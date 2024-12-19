import { readFileSync } from 'node:fs';
import { ok } from 'node:assert';

export function safe_mod(x: bigint, m: bigint): bigint {
	x %= m;
	if (x < 0n) x += m;
	return x;
}
export function floor_sum_unsigned(n: bigint, m: bigint, a: bigint, b: bigint): bigint {
	let ans = 0n;
	while (true) {
		if (a >= m) {
			ans += ((n * (n - 1n)) / 2n) * (a / m);
			a %= m;
		}
		if (b >= m) {
			ans += n * (b / m);
			b %= m;
		}

		const y_max = a * n + b;
		if (y_max < m) break;

		n = y_max / m;
		b = y_max % m;

		[m, a] = [a, m];
	}
	return ans;
}

export type ll = bigint | number;
export function floor_sum(n: ll, m: ll, a: ll, b: ll): bigint {
	n = BigInt(n);
	m = BigInt(m);
	a = BigInt(a);
	b = BigInt(b);

	ok(0n <= n && n < 1n << 32n);
	ok(0n <= m && m < 1n << 32n);
	let ans = 0n;
	if (a < 0n) {
		const a2 = safe_mod(a, m);
		ans -= ((n * (n - 1n)) / 2n) * ((a2 - a) / m);
		a = a2;
	}
	if (b < 0n) {
		const b2 = safe_mod(b, m);
		ans -= n * ((b2 - b) / m);
		b = b2;
	}

	return ans + floor_sum_unsigned(n, m, a, b);
}

function main(inp: string[][]): void {
	const T = Number(inp[0][0]);
	for (let i = 1; i <= T; i++) {
		const [N, M, A, B] = inp[i].map(Number);
		console.log(floor_sum(N, M, A, B).toString());
	}
}

main(
	readFileSync('/dev/stdin', 'utf-8')
		.split('\n')
		.map(line => line.split(' ')),
);
