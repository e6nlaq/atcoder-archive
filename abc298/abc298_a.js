
function main(input) {
	const args = input.split('\n');

	const S = args[1];

	if (S.indexOf('o') >= 0 && S.indexOf('x') < 0) {
		console.log("Yes");
	} else {
		console.log("No");
	}

}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
