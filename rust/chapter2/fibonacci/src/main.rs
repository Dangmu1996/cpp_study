use std::io;

fn main() {
    println!("n 번째 수를 입력해 주세요.");

    let mut n = String::new();
    io::stdin().read_line(&mut n);
    let n : i32= n.trim().parse().unwrap(); // trim 앞뒤 공백 제거 후 i:32로 변환
    println!("입력 수: {}", n);

    let ret = fibo(n);
    println!("결과: {}", ret);
}

fn fibo(n:i32)->i32{
    let mut next = 0;
    let mut t1 = 1;
    let mut t2 = 1;
    let mut counter = 2;

    print!("1, 1, ");
    while counter < n{
        next = t1 +t2;
        t1 = t2;
        t2 = next;
        print!("{}, ", next);

        counter += 1;
    }
    println!("");
    next
}

// #[test] 지시자를 함수 위에 추가하면 test에만 작동하는 함수를 만들 수 있음 
// $ cargo test 이렇게 하면 됨
#[test]
fn fibo_test(){
    assert_eq!(fibo(6), 8); // 6번째 수열은 8이여야함
    assert_eq!(fibo(7), 13); // 7번째 수열은 13이여야함
}