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

let A: number[];

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function inputs(inp: string[][]): void {
	// Input
	N = Number(inp[0][0]);

	A = inp[1].map(Number);
}

function main(): void {
	// Main function
	let cnt = 0;
	for (let i = 0; i < N; ++i) {
		cnt += A[i];
		if (cnt < 0) cnt = 0;
	}

	console.log(cnt);
}

// #region 入力

inputs(
	readFileSync('/dev/stdin', 'utf-8')
		.split('\n')
		.map(line => line.split(' ')),
);

main();

// #endregion
