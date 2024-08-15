use proconio::input;

fn main() {
    input! {
        // Input
        n:usize,
        t:usize,
        a:usize
    };

    let hant = (n + 1) / 2;
    let ans = if t >= hant || a >= hant { "Yes" } else { "No" };

    println!("{}", ans);
}
