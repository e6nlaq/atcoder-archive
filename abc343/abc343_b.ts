/*------------------------------------------------------------


	   Welcome to my program!
	   DON'T HACK PLEASE!!!!!!!!

	  ∧＿∧        AtCoder / Codeforces / yukicoder
	 ( 　･ω･)
	＿(__つ/￣￣￣ /  
	  ＼/　　　　 /   TypeScript 5.2.2 + Node.js v20.11.1
		￣￣￣￣￣
		   Let's write Code!


------------------------------------------------------------*/

//#region Lib

import { readFileSync } from 'fs';
import * as mathjs from 'mathjs';
import * as std from 'tstl';


const dx: number[] = [0, 0, 1, -1];
const dy: number[] = [1, -1, 0, 0];

// #endregion

let N: number, M: number;
let H: number, W: number;
let S: string = "";

let A: boolean[][]=[];

// Functions

function inputs(inp: string[][]): void {
	N = Number(inp[0][0]);
	for (let i = 1; i <= N; ++i){
		A.push(inp[i].map(val => val === "1"));
	}
}

function main(): void {
	let ans: number[][]=[];
	for (let i = 0; i < N; ++i){
		ans.push([]);
		for (let j = 0; j < N; ++j){
			if (A[i][j]) {
				ans[i].push(j + 1);
			}
		}

		console.log(ans[i].join(" "));
	}
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): string[] => {
	return line.split(" ");
}));

main();

// #endregion
