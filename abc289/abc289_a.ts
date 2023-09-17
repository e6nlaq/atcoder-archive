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

let s: string;

function inputs(inp: Array<Array<string>>): void {
	s = inp[0][0];
}

function main(): void {
	let ans: string = "";
	for (let i = 0; i < s.length; i++) {
		if (s[i] === '0') ans += '1';
		else ans += '0';
	}

	console.log(ans);
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): Array<string> => {
	return line.split(" ");
}));

main();

// #endregion
