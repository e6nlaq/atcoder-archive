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
let Q: number;

let P: number[];

let A: number[]=[], B: number[]=[];

// Functions

function inputs(inp: string[][]): void {
	N = Number(inp[0][0]);
	P = inp[1].map(Number);
	Q = Number(inp[2][0]);
	for (let i = 3; i <= 3 + Q; ++i){
		A.push(Number(inp[i][0]));
		B.push(Number(inp[i][1]));
	}
}

function main(): void {
	const pos = new Array<number>(N+1);
	for (let i = 0; i < N; ++i){
		pos[P[i]] = i;
	}

	for (let i = 0; i < Q; ++i){
		console.log(pos[A[i]] < pos[B[i]] ? A[i] : B[i]);
	}
}

// #region 入力

inputs(readFileSync("/dev/stdin", "utf-8").split("\n").map((line: string): string[] => {
	return line.split(" ");
}));

main();

// #endregion
