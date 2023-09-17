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
import { join } from 'node:path/win32';
import * as std from 'tstl';

// #endregion

let N: number, M: number;
let H: number, W: number;
let S: string = "";
const space_split: boolean = true;

// Functions

let C: Array<string>;

function inputs(inp: Array<Array<string>>): void {
	console.error(inp);
	H = Number(inp[0][0]); W = Number(inp[0][1]);
	C = Array(H);
	for (let i = 0; i < H; i++) {
		C[i] = inp[i + 1][0];
	}
}

function main(): void {
	let X: Array<number> = Array(W).fill(0);

	for (let j = 0; j < W; j++) {
		for (let i = 0; i < H; i++) {
			if (C[i][j] === '#') X[j]++;
		}
	}

	console.log(X.join(' '));
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): Array<string> => {
	return line.split(" ");
}));

main();

// #endregion
