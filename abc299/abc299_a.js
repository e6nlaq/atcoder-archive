
function main(input) {
	const args = input.split('\n');

	const N = parseInt(args[0]);
	const S = args[1];

	let flag = false;
	for (let i = 0; i < N; i++) {
		if (S[i] == '|') flag = !flag;
		else if (S[i] == '*') {
			console.log(flag ? "in" : "out");
			return;
		}
	}
}


main(require("fs").readFileSync("/dev/stdin", "utf8"));
