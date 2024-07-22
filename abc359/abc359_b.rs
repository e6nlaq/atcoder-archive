use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        n:usize,
        a:[u32;2*n]
    };

    let mut ans = 0;
    for i in 0..(2 * n - 2) {
        if a[i] == a[i + 2] {
            ans += 1;
        }
    }

    println!("{}", ans);
}
