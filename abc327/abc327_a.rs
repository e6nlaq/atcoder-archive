use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        n:usize,
        s:Chars
    };

    let mut ans = "No";
    for i in 0..(n - 1) {
        if (s[i] == 'a' && s[i + 1] == 'b') || (s[i] == 'b' && s[i + 1] == 'a') {
            ans = "Yes";
        }
    }

    println!("{}", ans);
}
