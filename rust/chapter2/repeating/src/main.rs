use std::io;

fn main() {
    // loop
    loop{// 다른 언어의 while(true)와 같다.
        println!("숫자를 입력해 주세요. 0을 입력하면 종료합니다");
        let mut read = String::new();
        io::stdin().read_line(&mut read).unwrap();
        let val : i32 = read.trim().parse().unwrap();

        if val == 0{
            break;
        }
        println!("입력={}", val);
    }

    // for
    let arr = [1,2,3,4,5];
    for a in arr{// arr을 순회합니다.
        print!("{}, ", a);
    }

    for a in 0..5{// 5회 반복
        print!("{}, ", a);
    }

    // while
    let mut counter = 0;
    while counter < 5{//counter가 5 미만일 때까지 반복합니다.
        print!("{},",counter);
        counter +=1;

    }
    
}
