use proconio::input;

fn main() {
    input! {
    // Input
    _n:i32,
    s:String
    };

    for c in s.chars() {
        print!("{}{}", c, c);
    }
}
