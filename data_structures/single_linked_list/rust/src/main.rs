mod node;

fn main() {
    let s = String::from("hello");
    println!("{}", &s[..]);
    node::test();
}
