/*------------------------------------------------------------


	   Welcome to my program!
	   DON'T HACK PLEASE!!!!!!!!

	  ∧＿∧        AtCoder / Codeforces / yukicoder
	 ( 　･ω･)
	＿(__つ/￣￣￣ /  
	  ＼/　　　　 /   TypeScript 5.1.6 + Node.js v18.16.1
		￣￣￣￣￣
		   Let's write Code!


------------------------------------------------------------*/

//#region Lib

/* eslint-disable */

import { readFileSync } from 'fs';
import * as mathjs from 'mathjs';
import * as std from 'tstl';

const dx: number[] = [0, 0, 1, -1];
const dy: number[] = [1, -1, 0, 0];

// #endregion

let N: number, M: number;
let H: number, W: number;
let Q: number;
let S: string = '';

/* eslint-enable */

// Functions

// eslint-disable-next-line @typescript-eslint/no-unused-vars
function inputs(inp: string[][]): void {
	// Input
	S = inp[0][0];
}

function main(): void {
	// Main function
	const plus = S.split('+');
	let ans = 0;
	for (let i = 0; i < plus.length; ++i) {
		const kake = plus[i].split('*').map(Number);
		let flag = false;
		for (let j = 0; j < kake.length; ++j) {
			if (kake[j] === 0) {
				flag = true;
			}
		}

		if (!flag) ans++;
	}

	console.log(ans);
}

// #region 入力

inputs(
	readFileSync('/dev/stdin', 'utf-8')
		.split('\n')
		.map(line => line.split(' ')),
);

main();

// #endregion
