use std::collections::HashMap;

use proconio::input;

fn main() {
    input! {
        // Input
        q:usize
    };

    let mut dat: HashMap<usize, usize> = HashMap::new();
    let mut cnt = 0;
    for _query_cnt in 0..q {
        input! {
            query:usize
        };

        if query == 1 {
            input! {
                x:usize
            }

            if !dat.contains_key(&x) {
                dat.insert(x, 0);
            }

            *dat.get_mut(&x).unwrap() += 1;
            if dat.get(&x).unwrap() == &1 {
                cnt += 1;
            }
        } else if query == 2 {
            input! {
                x:usize
            }

            *dat.get_mut(&x).unwrap() -= 1;

            if dat.get(&x).unwrap() == &0 {
                cnt -= 1;
            }
        } else {
            println!("{}", cnt);
        }
    }
}
