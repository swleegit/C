#include<stdio.h> //전처리 지시자
				  //소스파일, 전처리(전처리지시자, 가공), 컴파일(기계어 변환), 링크(설치된 운영체제가 인식할 수 있게 startup code와 결합, main 함수필요)
				  //일괄주석 : cntrl + k + c, 주석해제 cntrl + k + u 
				  /*여러줄
				  주석입니다.*/
int main_datatype(void)
{
	//정수형 변수
	int age = 12; //(;), 변수 자료형 반드시, 초기값(쓰레기값), 초기화
	printf("%d\n", age); //출력 : printf, 변환문자(%), 자료형에 따라 , 제어문자(\), 모두 쌍따옴표로 둘러쌈.
	age = 13; //변수 : 코드가 진행됨에 따라 값이 변함.(정해진 자료형만 가능, 파이썬과 비교)
	printf("%d\n", age);

	//실수형 변수 
	//float 사용 
	float f = 46.5f; //float로 실수형 변수 했으면 숫자 뒤에 f
	printf("%.2f\n", f); //소숫점 제한 안하면 6자리까지, printf하면 커서는 바로 뒤에, 제어문자로 enter해야함.
	
	//double 사용 
	double d = 46.25;
	printf("%.2lf\n", d); //double 변환문자 lf

	//const 상수 지정 : 자주쓰는 상수를 이름으로 지정 가능함
	const int year = 2022;
	printf("태어난 년도 %d\n", year); //const로 지정했기 때문에 year 값은 변경할 수 없다.

	//printf 연산 수행 
	printf("%d * %d = %d\n", 30, 20, 30 * 20); //연산을 수행함
	//변환문자, 해당하는 값을 문자열로 변환, 해당하는 값의 자료형에 따라 변환문자는 달라진다.

	//scanf : 키보드의 값을 입력받아 저장(입력, 파이썬에서 input)
	int cd; //선언과 동시에 초기화, scanf값이 들어갈 변수를 미리 선언해야함.
	printf("값을 입력하세요."); //제어문자로 enter안하면 커서는 바로 뒤에 위치함.
	scanf_s("%d", &cd); //어떤 자료형을 받을지 변환문자로 하고, &앞에서 선언한 입력값을 받을 변수, 저절로 enter됨(\n불필요)
	printf("입력값: %d\n", cd);

	//동시에 여러값 선언
	int a = 1, b = 2, c = 3;
	printf("선언한 변수는 %d, %d, %d\n", a, b, c);

	//scanf_s 동시에 여러변수 받기 
	//1. 입력값 받을 변수 먼저 선언 
	int one = 0, two = 0, three = 0;
	printf("3개의 자연수를 입력하세요");
	scanf_s("%d %d %d", &one, &two, &three); //scanf에 제어문자 \n 넣지마..!
											 //scanf("%d %d %d",& , &, &)
	printf("%d, %d, %d\n", one, two, three); //입력시 엔터나 스페이스바로 구분 

	//문자(str) 변수 선언 
	char ch = 'a'; //문자(한글자) char로 받는다.
	printf("문자 : %c\n", ch);
	
	//문자열(string) 변수 선언 
	char str[256]; //문자열: 문자의 배열로 생각함. str이라는 전체 변수안에 str[0], str[1],..str[255]이렇게 있고 각 변수는 자료형(크기) char 
	scanf_s("%s", str, sizeof(str)); //배열로 지정한 문자열은 str자체가 주소이기 때문에 &를 붙이지 않고, 입력받을 문자의 개수를 sizeof로 조절한다.
	printf("%s", str);

	return 0;
}