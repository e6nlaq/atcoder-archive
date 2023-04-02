
function main(input) {
	const args = input.split('\n');

	const N = parseInt(args[0]);
	const S = args[1];

	for (let i = 0; i < N - 1; i++) {
		if (S[i] == S[i + 1]) {
			console.log("No");
			return;
		}
	}

	console.log("Yes");

}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
