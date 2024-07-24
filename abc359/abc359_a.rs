use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        n:usize,
        s:[String;n]
    };

    let mut ans = 0;
    for c in s {
        if c == "Takahashi" {
            ans += 1;
        }
    }

    println!("{}", ans);
}
