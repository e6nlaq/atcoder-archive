use proconio::input;

fn main() {
    input! {
        // Input
        n:usize,
        a:[usize;n],
        w:[i32;n]
    };

    let mut dat: Vec<Vec<i32>> = vec![vec![]; 100000];
    let mut ans = 0;

    for i in 0..n {
        dat.get_mut(a[i] - 1).unwrap().push(w[i]);
    }

    for i in 0..n {
        if dat[i].len() != 0 {
            ans += &dat[i].iter().sum();
            ans -= dat[i].iter().max().unwrap();
        }
    }

    println!("{}", ans);
}
