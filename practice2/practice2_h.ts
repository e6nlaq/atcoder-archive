import { readFileSync } from 'node:fs';

export class CSR<E> {
	readonly start: Int32Array;
	readonly elist: E[];

	constructor(n: number, edges: [number, E][]) {
		this.start = new Int32Array(n + 1);
		this.elist = new Array<E>(edges.length);

		for (const [v, _] of edges) {
			this.start[v + 1]++;
		}

		for (let i = 1; i <= n; i++) {
			this.start[i] += this.start[i - 1];
		}

		const counter = this.start.slice();
		for (const [v, e] of edges) {
			this.elist[counter[v]++] = e;
		}
	}
}

type Edge = { to: number };

export class SCCGraph {
	private _n: number;
	private edges: [number, Edge][];

	constructor(n: number) {
		this._n = n;
		this.edges = [];
	}

	num_vertices(): number {
		return this._n;
	}

	add_edge(from: number, to: number): void {
		this.edges.push([from, { to }]);
	}

	// Returns [number of SCCs, SCC ids]
	scc_ids(): [number, Int32Array] {
		const g = new CSR<Edge>(this._n, this.edges);
		let now_ord = 0;
		let group_num = 0;
		const visited: number[] = [];
		const low = new Int32Array(this._n);
		const ord = new Int32Array(this._n).fill(-1);
		const ids = new Int32Array(this._n);

		const dfs = (v: number): void => {
			low[v] = ord[v] = now_ord++;
			visited.push(v);

			for (let i = g.start[v]; i < g.start[v + 1]; i++) {
				const to = g.elist[i].to;
				if (ord[to] === -1) {
					dfs(to);
					low[v] = Math.min(low[v], low[to]);
				} else {
					low[v] = Math.min(low[v], ord[to]);
				}
			}

			if (low[v] === ord[v]) {
				while (true) {
					const u = visited[visited.length - 1];
					visited.pop();
					ord[u] = this._n;
					ids[u] = group_num;
					if (u === v) break;
				}
				group_num++;
			}
		};

		for (let i = 0; i < this._n; i++) {
			if (ord[i] === -1) dfs(i);
		}

		for (let i = 0; i < this._n; i++) {
			ids[i] = group_num - 1 - ids[i];
		}

		return [group_num, ids];
	}

	scc(): number[][] {
		const [group_num, ids] = this.scc_ids();
		const counts = new Int32Array(group_num);

		for (const id of ids) {
			counts[id]++;
		}

		const groups = new Array<number[]>(group_num).fill([]).map((): number[] => []);

		for (let i = 0; i < this._n; i++) {
			groups[ids[i]].push(i);
		}

		return groups;
	}
}

export class TwoSat {
	private _n: number;
	private _answer: boolean[];
	private scc: SCCGraph;

	constructor(n = 0) {
		this._n = n;
		this._answer = new Array<boolean>(n);
		this.scc = new SCCGraph(2 * n);
	}

	add_clause(i: number, f: boolean, j: number, g: boolean): void {
		if (!(0 <= i && i < this._n && 0 <= j && j < this._n)) {
			throw new RangeError('Out of range');
		}

		this.scc.add_edge(2 * i + (f ? 0 : 1), 2 * j + (g ? 1 : 0));
		this.scc.add_edge(2 * j + (g ? 0 : 1), 2 * i + (f ? 1 : 0));
	}

	satisfiable(): boolean {
		const id = this.scc.scc_ids()[1];
		for (let i = 0; i < this._n; i++) {
			if (id[2 * i] === id[2 * i + 1]) return false;
			this._answer[i] = id[2 * i] < id[2 * i + 1];
		}
		return true;
	}

	answer(): boolean[] {
		return this._answer;
	}
}

const abs = Math.abs;

function main(inp: string[][]): void {
	const [N, D] = inp[0].map(Number);
	const sat = new TwoSat(N);
	const X: number[] = [];
	const Y: number[] = [];

	for (let i = 0; i < N; i++) {
		const [x, y] = inp[1 + i].map(Number);
		X.push(x);
		Y.push(y);
	}

	for (let i = 0; i < N - 1; i++) {
		for (let j = i + 1; j < N; j++) {
			if (abs(X[i] - X[j]) < D) {
				sat.add_clause(i, false, j, false);
			}

			if (abs(X[i] - Y[j]) < D) {
				sat.add_clause(i, false, j, true);
			}

			if (abs(Y[i] - Y[j]) < D) {
				sat.add_clause(i, true, j, true);
			}

			if (abs(Y[i] - X[j]) < D) {
				sat.add_clause(i, true, j, false);
			}
		}
	}

	if (!sat.satisfiable()) {
		console.log('No');
	} else {
		console.log('Yes');
		const ans = sat.answer();
		for (let i = 0; i < N; i++) {
			if (ans[i]) {
				console.log(X[i]);
			} else {
				console.log(Y[i]);
			}
		}
	}
}

main(
	readFileSync('/dev/stdin', 'utf-8')
		.split('\n')
		.map(line => line.split(' ')),
);
