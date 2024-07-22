use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        s:Chars,
        t:Chars
    };

    let n = s.len();

    let mut ans = n + 1;
    for i in 0..n {
        if s[i] != t[i] {
            ans = i + 1;
            break;
        }
    }

    println!("{}", ans);
}
