use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        n:usize,
        a:u32,
        b:u32,
        c:[u32;n]
    };

    let ans = a + b;
    for i in 0..n {
        if c[i] == ans {
            println!("{}", i + 1);
            break;
        }
    }
}
