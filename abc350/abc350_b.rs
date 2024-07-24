use proconio::input;

fn main() {
    input! {
        // Input
        n:usize,
        q:usize,
        t:[usize;q]
    };

    let mut ans = n;
    let mut dat = [true; 1000];
    for i in 0..q {
        dat[t[i] - 1] ^= true;
        if dat[t[i] - 1] {
            ans += 1;
        } else {
            ans -= 1;
        }
    }

    println!("{}", ans);
}
