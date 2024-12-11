use proconio::input;

fn main() {
    input! {
        // Input
        h:usize
    };

    let mut now = 0usize;
    for i in 0..64 {
        now += 1 << i;
        if now > h {
            println!("{}", i + 1);
            break;
        }
    }
}
