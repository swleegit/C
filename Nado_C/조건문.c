#include<stdio.h>
#include<stdlib.h>
#include<time.h> //전처리 지시자

int main(void)
{
	/*
	예제)
	몇 살이에요? 
	8-13 : 초등학생
	14-16 : 중학생
	17-19 : 고등학생
	그 이외: 학생이 아닙니다.
	*/

	int age = 0;
	printf("몇살이에요? ");
	scanf_s("%d", &age);

	if (age >= 8 && age <= 13) //파이썬은 if, for 뒤에 : 들여쓰기로 구분함 
	{
		printf("초등학생입니다\n");
	}

	else if (age >= 14 && age <= 16) //elif가 아니라 else if
	{
		printf("중학생입니다\n");
	}

	else if (age >= 17 && age <= 19)
	{
		printf("고등학생입니다\n");
	}

	else
	{
		printf("학생이 아닌가봐요.\n");
	}

	//if else if else 실행문이 한줄이면 들여쓰기로 구분해도 좋지만, 그 이상인 경우에는 반드시 {}로!
	//python : 13<age<17 13과 17사이
	//c : 13<age<17 age가 13보다 크면 1을 반환하고 1 < 17 :: 거짓 :: 0을 반환함.
	// and && or ||
	//반드시 확인해야하는 조건문은 if else if else 세트가 아니라 따로 if 를 형성하면 됨 .
	//연속된 if else if else가 한 덩어리임.

	//break
	//반복문(for, whlie, dowhile)에서 특정조건을 만족하면 해당 반복문을 바로 탈출 
	//break는 반복문 안에서 조건문과 같이쓰인다. 단독으로 사용하지 않음! 

	//예제)
	//몇번학생까지 발표하나요? : 2
	//1번학생 발표하세요
	//2번학생 발표하세요
	//나머지 집에 가세요.

	//방법1)
	int num = 0;
	printf("몇번학생까지 발표하나요?");
	scanf_s("%d", &num);
	
	for (int i = 1; i <= num; i++)
	{
		printf("%d번 학생 발표하세요.\n",i);
	}
	printf("나머지학생은 집에 가세요!\n");

	//방법2) break 사용 
	for (int i = 1; i <= 30; i++) //다른 {} 덩어리에서 선언한 변수는 다시 선언해서 사용할 수 있음.
	{
		printf("%d번 학생 발표하세요.\n", i);
		if (i == num)
		{
			printf("나머지학생은 집에 가세요!\n");
			break;
		}
	}
	
	//continue
}