use std::io; // std::io 패키지 로드

fn main() {
    let number = 30; // 32비트 정수, let number: i32 = 30; 으로 선언해도 동일
    let long_number: i64=123456789123567890; // 64비트 정수
    let real = 10.22; // 실수
    let hangul_char  = '러'; // 문자형

    println!("32비트 정수: {}", number);
    println!("64비트 정수: {}", long_number);
    println!("32비트 실수: {}", real);
    println!("문자: {}", hangul_char);

    // 정수형
    println!("i8: MIN={}, MAX={}", i8::MIN, i8::MAX);
    println!("i16: MIN={}, MAX={}", i16::MIN, i16::MAX);
    println!("i32: MIN={}, MAX={}", i32::MIN, i32::MAX);
    println!("i64: MIN={}, MAX={}", i64::MIN, i64::MAX);
    println!("i128: MIN={}, MAX={}", i128::MIN, i128::MAX);

    println!("u8: MIN={}, MAX={}", u8::MIN, u8::MAX);
    println!("u16: MIN={}, MAX={}", u16::MIN, u16::MAX);
    println!("u32: MIN={}, MAX={}", u32::MIN, u32::MAX);
    println!("u64: MIN={}, MAX={}", u64::MIN, u64::MAX);
    println!("u129: MIN={}, MAX={}", u128::MIN, u128::MAX);

    // 부동 소수점형
    println!("f32: MIN = {}, MAX = {}", f32::MIN, f32::MAX);
    println!("f64: MIN = {}, MAX = {}", f64::MIN, f64::MAX);

	// 튜플
	let tuple = (1,2,3);
	println!("tuple: {}, {}, {}", tuple.0, tuple.1, tuple.2);
	
	// (i32, char, bool) 타입의 튜플 (x, y, z)를 선언하고, 각각의 값으로 (1, 'a', true)를 할당합니다.
	let(x, y ,z) : (i32, char, bool) = (1, 'a', true);	

	// println! 매크로를 사용해 x, y, z의 값을 콘솔에 출력합니다.
	println!("x={}, y={}, z={}", x, y, z);
	
	// 배열
	// 정수 배열 arr을 선언하고 [1, 2, 3, 4, 5]로 초기화합니다.
	let arr = [1,2,3,4,5];

	// 배열 arr의 각 요소에 대해 반복합니다.
	for a in arr{
		// 현재 요소의 값을 콘솔에 출력합니다.
		print!("{}, ", a);
	}

	// println!을 사용하여 다음 라인으로 이동합니다.
	println!("");

	let arr : [i32; 5] = [1,2,3,4,5]; // i32 타입을 가지는 5개 원소

	for i in 0..arr.len(){
		print!("{}, ", arr[i]);
	}

	println!("");
	
	let mut arr : [i32; 5] = [1,2,3,4,5]; // i32 타입을 가지느 5개 원소
	
	// 문자 넣기
	println!("숫자를 입력해 주세요. " );
	
	let mut read = String::new(); // 입력값을 저장할 문자열 데이터 생성
	io::stdin().read_line(&mut read).unwrap(); // 키보드 입력을 읽습니다.
	let index: i32 = read.trim().parse().unwrap(); // 문자열을 숫자로 변환합니다.

	println!("arr[{}] = {}", index, arr[index as usize]);

	// 문자열 리터럴을 사용해 s 생성
	let s : &str = "Hello 러스트!";

	// s값 출력
	println!("문자열: {}", s);

	// 문자열 슬라이싱
	let slice : &str = &s[0..5];
	println!("슬라이스: {}", slice);

	let s : &str = "Hello Rust ";
	println!("{}", s.trim()); // 앞뒤 빈 공간 제거
	println!("{}", s.to_lowercase()); // 소문자로
	println!("{}", s.to_uppercase()); // 대문자로

	let mut s = String::from("Hello"); // Hello로 String 생성
	println!("{}", s);
	s.push_str(" Rust!"); // s 뒤에 Rust!를 추가
	println!("{}", s);


}
