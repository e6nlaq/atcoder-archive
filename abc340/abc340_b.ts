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

/* eslint-enable */

const query: Array<number[]> = [];

// Functions

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function inputs(inp: string[][]): void {
	// Input
	Q = Number(inp[0][0]);

	for (let i = 1; i <= Q; ++i) {
		query.push(inp[i].map(Number));
	}
}

function main(): void {
	// Main function
	const A = [];

	for (let i = 0; i < Q; ++i) {
		if (query[i][0] === 1) {
			A.push(query[i][1]);
		} else {
			console.log(A[A.length - query[i][1]]);
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
