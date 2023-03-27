
function main(input) {
	const args = input.split('\n');

	const N = parseInt(args[0]);
	const A = args[1].split(' ');

	let ans = 0;
	let dat = {};

	for (let i = 0; i < N; i++) {
		if (A[i] in dat) {
			dat[A[i]]++;
		} else {
			dat[A[i]] = 1;
		}

		if (dat[A[i]] == 2) {
			ans++;
			dat[A[i]] = 0;
		}
	}

	console.log(ans);

}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
