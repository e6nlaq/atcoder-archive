use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        s:String
    };

    let mut str = s;

    str.retain(|c| c != '.');

    println!("{}", str);
}
