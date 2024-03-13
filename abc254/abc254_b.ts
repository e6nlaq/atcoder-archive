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

// Functions

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function inputs(inp: string[][]): void {
	N = Number(inp[0][0]);
}

function main(): void {
	const A = new Array<number[]>(N);

	for (let i = 0; i < N; ++i) {
		A[i] = new Array<number>(i + 1);
		for (let j = 0; j <= i; ++j) {
			if (j === 0 || j === i) {
				A[i][j] = 1;
			} else {
				A[i][j] = A[i - 1][j - 1] + A[i - 1][j];
			}
		}

		console.log(A[i].join(' '));
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
