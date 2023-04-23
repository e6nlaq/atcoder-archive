
function rot90(arr) {
	let x = arr[0].length;
	let y = arr.length;

	let ret = [];
	for (let i = 0; i < x; i++) {
		ret[i] = [];
		for (let j = 0; j < y; j++) {
			ret[i][j] = arr[j][i];
		}
	}

	for (let i = 0; i < y; i++) {
		ret[i].reverse();
	}

	return ret;
}

function main(input) {
	const args = input.split('\n');

	const N = parseInt(args[0]);
	let A = [], B = [];

	for (let i = 0; i < N; i++) {
		A.push(args[i + 1].split(' '));
	}

	for (let i = 0; i < N; i++) {
		B.push(args[i + N + 1].split(' '));
	}

	for (let _ = 0; _ < 4; _++) {
		A = rot90(A);
		let ok = true;

		for (let i = 0; i < N; i++) {
			for (let j = 0; j < N; j++) {
				if (A[i][j] == "1" && B[i][j] == "0") {
					ok = false;
				}
			}
		}

		if (ok) {
			console.log("Yes");
			return;
		}
	}

	console.log("No");
}

main(require("fs").readFileSync("/dev/stdin", "utf8"));