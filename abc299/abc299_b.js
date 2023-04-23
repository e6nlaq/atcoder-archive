
function main(input) {
	const args = input.split('\n');
	const num = args[0].split(' ');

	const N = parseInt(num[0]), C = args[1].split(' '), R = args[2].split(' ');
	let T = num[1];

	if (C.indexOf(T) == -1) T = C[0];

	let ans = [-1, "-1"];
	for (let i = 0; i < N; i++) {
		if (C[i] == T && R[i] > ans[1]) {
			ans[0] = i + 1;
			ans[1] = R[i];
		}
	}

	console.log(ans[0]);

}


main(require("fs").readFileSync("/dev/stdin", "utf8"));
