/*------------------------------------------------------------



	   Welcome to my program!

	  ∧＿∧        AtCoder / Codeforces
	 ( 　･ω･)
	＿(__つ/￣￣￣ /  MIT License
	  ＼/　　　　 /   TypeScript 5.2.2 + Node.js v18.18.0
		￣￣￣￣￣
		   Let's write Code!


------------------------------------------------------------*/



//#region Lib

import { readFileSync } from 'fs';
import * as mathjs from 'mathjs';
import * as std from 'tstl';


const dx: Array<number> = [0, 0, 1, -1];
const dy: Array<number> = [1, -1, 0, 0];

// #endregion

let N: number, M: number;
let H: number, W: number;
let S: string = "";

// Functions

const list: Set<string> = new Set<string>(["ACE", "BDF", "CEG", "DFA", "EGB", "FAC", "GBD"]);

function inputs(inp: string[][]): void {
	S = inp[0][0];
}

function main(): void {
	console.log(list.has(S) ? "Yes" : "No");
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): string[] => {
	return line.split(" ");
}));

main();

// #endregion
