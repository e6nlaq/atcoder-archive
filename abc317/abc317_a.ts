/*------------------------------------------------------------



	   Welcome to my program!

	  ∧＿∧        AtCoder / Codeforces
	 ( 　･ω･)
	＿(__つ/￣￣￣ /  MIT License
	  ＼/　　　　 /   TypeScript 5.2.2 + Node.js v18.17.1
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

let X: number;
let P: Array<number>;

function inputs(inp: Array<Array<string>>): void {
	let tmp = inp[0].map(Number);
	N = tmp[0], H = tmp[1], X = tmp[2];
	P = inp[1].map(Number);
}

function main(): void {
	for (let i = 0; i < N; i++) {
		if (H + P[i] >= X) {
			console.log(i + 1);
			break;
		}
	}
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): Array<string> => {
	return line.split(" ");
}));

main();

// #endregion
