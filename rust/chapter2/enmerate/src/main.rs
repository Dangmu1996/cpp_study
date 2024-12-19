enum Message{
    Quit, // Quit 액션을 나타내는 열겨형 멤버
    List(i32), // List 액션과 함께 i32 값을 가지는 열거형 멤버
    Put(String), // Put 액션과 함께 문자열 값을 가지는 열거형 멤버
    Get(i32), // Get 액션과 함께 i32 값을 가지는 열거형 멤버
}

// Message 열거형에 대한 메서드를 구현합니다.
impl Message{
    // execute 메서드는 Message 열거형의 인스턴스에 따라 특정 작업을 수행합니다.
    fn execute(&self){
        match self{ // self 에 따라 분기
            Message::Quit => println!("Quit"),
            Message::List(val)=>println!("List: {}", val),
            Message::Put(val)=>println!("Put: {}", val),
            Message::Get(val)=>println!("Get: {}", val),
        }
    }
}

fn print_optional(val : Option<String>){
    match val{
        Some(val)=>println!("{}", val), // 값이 있는 것 표현
        None => println!("None"), // 값이 없는 것
    }
}

fn main() {
    let m = Message::Put(String::from("/root/"));
    m.execute();
    let m = Message::Quit;
    m.execute();

    let some_string = Some(String::from("러스트"));
    let none_string: Option<String>=None;
    print_optional(some_string);
    print_optional(none_string);
}
