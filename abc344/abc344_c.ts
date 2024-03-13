/*------------------------------------------------------------


	   Welcome to my program!
	   DON'T HACK PLEASE!!!!!!!!

	  ∧＿∧        AtCoder / Codeforces / yukicoder
	 ( 　･ω･)
	＿(__つ/￣￣￣ /  
	  ＼/　　　　 /   TypeScript 5.2.2 + Node.js v20.11.1
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
let L: number;

let A: number[], B: number[], C: number[], X: number[];

/* eslint-enable */

// Functions

function inputs(inp: string[][]): void {
	N = Number(inp[0][0]);
	A = inp[1].map(Number);
	M = Number(inp[2][0]);
	B = inp[3].map(Number);
	L = Number(inp[4][0]);
	C = inp[5].map(Number);

	Q = Number(inp[6][0]);
	X = inp[7].map(Number);
}

function main(): void {
	const dat = new Set();
	for (let i = 0; i < N; ++i) {
		for (let j = 0; j < M; ++j) {
			for (let k = 0; k < L; ++k) {
				dat.add(A[i] + B[j] + C[k]);
			}
		}
	}

	for (let i = 0; i < Q; ++i) {
		console.log(dat.has(X[i]) ? 'Yes' : 'No');
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
