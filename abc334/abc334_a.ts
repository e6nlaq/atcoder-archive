/*------------------------------------------------------------


	   Welcome to my program!
	   DON'T HACK PLEASE!!!!!!!!

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

let B: number, G: number;

function inputs(inp: string[][]): void {
	B = Number(inp[0][0]);
	G = Number(inp[0][1]);
}

function main(): void {
	console.log((B > G ? "Bat" : "Glove"));
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): string[] => {
	return line.split(" ");
}));

main();

// #endregion
