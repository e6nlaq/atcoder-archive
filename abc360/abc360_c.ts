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

const debug = console.error;

// #endregion

let N: number, M: number;
let Q: number;
let S: string = '';

let A: number[], W: number[];

/* eslint-enable */

// Functions

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function inputs(inp: string[][]): void {
	// Input
	N = Number(inp[0][0]);
	A = inp[1].map(Number);
	W = inp[2].map(Number);
}

function main(): void {
	// Main function
	const box = new Array<number[]>(N).fill([]).map(() => [] as number[]);
	for (let i = 0; i < N; ++i) {
		box[A[i] - 1].push(W[i]);
	}

	let ans = 0;
	for (let i = 0; i < N; ++i) {
		box[i].sort((a, b) => a - b);
		for (let j = 0; j < box[i].length - 1; ++j) {
			ans += box[i][j];
		}
	}

	debug(box);
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
