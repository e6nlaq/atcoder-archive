
function main(input) {
	const args = input.split('\n');

	const S = args[0];

	let pos1 = S.indexOf('B');
	let pos2 = S.lastIndexOf('B');

	pos1 %= 2;
	pos2 %= 2;

	if (pos1 == pos2) {
		console.log("No");
		return;
	}

	let check = false;
	for (let i = 0; i < S.length; i++) {
		if (S[i] == 'R') {
			check = !check;
		}

		if (S[i] == 'K' && !check) {
			console.log("No");
			return;
		}
	}

	console.log("Yes");


}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
