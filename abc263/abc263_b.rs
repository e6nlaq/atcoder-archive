use std::collections::VecDeque;

use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        n:usize,
        p:[usize;n-1]
    };
    let mut dp = vec![-1; n + 1];
    dp[1] = 0;

    let mut q: VecDeque<usize> = VecDeque::new();
    q.push_back(1);

    while !q.is_empty() {
        let pos = q.front().unwrap() + 0;
        q.pop_front();
        for i in 0..(n - 1) {
            if p[i] == pos {
                dp[i + 2] = dp[pos] + 1;
                q.push_back(i + 2);
            }
        }
    }
    eprintln!("{:?}", dp);
    println!("{}", dp[n]);
}
