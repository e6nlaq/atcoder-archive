use proconio::input;

fn main() {
    input! {
        // Input
        s:String,
        t:String
    };

    let mut ans = "No";

    if s == "AtCoder" && t == "Land" {
        ans = "Yes";
    }

    println!("{}", ans);
}
