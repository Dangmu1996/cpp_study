struct Node{
    value: i32, // 노드의 값을 저장하는 i32 타입의 필드
    next: Option<Box<Node>>, // 다음 노드를 가리키는 필드, Option을 사용해 노드가 없을 수 있는 상황(예: 마지막 노드)을 처리
}

impl Node{
    fn append(&mut self, elem: i32){
        match self.next{
            Some(ref mut next)=>{// 값이 있을 경우
                next.append(elem); // 마지막 노드를 찾기 위해 다음 노드로 이동
            }
            None=>{// 값이 없을 경우 마지막 노드로 간주
                let node=Node{ // 마지막 노드에 값을 삽입
                    value: elem,
                    next: None
                };
                self.next = Some(Box::new(node))
            }
        }
    }

    fn list(&self){
        println!("{}", self.value);
        match self.next{
            Some(ref next) => next.list(),
            None=>{},
        }
    }
}

fn main() {
    let mut head = Node{
        value: 1,
        next: None,
    };

    for i in 2..10{
        head.append(i);
    }

    head.list();
}
