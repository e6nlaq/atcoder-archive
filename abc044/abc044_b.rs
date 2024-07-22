use std::collections::HashMap;

use proconio::{input, marker::Chars};

fn main() {
    input! {
        // Input
        w:Chars
    };

    let mut dat: HashMap<char, u32> = HashMap::new();

    for c in w {
        *dat.entry(c).or_insert(0) += 1;
    }

    let mut ans = "Yes";
    for (_c, v) in dat {
        if v % 2 == 1 {
            ans = "No";
            break;
        }
    }

    println!("{}", ans);
}
