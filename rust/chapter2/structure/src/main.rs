use std::io;

// Debug 트레잇을 구현하도록 지시하는 derive 어노테이션, 이를 통해서 Student 구조체 인스턴스를 디버깅 정보로 쉽게 출력 할 수 있음
#[derive(Debug)]
struct Student{
    id: i32,
    name: String,
    email: String,
}

struct Score{
    score: i32,
}

fn main() {
    println!("학번을 입력해주세요.");
    let mut id = String::new();
    io::stdin().read_line(&mut id);
    let id : i32 = id.trim().parse().unwrap();

    println!("이름을 입력해주세요.");
    let mut name = String::new();
    io::stdin().read_line(&mut name);
    let name  = name.trim().to_string();

    println!("이메일을 입력해 주세요.");
    let mut email = String::new();
    io::stdin().read_line(&mut email);
    let email  = email.trim().to_string();

    let stu = create_student(id, name, email);
    println!("학번={}, 이름={}, 이메일={}", stu.id, stu.name, stu.email);
    println!("stu={:?}", stu);
}

fn create_student(id: i32, name: String, email: String) -> Student{
    Student{
        id: id,
        name: name,
        email: email,
    }


}

impl Score{
    fn get_grade(&self)->String{
        if self.score > 90{
            String::from("A")
        }else if self.score>80{
            String::from("B")
        }else{
            String::from("C")
        }
    }

    fn from(score: i32)->Score{
        Score{score : score}
    }
}


#[test]
fn test_get_grade(){
    let score = Score{
        score : 100,
    };
    // score.get_grade()가 "A"를 반환하는지 검사 
    assert_eq!(score.get_grade(),"A");

    // Score 구조체 인스턴스 생성, 점수는 80
    let score =Score{
        score:80,
    };

    assert_eq!(score.get_grade(),"C");

    // 연관함수 구조체의 인스턴스 없이도 호출이 가능 한 것(associated functions)
    assert_eq!(Score::from(100).get_grade(), "A");
    assert_eq!(Score::from(90).get_grade(), "B");
}
