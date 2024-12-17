fn main() {
    add(1,2);
    let ret = returnadd(1,2);
    println!("1+2={}", ret);

    //anonymous function
    let x= 1;
    let y= 2;
    let ret = {// 익명함수의 변환값을 ret에 저장
        x+y
    };

    println!("{}+{}={}", x, y, ret);
}

fn add(x : i32, y: i32){
    println!("{}+{}={}", x, y, (x+y));
}

fn returnadd(x: i32, y:i32)->i32{
    x+y // 새미콜론 없이
}