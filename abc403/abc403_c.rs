use std::collections::HashSet;

use proconio::input;

fn main() {
    input! {
        // Input
        n:usize,
        _:usize,
        q:usize
    };

    let mut dat: Vec<HashSet<usize>> = Vec::new();
    dat.resize(n, HashSet::new());

    let mut ok = vec![false; n];
    for _ in 0..q {
        input! {
            query:usize
        }

        if query == 1 {
            input! {
                x:usize,
                y:usize
            };

            dat[x - 1].insert(y);
        } else if query == 2 {
            input! {
                x:usize
            };

            ok[x - 1] = true;
        } else {
            input! {
                mut x:usize,
                y:usize
            }

            x -= 1;
            if ok[x] {
                println!("Yes");
            } else {
                println!("{}", if dat[x].contains(&y) { "Yes" } else { "No" });
            }
        }
    }
}
