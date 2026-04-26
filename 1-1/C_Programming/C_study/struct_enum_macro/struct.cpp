#include <string.h>
#include <stdio.h>

#define NAME_LEN 20
#define PHONE_LEN 20
//구조체 : 여러개의 변수를 묶어 하나의 타입으로 만드는 것. 상속, 캡슐화, 메서드가 없다는 점에서 클래스보다는 낮은 개념.

//구조체 선언) 이때, 초기값을 할당할 순 없음. 메모리가 이 단계에서는 할당 X
struct Person {
	char name[NAME_LEN];
	//3byte의 패딩 발생
	int age;
	char grade;
	void (*speak) ();  //함수 포인터의 선언 : 함수반환값에따른타입명 (*포인터명) (매개변수 표시); ex. int (*ptr) (int, int); \n ptr = add;
	char phone[PHONE_LEN];
	//3byte의 패딩 발생
};

void speak() { printf("안녕!"); 
}
typedef struct student {
	char grade;
	int age;
}student;  // 결국 typedef student student가 생략되어 한 블럭안에 들어간 구문임. 
//typedef로 인해 객체 만들때 student s1;이런식으로 가능.


//구조체의 크기는 단순히 내부 멤버 변수 값의 합이 아님. CPU의 메모리 효율을 높이기 위해 4 또는 8바이트로 끊어서 읽음 (4byte기준으로 데이터를 읽는게 좀 더 효율적)
//이를 위해 Padding이라는 빈 바이트 공간을 집어 넣음.  (배열이 들어가 애매하게 35byte가 된 struct가 있으면 36byte로 읽음.) 

struct Point {   // 익명구조체(계층화 가능하다)
	struct {
		int x, y;
	};
	int health;
};

int main() {
	struct Person s1; // 메모리 할당
	strcpy_s(s1.name, "홍길동");
	s1.grade = 'A';
	s1.speak = speak;  //s1.speak (포인터)에 speak 함수 주소 넣기 이때 함수 이름은 자동으로 포인터로 변환되기에 배열처럼 &안붙여도 됨.
	s1.speak();   //함수 사용
	printf("전화번호 :");
	gets_s(s1.phone, PHONE_LEN);
	return 0;
}