fn main() {
    // if
    let condition = true;
    if condition == true{
        println!("조건이 참입니다.");
    }else{
        println!("조건이 거짓입니다.");
    }

    // let if
    let condition = true;
    let ret = if condition == true{
        String::from("조건이 참입니다.") // ;을 붙이면 컴파일 오류가 발생합니다.
    }else{
        String::from("조건이 거짓입니다.")
    };

    println!("ret={}", ret);

    // match
    let var = 1;
    match var{// var 값을 사용해 분기합니다.
        1 => println!("하나"),
        2 => println!("둘"),
        _ => println!("기타"),
    }

    let var = 1;
    let ret = match var{// match의 결과를 ret에 저장합니다.
        1=>String::from("하나"),
        2=>String::from("둘"),
        _=>String::from("기타"),
    };

    println!("ret={}", ret);

}
