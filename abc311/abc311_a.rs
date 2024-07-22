use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        n:usize,
        s:Chars
    };

    let mut a = false;
    let mut b = false;
    let mut c = false;

    for i in 0..n {
        if s[i] == 'A' {
            a = true;
        } else if s[i] == 'B' {
            b = true;
        } else if s[i] == 'C' {
            c = true;
        }

        if a && b && c {
            println!("{}", i + 1);
            break;
        }
    }
}
