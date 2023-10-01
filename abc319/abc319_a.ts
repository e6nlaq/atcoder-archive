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

let dat = {
	"tourist": 3858,
	"ksun48": 3679,
	"Benq": 3658,
	"Um_nik": 3648,
	"apiad": 3638,
	"Stonefeang": 3630,
	"ecnerwala": 3613,
	"mnbvmar": 3555,
	"newbiedmy": 3516,
	"semiexp": 3481
}

function inputs(inp: string[][]): void {
	S = inp[0][0];
}

function main(): void {
	console.log(dat[S]);
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): string[] => {
	return line.split(" ");
}));

main();

// #endregion
