fn main() {
    let var = 1; // 불변 변수 생성

    let mut var_2 = 1; // mut을 사용하면 값을 수정할 수 있음
    println!("수정 전={}", var_2);

    var_2 = 2;

    println!("수정 후={}", var_2);
}
