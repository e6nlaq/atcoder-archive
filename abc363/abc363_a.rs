use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        r:u32
    };

    println!("{}", 100 - (r % 100));
}
