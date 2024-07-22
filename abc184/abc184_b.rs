use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        _n:usize,
        x:i32,
        s:Chars
    };

    let mut ans = x;
    for c in s {
        if c == 'o' {
            ans += 1;
        } else {
            ans -= 1;
        }

        if ans < 0 {
            ans = 0;
        }
    }

    println!("{}", ans);
}
