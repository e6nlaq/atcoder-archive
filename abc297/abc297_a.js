
function main(input) {
	const args = input.split('\n');

	const num = args[0].split(' ');
	const N = parseInt(num[0]), D = parseInt(num[1]);
	const T = args[1].split(' ');

	for (let i = 0; i < N - 1; i++) {
		if (parseInt(T[i + 1]) - parseInt(T[i]) <= D) {
			console.log(T[i + 1]);
			return;
		}
	}

	console.log(-1);

}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
