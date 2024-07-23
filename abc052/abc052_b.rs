use proconio::{input, marker::Chars};
use std::cmp::max;

fn main() {
    input! {
        // Input
        _n:usize,
        s:Chars
    };

    let mut ans = 0;
    let mut x = 0;
    for c in s {
        if c == 'I' {
            x += 1;
        } else {
            x -= 1;
        }

        ans = max(ans, x);
    }

    println!("{}", ans);
}
