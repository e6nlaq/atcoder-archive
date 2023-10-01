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

let R: number, C: number;

const dx: Array<number> = [0, 0, 1, -1];
const dy: Array<number> = [1, -1, 0, 0];

function inputs(inp: Array<Array<string>>): void {
	H = Number(inp[0][0]), W = Number(inp[0][1]);
	R = Number(inp[1][0]), C = Number(inp[1][1]);
}

function main(): void {
	let r: number = R, c: number = C;
	let ans: number = 0;
	for (let i: number = 0; i < 4; ++i) {
		r = R, c = C;
		r += dx[i], c += dy[i];

		if (r >= 1 && r <= H && c >= 1 && c <= W) ans++;
	}

	console.log(ans);
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): Array<string> => {
	return line.split(" ");
}));

main();

// #endregion
