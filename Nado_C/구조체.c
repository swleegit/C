#include<stdio.h>
#define MAX 10000 //(;)를 붙이지 않는다. 어디서든 사용가능(전역변수), MAX는 완전 상수하고 같음.

struct gameinfo { //main함수 밖에서 구조체 선언
	char* name; //* 변수이름 꼴로 글자수 제한 없이 문자열을 담을 수 있다.
	int year;
	int price;
	char* company;
	struct gameinfo* friendgame;
	//구조체 안에 자신의 구조체(자료형)을 갖는 포인터 변수를 선언한것.
	//gameinfo1.friendgame = &gameinfo2
	//struct gameinfo 자료형을 갖는 gameinfo1을 선언하면
	//struct gameinfo 자료형을 갖는 포인터 변수 friendgame을 사용할 수 있으며(선언된 것과 마찬가지, 아직 초기화를 하지 않았을 뿐)
	//struct gameinfo 자료형을 갖는 gameinfo2를 선언하면 
	//위의 포인터변수와 자료형이 같기 때문에
	//gameinfo2의 주소를 할당할 수 있다.
	//그러면 gameinfo1안에 있는 friendgame이라는 포인터 변수에 gameinfo2가 동기화 된것 
	//그러면 (*friendgame).name 또는 friendgame->name으로 gameinfo2.name에 접근가능하다.
};

typedef struct gameinformation_1 { 
	char* name; 
	int year;
	int price;
	char* company;
	struct gameinfo* friendgame;
} GAME_INFO_1; //자료형 둘 중 택 1 : struct gameinformation 또는 GAME_INFO

typedef struct {
	char* name;
	int year;
	int price;
	char* company;
	struct gameinfo* friendgame;
} GAME_INFO_2; //이건 only 자료형 GAME_INFO만 가능하다.

int main(void)
{
	printf("전역변수 MAX의 값 : %d\n", MAX);
	//구조체 : 붕어빵 틀 
	//반복되는 형식을 편리하게 사용하기 위함. 파이썬 클래스와 비슷함.
	//파이썬에서는 클래스로 객체를 만들면 해당 인스턴스로 변수 생성(미리 만들어진 클래스 내부 변수(공격력, 방어력 등)가 할당됨 ; self.name = "마린")
	//그리고 미리 만들어진 클래스 안의 메소드로 객체만의 메소드 사용 가능함.

	struct gameinfo gameinfo1; //struct gameinfo가 하나의 자료형이고, gameinfo1가 변수이름
							   //파이썬으로 따지자면 위의 구문은 클래스 객체(인스턴스 = gameinfo1)을 만든것
	gameinfo1.name = "나도게임"; 
	gameinfo1.year = 2017;
	gameinfo1.price = 50;
	gameinfo1.company = "나도회사";

	//struct gameinfo를 자료형으로 하는 여러 변수 선언 가능함.

	struct gameinfo gameinfo2 = { "스타크래프트", 1998, 20, "블리자드" }; //중괄호 형식으로 차례로 대입가능함.
	//당연히 gameinfo2.name과 gameinfo1.name은 서로 다른 주소를 갖는 변수다.

	//배열을 활용한 구조체
	//어떤 자료형을 갖는 여러개의 변수를 동시에 만들고 싶을 때 배열을 사용함 
	//이때 자료형을 구조체로 사용한다는 것 

	struct gameinfo gameinfo[2] =
	{
		{"나도게임", 2017, 50, "너도게임"},
		{ "스타크래프트", 1998, 20, "블리자드" }
	};
	//이차원 배열로 생성을 안했는데 왜 2차원 배열 원소 대입처럼 함?
	//1차원 배열이지만 구조체 안에 변수가 4개가 있기 때문에 위와 같은 구조임.
	
	//게임이름 나열, 같은 구조체를 갖는 여러 변수를 나열하고 싶을 때 : 구조체 배열을 고려하자.
	for (int i = 0; i < 2; i++)
	{
		printf("게임이름 : %s \n", gameinfo[i].name);
	}

	//구조체 포인터
	//포인터 변수 선언시 : 자료형* 변수이름 하듯이
	//구조체* 변수이름 하면 '구조체'자료형을 갖는 포인터 변수를 선언하는 것 

	struct gameinfo* gameptr = &gameinfo1;
	//struct gameinfo 자료형을 갖는 gameptr 포인터 변수를 선언하고 앞서 선언한, struct gameinfo 자료형을 갖는 gameinfo1 주소를 할당함
	//포인터 변수와 동기될 변수는 자료형이 반드시!! 같아야 한다.
	
	//포인터 변수로 구조체 내부 변수에 접근하는 방법1
	printf("게임정보\n");
	printf("게임명 : %s \n", (*gameptr).name);
	printf("발매년도 : %d \n", (*gameptr).year);
	printf("가격 : %d \n", (*gameptr).price);
	printf("회사명 : %s \n", (*gameptr).company);

	//포인터 변수로 구조체 내부 변수에 접근하는 방법2
	printf("게임정보\n");
	printf("게임명 : %s \n", gameptr->name);
	printf("발매년도 : %d \n", gameptr->year);
	printf("가격 : %d \n", gameptr->price);
	printf("회사명 : %s \n", gameptr->company);

	//gameinfo2 자료형 struct gameinfo, gameinfo1 안에 변수 friendgame 포인터 변수 자료형 struct gameinfo
	//연동가능하다

	gameinfo1.friendgame = &gameinfo2;
	//(*friendgame).name --> 이건 틀림 , friendgame은 gameinfo1의 내부변수니까. (*gameinfo1.friendgame).name = 이런식으로 접근
	(*gameinfo1.friendgame).name = "스타크래프트2";
	gameinfo1.friendgame->year = 1980;
	printf("%s \n ", gameinfo2.name);


	//typedef 자료형에 별명을 지정한다 : 구조체는 자료형이 길기때문에 별명을 지정하면 편하다.
	int i = 1;
	typedef int 정수; //int 자료형의 별명을 정수로 지음 
	typedef float 실수;
	정수 num = 2;
	int num_1 = 3; //둘다 병행해서 사용 가능하다.





	
	

}