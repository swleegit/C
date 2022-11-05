#include<stdio.h>

int main_arr(void)
{
	//배열: 같은 자료형의 여러개의 변수를 동시에 생성함.
	//자료형 변수이름[개수] 방식으로 선언한다.
	int subway_arr[3];

	subway_arr[0] = 30; //zero index
	subway_arr[1] = 40; 
	subway_arr[2] = 50;

	//예제) 지하철의 몇번 칸에는 몇명이 타고 있습니다.
	for (int i = 0; i < 3; i++) //i를 index로 활용하기 위해서
	{
		printf("%d칸에는 %d명이 타고 있습니다.\n", i, subway_arr[i]);
	}

	//값 할당 방법 
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 }; //{}를 활용해서 한번에 할당할 수 있다.
	for (int i = 0; i <= 9; i++)
	{
		printf("%d\n", arr[i]);
	}

	//배열의 크기(몇개를 만들건지)는 항상 상수로 선언, 상수값이 할당된 변수 사용불가, const로 선언된 상수로도 불가함.
	//모든 배열에 값을 반드시 할당해야하는 것은 아니다
	int arr_1[5] = { 1,2 }; //인덱스 2부터는 0으로 값 할당됨.
	for (int i = 0; i < 5; i++)
	{
		printf("%d\n", arr_1[i]);
	}
	
	//배열의 자료형이 float인 경우 값의 마지막에 반드시f를 붙여야 한다.
	float arr_f[5] = {1.0f, 2.0f};

	//배열의 크기 반드시 정할 필요 없다.
	int arr_3[] = { 1,2,3,4,5,6 }; //int arr_3[6] = {1,2,3,4,5,6}; 같음.

	//문자 vs 문자열
	char ch = 'a';//문자는 작은 따옴표를 이용한다.
	//문자열은 여러개의 문자가 있는것. 따라서 배열을 사용한다. 글자수보다 많게
	char str[7] = "coding"; //각 배열의 인덱스 별로 한글자씩 들어감. 연속된 마지막에는 문자의 끝을 나타내는 null \0이 들어간다.
	char str_1[6] = "coding"; //NULL문자가 들어갈 자리가 없어 끝에 이상한 값이 대입된다.
	printf("%s\n", str_1); //참고로 printf안에 문자'열'을 제외한 다른 자료형이 오면 그 자체로 출력되지 않는다.
						 //변환문자로 해당 자료형을 문자열 자료형으로 변환해야한다.
						 //str_1이라는 큰 배열 안에 인덱스 변수가 있다고 생각하면됨 .

	char str_2[] = "coding"; //배열의 크기는 null를 추가로 고려하여 7개
	printf(str_2); //문자열이기 때문에 변환문자를 반드시 사용할 필요없음, 단 제어문자를 함께 쓰기 힘들어지므로 그냥 변환문자 같이 사용 권고
	printf("%d\n", sizeof(str)); //sizeof(배열) 배열의 크기를 반환한다.

	//예제)coding 한글자씩 엔터로 구분하여 출력해라
	char str_3[] = "coding"; //크기는 6
	for (int i = 0; i < sizeof(str_3); i++) //zero index니까 0,1,2,3,4,5, 5는 null
	{
		printf("%c\n", str_3[i]);
	}

	//char 1개 : 1byte, 영어 한글자 : 1byte, 한글 한글자 : 2byte
	char kor[] = "나도코딩";
	printf("%s\n", kor);
	printf("%d\n", sizeof(kor));

	//sizeof
	int i = 8; //i라는 변수의 자료형의 크기는 int로 4바이트
	printf("%d\n", sizeof(i)); //결과는 4

	//예제) 이름이 뭐에요?_ name[]
	char name[] = "name"; //여기서 name배열의 크기는 5바이트로 결정됨. 따라서 5바이트 이상의 값은 대입못함
	printf("이름이 뭐에요? : ");
	scanf_s("%s", name, sizeof(name)); //문자열 scanf_s사용시 반드시 sizeof 있어야한다
	printf("%s씨 안녕하세요!\n", name);

	//예제) 이름이 뭐에요? _ name[250]
	char name_re[250] = "name";
	printf("이름이 뭐에요? : ");
	scanf_s("%s", name_re, sizeof(name_re));
	printf("%s씨 안녕하세요!\n", name_re); //5바이트보다 큰 문자열을 대입해도 정상적으로 출력됨 

	//비교)
	char name_1[255] = "name";
	printf("%s\n", name_1); //name의 주소가 아니라 name배열에 들어있는 값 전체 출력
	printf("%c\n", name_1[20]); //문자열에서 대입되지 않는 인덱스는 null이 대입된다.
	
	//비교)
	int number[255] = { 0,1,2,3 };
	printf("%d\n", number); //알 수 없는 숫자가 출력된다. number배열의 주소
	printf("%d\n", number[6]); //숫자에서는 대입되지 않는 인덱스는 0이 대입됨.

	//(signed)char : 8bit, -128 ~ 127 총 255개
	//unsigned char : 8bit, 0 ~ 255

	char num_char = 129; //signed char에 129 대입 : 범위를 넘어감 
	printf("%d\n", num_char); // 이상한 숫자 나옴.
	printf("%c\n", num_char); // %c는 0~127에 해당하는 문자만 가능함.

	unsigned char num_char_1 = 253;
	printf("%d\n", num_char_1); //253 출력됨. 즉 자료형을 나타내는 것은 단순히 '크기'임.
								//char을 숫자에 사용해도 틀린것은 아님. 단지 그 숫자의 범위가 작아 제한이 많음.
	
	//아스키코드(ASCII) : ANSI(미국표준협회)에서 제시한 표준 코드 체계
	//7bit 총 128개 코드 0 ~ 127(십진법 아스키코드값)

	printf("문자와 아스키코드값\n");
	for (int i = 0; i < 128; i++)
	{
		printf("%c : %d\n", i, i); //%c, 숫자 1에 해당하는 문자, 즉 대입된 값을 어떻게 변환하느냐에 따라 출력이 다름
	}





	







}
