
function main(input) {
	const args = input.split('\n');

	for (let i = 0; i < 8; i++) {
		const S = args[i];

		for (let j = 0; j < 8; j++) {
			if (S[j] == '*') {
				console.log(String.fromCharCode('a'.charCodeAt(0) + j) + String(8 - i));
				return;
			}
		}
	}

}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
