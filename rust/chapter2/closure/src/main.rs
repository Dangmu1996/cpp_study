fn main() {
    // clousure : 함수 내부에서 외부 범위의 변수를 조작하거나 사용해야 할 경우 주변 범위의 변수를 '캡처'하고 사용할 수 있는 익명 함수
    let mut x = 5;
    let mut inc = || {
        x+=1;
    };
    inc();
    println!("변수 x: {}", x);

    // closure with parameter
    let x = 10;
    let add = |y|{x+y}; 
    println!("10+5={}", add(5));

    // move 
    let s = String::from("Hello");
    let f = move || { // move 클로저는 소유권을 이전
        println!("s: {}", s);
    };

    f();
    //println!("s: {}", s); 이러면 s 소유권이 없어서 erro

}