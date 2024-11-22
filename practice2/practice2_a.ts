/*------------------------------------------------------------


	   Welcome to my program!
	   DON'T HACK PLEASE!!!!!!!!

	  ∧＿∧        AtCoder / Codeforces / yukicoder
	 ( 　･ω･)
	＿(__つ/￣￣￣ /  
	  ＼/　　　　 /   TypeScript 5.1.6 + Node.js v18.16.1
		￣￣￣￣￣
		   Let's write Code!


------------------------------------------------------------*/

//#region Lib

/* eslint-disable */

import { readFileSync } from 'fs';
import * as mathjs from 'mathjs';
import * as std from 'tstl';

const dx: number[] = [0, 0, 1, -1];
const dy: number[] = [1, -1, 0, 0];

// #endregion

let N: number, M: number;
let H: number, W: number;
let Q: number;
let S: string = '';

/* eslint-enable */

class DSU {
	private _n: number;
	private parentOrSize: number[];

	constructor(n = 0) {
		this._n = n;
		this.parentOrSize = new Array(n).fill(-1);
	}

	merge(a: number, b: number): number {
		this.assertInRange(a);
		this.assertInRange(b);
		let x = this.leader(a);
		let y = this.leader(b);
		if (x === y) return x;
		if (-this.parentOrSize[x] < -this.parentOrSize[y]) {
			[x, y] = [y, x];
		}
		this.parentOrSize[x] += this.parentOrSize[y];
		this.parentOrSize[y] = x;
		return x;
	}

	same(a: number, b: number): boolean {
		this.assertInRange(a);
		this.assertInRange(b);
		return this.leader(a) === this.leader(b);
	}

	leader(a: number): number {
		this.assertInRange(a);
		if (this.parentOrSize[a] < 0) return a;

		this.parentOrSize[a] = this.leader(this.parentOrSize[a]);
		return this.parentOrSize[a];
	}

	size(a: number): number {
		this.assertInRange(a);
		return -this.parentOrSize[this.leader(a)];
	}

	groups(): number[][] {
		const leaderBuf = new Array(this._n).fill(0).map((_, i) => this.leader(i));
		const groupSize = new Array(this._n).fill(0);

		for (const leader of leaderBuf) {
			groupSize[leader]++;
		}

		const result: number[][] = Array.from({ length: this._n }, () => []);
		for (let i = 0; i < this._n; i++) {
			result[leaderBuf[i]].push(i);
		}
		return result.filter((group) => group.length > 0);
	}

	private assertInRange(a: number): void {
		if (a < 0 || a >= this._n) {
			throw new RangeError(`Index ${a} is out of range`);
		}
	}
}


// Functions

let t:number[],u:number[],v:number[];

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function inputs(inp: string[][]): void {
	// Input
	[N, Q] = inp[0].map(Number);
	t = new Array(Q);
	u = new Array(Q);
	v = new Array(Q);
	for (let i = 0; i < Q; ++i){
		[t[i],u[i],v[i]]=inp[i+1].map(Number);
	}
}

function main(): void {
	// Main function
	const uf = new DSU(N);
	for (let i = 0; i < Q; ++i){
		if (t[i] == 0) {
			uf.merge(u[i], v[i]);
		} else {
			console.log(Number(uf.same(u[i], v[i])));
		}
	}

}

// #region 入力

inputs(
	readFileSync('/dev/stdin', 'utf-8')
		.split('\n')
		.map(line => line.split(' ')),
);

main();

// #endregion
