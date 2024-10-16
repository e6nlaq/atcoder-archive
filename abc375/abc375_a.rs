use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        n:usize,
        s:Chars
    };

    let mut ans = 0;
    if n >= 3 {
        for i in 0..(n - 2) {
            if s[i] == '#' && s[i + 1] == '.' && s[i + 2] == '#' {
                ans += 1;
            }
        }
    }

    println!("{}", ans);
}
