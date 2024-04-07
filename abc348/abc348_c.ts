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

// Functions

let A: number[], C: number[];

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function inputs(inp: string[][]): void {
	// Input
	N = Number(inp[0][0]);
	A = new Array(N);
	C = new Array(N);
	for (let i = 0; i < N; ++i) {
		[A[i], C[i]] = inp[i + 1].map(Number);
	}
}

function main(): void {
	// Main function
	const dat = new Map<number, number>();
	for (let i = 0; i < N; ++i) {
		if (dat.has(C[i])) {
			dat.set(C[i], Math.min(dat.get(C[i])!, A[i]));
		} else {
			dat.set(C[i], A[i]);
		}
	}

	let ans = 0;
	const key = dat.values();
	for (const val of key) {
		ans = Math.max(ans, val);
	}

	console.log(ans);
}

// #region 入力

inputs(
	readFileSync('/dev/stdin', 'utf-8')
		.split('\n')
		.map(line => line.split(' ')),
);

main();

// #endregion
