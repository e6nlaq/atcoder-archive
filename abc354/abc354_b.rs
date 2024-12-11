use proconio::input;

fn main() {
    input! {
        // Input
        n:usize,
        mut pair:[(String,usize);n]
    };

    pair.sort_by(|a, b| a.0.cmp(&b.0));

    let mut sum = 0usize;
    for i in 0..n {
        sum += pair[i].1;
    }

    println!("{}", pair[sum % n].0);
}
