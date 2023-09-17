/*------------------------------------------------------------



	   Welcome to my program!

	  ∧＿∧        AtCoder / Codeforces
	 ( 　･ω･)
	＿(__つ/￣￣￣ /  MIT License
	  ＼/　　　　 /   TypeScript  + Node.js v18.17.1
		￣￣￣￣￣
		   Let's write Code!


------------------------------------------------------------*/



//#region Import

import { readFileSync } from 'fs';
import * as mathjs from 'mathjs';
import * as std from 'tstl';

// #endregion

let N: number, M: number;
let H: number, W: number;
let S: string = "";
const space_split: boolean = true;

// Functions

let A: Array<number>;

function inputs(inp: Array<Array<string>>): void {
	N = inp[0].map(Number)[0];
	A = inp[1].map(Number);
}

function main(): void {
	A = A.sort((a, b) => { return a - b });
	console.error(A);
	for (let i = 0; i < N; ++i) {
		if (A[i] !== A[0] + i) {
			console.log(A[0] + i);
			return;
		}
	}
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): Array<string> => {
	return line.split(" ");
}));

main();

// #endregion
