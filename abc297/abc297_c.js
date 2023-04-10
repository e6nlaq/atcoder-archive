
function main(input) {
	const args = input.split('\n');

	const num = args[0].split(' ');
	const H = parseInt(num[0]), W = parseInt(num[1]);
	let S = [];

	for (let i = 0; i < H; i++) {
		S.push(args[i + 1].split(''));
	}

	for (let i = 0; i < H; i++) {
		for (let j = 0; j < W - 1; j++) {
			if (S[i][j] == 'T' && S[i][j + 1] == 'T') {
				S[i][j] = 'P';
				S[i][j + 1] = 'C';
			}
		}
	}

	S.forEach(function (s) {
		console.log(s.join(''));
	});
}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
