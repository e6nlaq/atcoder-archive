use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        s:Chars
    };

    println!("{}{}{}", s[0], s.len() - 2, s.last().unwrap());
}
