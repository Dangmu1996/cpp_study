fn main() {
    let var = 1;
    println!("var={}", var);
    let var = var+ 1; // 기존의 var는 소멸되며 var이라는 새로운 변수가 생성
    println!("var={}", var);

    let var = 1;
    println!("var={}", var);
    let var = String::from("기존 var를 새도잉");
    println!("var={}", var);
}
