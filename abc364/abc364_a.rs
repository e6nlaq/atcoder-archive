use proconio::input;

fn main() {
    input! {
        // Input
        n:usize,
        s:[String;n]
    };

    let mut ans = "Yes";
    if n > 2 {
        for i in 0..n - 2 {
            if s[i] == "sweet" && s[i + 1] == "sweet" {
                ans = "No";
                break;
            }
        }
    }

    println!("{}", ans);
}
