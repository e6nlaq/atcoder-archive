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

let N: bigint, M: number;
let H: number, W: number;
let Q: number;
let S: string = '';

/* eslint-enable */

let K: bigint;
let A: bigint[];

// Functions

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function inputs(inp: string[][]): void {
	// Input

	N = BigInt(inp[0][0]);
	K = BigInt(inp[0][1]);
	A = inp[1].map(BigInt);
}

function main(): void {
	// Main function

	let ans = (K * (K + 1n)) / 2n;
	const dat = new Set<bigint>();
	for (let i = 0; i < N; ++i) {
		if (A[i] <= K && !dat.has(A[i])) {
			dat.add(A[i]);
			ans -= A[i];
		}
	}

	console.log(ans.toString());
}

// #region 入力

inputs(
	readFileSync('/dev/stdin', 'utf-8')
		.split('\n')
		.map(line => line.split(' ')),
);

main();

// #endregion
