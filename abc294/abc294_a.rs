use proconio::input;

fn main() {
    input! {
        // Input
        n:usize,
        a:[u32;n]
    };

    for x in a.iter().filter(|&x| x % 2 == 0) {
        print!("{} ", x);
    }
}
