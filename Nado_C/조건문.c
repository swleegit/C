#include<stdio.h>
#include<stdlib.h>
#include<time.h> //전처리 지시자

int main(void)
{
	///*
	//예제)
	//몇 살이에요? 
	//8-13 : 초등학생
	//14-16 : 중학생
	//17-19 : 고등학생
	//그 이외: 학생이 아닙니다.
	//*/

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
	//반복문 안에서 단독이 아니라 조건문과 같이 사용된다
	//continue 아래 반복문에 속한 구문을 실행하지 않고 다시 반복문의 원점(시작점)으로 돌아간다.

	//예제) 1~10번까지 발표하세요. 7번은 아파서 결석입니다.
	int num_absent = 0;
	printf("결석인 학생 번호: ");
	scanf_s("%d", &num_absent);
	
	for (int i = 1; i <= 10; i++)
	{
		if (i == num_absent)
		{
			printf("%d번 학생은 아파서 결석입니다.\n", i);
			continue;
		}
		printf("%d번 학생 발표하세요.\n", i);
	}
	

	//난수

	srand(time(NULL)); //난수 초기화
	int num_1 = rand() % 3; //3개의 숫자 0,1,2 중 한개를 랜덤으로 고른다. (실행마다 결과 다름)
							//3 + 1 하면 3개의 숫자가 1,2,3임. 1,2,3 중 한개를 랜덤으로 고르는 것
	
	printf("난수 초기화 이전\n");
	for (int i = 1; i < 10; i++)
	{
		printf("%d", rand() % 10); //i 사용하지 않음. 필수로 사용해야하는 것 아님!
								   //for 반복당 0~9임의 숫자 한개 출력
								   //계속 실행해도 똑같은 배열의 난수를 출력함. 난수를 초기화 하지 않아서.
	}

	printf("난수 초기화 이후\n");
	for (int i = 1; i < 10; i++)
	{
		srand(time(NULL));
		printf("%d", rand() % 10); //for구문 루프 한번 돌 때마다 난수 초기화
							       //난수 초기화하지 않으면 이미 있던 배열에서 하나씩 꺼내서 보여준다고 생각.
								   //초기화 하지 않으면 루프마다, 실행을 다시 할때 마다 같은 배열임.
								   //난수 초기화란 그 배열의 순서를 바꾸는 것을 의미함.
								   //rand 함수를 사용하려면 전처리 지시자로 stdlib.h
								   //난수초기화 srand(time(NULL))을 사용하려면 time.h
								   //특정 함수는 특정 전처리지시자(파이썬에서 모듈이라 생각)이 필요
	}

	/*예제) 사용자로부터 가위, 바위, 보를 입력 받고
	랜덤으로 가위,바위,보를 출력해 승패를 결정짓는 코드를 만들어보자.*/
	
	/*반복문이 돌때마다 하나의 {} 안에서 선언하면 오류남.
	반복문이 돌때마다 '재할당'은 가능함.
	반복문안에서 변수 선언하면 안됨. 밖에서 해야함.*/

	int input = 0;
	int num_2 = 0;
	int re = 0;
	
	while (1) //while, whlie 스팰링 제발! 
	{
		//입력값
		printf("가위0바위1보2:  ");
		scanf_s("%d", &input);
		printf("\n");

		if (input < 0 || input > 2)
		{
			printf("값을 잘못 입력했습니다\n");
			continue;
		}
		
		//난수 초기화
		srand(time(NULL));
		num_2 = rand() % 3;

		//사용자가 입력한 값
		if (input == 0)
		{
			printf("나 : 가위\n");
		}

		else if (input == 1)
		{
			printf("나 : 바위\n");
		}

		else
		{
			printf("나 : 보\n");
		}

		//컴퓨터에서 나온 값 

		if (num_2 == 0)
		{
			printf("상대 : 가위\n");
		}

		else if (num_2 == 1)
		{
			printf("상대: 바위\n");
		}

		else
		{
			printf("상대 : 보\n");
		}

		//승패

		if (num_2 == input)
		{
			printf("비겼습니다!. 다시하시겠습니까?(0/1) ");
			scanf_s("%d", &re);
			
			if (re == 0) //숫자, 문자, 문자열 사용가능함! 문자는 '' 문자열은 "", 변수로 지정할때만 알맞은 자료형의 크기를 사용하면됨.
			{
				printf("종료합니다\n");
				break;
			}

			else
			{
				printf("다시시작합니다.\n");
				continue;
			}
		}

		else // 비기지 않은 경우
		{
			if (input == 0) // 비기지 않고 나: 가위인경우, num_2 : 바위(1), 짐, num_2 : 보(2), 이김
			{
				if (num_2 == 1)
				{
					printf("졌습니다!. 다시하시겠습니까?(0/1) ");
					scanf_s("%d", &re);

					if (re == 0)
					{
						printf("종료합니다\n");
						break;
					}

					else
					{
						printf("다시시작합니다.\n");
						continue;
					}

				}
				else //나 : 가위, 상대 : 보
				{
					printf("이겼습니다!.다시하시겠습니까 ? (0/1) ");
					scanf_s("%d", &re);

					if (re == 0)
					{
						printf("종료합니다\n");
						break;
					}

					else
					{
						printf("다시시작합니다.\n");
						continue;
					}
				}

			}

			 
		}
	}
	
		



		
	


}