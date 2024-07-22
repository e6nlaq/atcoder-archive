use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        l:usize,
        r:usize
    };

    println!("{}", &"atcoder"[(l - 1)..r]);
}
