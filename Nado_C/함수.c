#include<stdio.h>

//특정 기능하는 것들을 한데 모아 : 함수
//main함수 위에 : 이름만 
//리턴값이 있는 경우, 매개변수가 있는 경우

//두개의 값을 더해서 결과(정수)를 반환하는 함수 

int sum(int num_1, int num_2); //return의 자료형이 int이고 int 자료형인 두개의 매개변수, 함수이름은 sum
int sum_1(int num_1, int num_2); //sum(2,3)의 결과를 받아서 추가적으로 합함
void words(void); //return도 없고 매개변수도 없음.
int main_func(void)
{
	words(); //리턴값과 매개변수가 없는 함수를 호출함.
	int num_1 = 0, num_2 = 0;
	printf("철수와 영희에게 각각 몇개의 사과를 줄 건가요?");
	scanf_s("%d %d", &num_1, &num_2);
	//바로 리턴값 사용
	printf("철수는 %d 영희는 %d, 총 합 %d 군요!\n", num_1, num_2, sum(num_1, num_2));

	//반환값을 변수에 할당하여 해당 변수를 함수의 매개변수로 사용 
	int ret = sum(num_1, num_2); //변수의 자료형과 반환값의 자료형 매칭을 잘해야함.
	printf("%d\n", sum_1(ret, ret));

}

int sum(int num_1, int num_2) //main함수 이전에 선언한 함수를 그대로 가져오되 (;)만 제외하고 가져온다.
{
	int sum_re = num_1 + num_2; 
	return sum_re; //함수를 선언한 위치로 sum_re주소에 할당된 값을 보낸다.
	
	//같은 이름의 변수(지역변수)더라도 선언된 {}위치가 다르다면, 다른 주소를 가진 변수임.
	//sum함수에서 선언된 num_1과 다른 함수에서 선언된 num_1은 이름만 같지 주소는 다름 
}

int sum_1(int num_1, int num_2)
{
	int total = num_1 + num_2 + sum(2, 3);
	//정의한 함수를 다른 함수에서 사용가능함
	//return값인 sum_re에 할당된 5를 가져옴
	//여기서 사용된 num_1은 sum함수의 num_1과 다름
	return total;
}

void words(void)
{
	printf("리턴값도 없고 출력값도 없는 함수입니다.\n");
	printf("내부 실행문만 실행됩니다.\n");
	printf("사과를 구매합니다.\n");
}

