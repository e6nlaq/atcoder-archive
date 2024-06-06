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
const X: number[][] = [];

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function inputs(inp: string[][]): void {
	// Input
	[N, M] = inp[0].map(Number);
	A = inp[1].map(Number);

	for (let i = 0; i < N; ++i) {
		X.push(inp[2 + i].map(Number));
	}
}

function main(): void {
	// Main function
	const gets = new Array<number>(M).fill(0);

	for (let i = 0; i < N; ++i) {
		for (let j = 0; j < M; ++j) {
			gets[j] += X[i][j];
		}
	}

	console.error(gets, A);

	const ans = gets.every((value, index) => value >= A[index]);
	console.log(ans ? 'Yes' : 'No');
}

// #region 入力

inputs(
	readFileSync('/dev/stdin', 'utf-8')
		.split('\n')
		.map(line => line.split(' ')),
);

main();

// #endregion
