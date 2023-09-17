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

let A: number, B: number;

function inputs(inp: Array<Array<string>>) {
	let tmp = inp[0].map(Number);
	A = tmp[0], B = tmp[1];
}

function main() {
	console.log((A ** B) + (B ** A));
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): Array<string> => {
	return line.split(" ");
}));

main();

// #endregion
