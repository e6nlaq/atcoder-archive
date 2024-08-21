use proconio::input;

fn main() {
    input! {
        // Input
        a:usize,
        b:usize,
        c:usize,
    };

    if b < c {
        println!("{}", if b < a && a < c { "No" } else { "Yes" });
    } else {
        println!("{}", if b < a || a < c { "No" } else { "Yes" });
    }
}
