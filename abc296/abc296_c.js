
function main(input) {
	const args = input.split('\n');

	const X = parseInt(args[0].split(' ')[1]);
	const A = new Set(args[1].split(' '));

	let ok = false;

	A.forEach(function (B) {
		if (A.has(String(parseInt(B) + X))) {
			ok = true;
		}
	});

	console.log(ok ? "Yes" : "No");

}

main(require("fs").readFileSync("/dev/stdin", "utf8"));
