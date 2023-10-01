/*------------------------------------------------------------



	   Welcome to my program!

	  ∧＿∧        AtCoder / Codeforces
	 ( 　･ω･)
	＿(__つ/￣￣￣ /  MIT License
	  ＼/　　　　 /   TypeScript 5.2.2 + Node.js v18.18.0
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

// Functions

let A: Array<Array<number>>;
let R: number, C: number;

function inputs(inp: Array<Array<string>>): void {
	R = Number(inp[0][0]), C = Number(inp[0][1]);
	A = [
		inp[1].map(Number),
		inp[2].map(Number)
	];
}

function main(): void {
	console.log(A[R - 1][C - 1]);
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): Array<string> => {
	return line.split(" ");
}));

main();

// #endregion
