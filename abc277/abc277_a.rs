use proconio::input;

fn main() {
    input! {
        // Input
        n:usize,
        x:u32,
        p:[u32;n]
    };

    println!("{}", p.iter().position(|&val| val == x).unwrap() + 1);
}
