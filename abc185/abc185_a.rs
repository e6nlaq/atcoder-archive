use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        a:[u32;4usize]
    };

    println!("{}", a.iter().min().unwrap());
}
