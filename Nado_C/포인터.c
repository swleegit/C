#include<stdio.h>

int main_pointer(void)
{
	//주소 &
	int 철수 = 1; //int형(4바이트)크기로 메모리에 공간을 만들고 그 공간을 철수라 이름 붙이고, 1을 할당함.
	int 영희 = 2;
	int 민수 = 3;

	printf("철수네 주소 : %d, 암호 %d\n", &철수, 철수); //&변수 --> 해당 변수의 주소(이상한 숫자)
	printf("영희네 주소 : %d, 암호 %d\n", &영희, 영희);
	printf("민수네 주소 : %d, 암호 %d\n", &민수, 민수);

	//포인터
	
	int* 미션맨 = 0; //변수 선언시 *을 앞에쓰면, 해당 변수는 포인터 변수
	미션맨 = &철수; //포인터 변수에서 *을 빼고 다른 변수의 주소를 할당하면, 해당 변수에 포인터 변수가 연결된것으로 생각
	printf("미션맨이 방문하는 곳 주소 %d, 암호: %d\n", 미션맨, *미션맨); //*을 포함하면 연결된 주소에 할당된 값
	printf("미션맨 변수 자체의 주소 : %d", &미션맨); //포인터 변수 자체의 주소는 다르다.
	미션맨 = &영희; //포인터 변수와 연결된 주소를 바꿀 수 있음. 중복택할 수는 없음.
	printf("미션맨이 방문하는 곳 주소 %d, 암호: %d\n", 미션맨, *미션맨);
	미션맨 = &민수;
	printf("미션맨이 방문하는 곳 주소 %d, 암호: %d\n", 미션맨, *미션맨);

	//a라는 변수에 할당된 값에 접근하는 방법
	//기존 처럼 a를 직접사용해서, a가 전역변수가 아니라 지역변수라면 이 방법은 같은 {}에서만 가능함.
	//또는 함수라면 새로운 변수에 return값을 할당해서 접근 가능함.
	//포인터를 사용, 다른 {}에서 선언된 변수여도 변수마다 주소는 고유함.
	//포인터 변수(자료형 *b)를 선언 (포인터변수에 어떤 값이 할당될지 생각후 자료형 판단)
	//b = &a -->포인터변수와 a변수 연결됨 
	//*b로 a에 할당된 값에 접근(수정)가능함.

	//철수의 비밀번호를 바꿔보자.
	//우선 미션맨을 철수와 동기화

	미션맨 = &철수;
	*미션맨 = *미션맨 * 3; //현재 철수의 암호(=*미션맨)에 곱하기 3
	printf("미션맨의 암호 : %d, 철수의 암호 : %d\n", *미션맨, 철수);
	
	//철수가 암호를 바꾸면 동기화된 미션맨의 암호도 바뀐다.
	철수 *= 50;
	printf("미션맨의 암호 : %d, 철수의 암호 : %d\n", *미션맨, 철수);

	//여러 포인터가 하나의 변수와 동기화 될 수 있다.
	int* 스파이 = 0; //'스파이'라는 포인터 변수 만듬
	스파이 = &철수; //포인터 변수 스파이를 철수와 동기화 시킴
	*스파이 -= 50; //미션맨, 철수, 스파이는 모두 동기화 되어 있음. 어느 하나의 값을 변경하면 나머지 모두 변경됨
	printf("미션맨 : %d, 철수 : %d, 스파이 : %d\n", *미션맨, 철수, *스파이);

	//각 포인터 변수는 자신만의 주소가 있다.
	printf("미션맨 주소 : %d, 스파이 주소 : %d, 철수 주소: %d\n", &미션맨, &스파이, &철수);

	
	//배열의 주소
	int arr[3] = { 0,1,2 };
	printf("%d\n", arr);
	printf("%d\n", &arr);
	printf("%d\n", &arr[0]); //arr = &arr = &arr[0]
	printf("%d\n", &arr[1]); //int자료형(4바이트)이기 때문에 주소가 4씩 차이난다.
	printf("%d\n", &arr[2]);

	//배열과 포인터
	int* prr = arr; // *prr에 arr을 할당하는게 아니라 prr에 arr을 할당하는 것 
					// 배열이름 arr은 &arr = &arr[0]과 같다. 즉 주소

	//배열과 포인터의 값.
	for (int i = 0; i < 3; i++) // 조건에 sizeof()사용하면 안됨. char은 1바이트여서 1단위이지만, int는 4단위, index초과하게 됨.
	{
		printf("prr[%d]의 값은 %d = arr[%d]의 값은 %d\n", i, prr[i], i, arr[i]);
	}

	//비교)
	//char* prr = arr; //배열 arr의 주소가 prr에 할당됨.
	//printf("%d = %d", prr[4], arr[1]); 
	//오류 발생, 어째뜬 포인터 변수는 연동되는 변수와 자료형이 같아야함.

	//비교)
	char ch[7] = "coding";
	char* pch = ch;
	printf("%d\n", &ch);
	printf("%d\n", &pch);
	printf("%d\n", ch);
	printf("%d\n", pch);
	printf("%s\n", pch);
	printf("%s\n", ch);
	printf("%d\n", pch[1]);
	printf("%d\n", &pch[1]);
	printf("%d\n", &ch[1]);

	//a = 1
	//int* b = &a
	//b = &a
	//&b 포인터변수 자체 주소
	//*b a에 할당된 값인 1

	//배열의 경우에는 좀 다르다.
	
	//int arr[7] = "coding"
	//int* prr = arr, arr = &arr = &arr[0], 따라서 배열의 주소를 할당한 것
	//printf("%d", prr), arr = &arr = &arr[0]의 주소가 할당됨.
	//coding이라는 값에 접근하려면 포인터 변수니까
	//printf("%s", *prr)을 해야할것 같지만, 아니다!
	//printf("%s", prr)하면된다.
	//각 원소에 접근할때도 
	//printf("%c", *prr[1])이 아니라
	//printf("%c", prr[1]), 그냥 arr 하고 사용법 같음!
	//printf("%d", prr[1]), o에 해당하는 아스키코드 실수값 반환.
	//prr을 d로 변환을 하면 주소가 나오는거고, prr을 s로 변환을 하면 해당 주소에 있는 문자열이 출력되는 것
	//변환문자를 어떻게 하냐에 따라 출력이 달라진다.
	//마치 0~127의 숫자를 숫자(d)로 보냐 문자(c)로 보냐에 따라 다른 것처럼.

	//printf("%d", &arr)
	//printf("%d", &prr)은 결과가 다르다. &prr은 포인터변수 자체의 주소다.
	//printf("%d", &arr[1])
	//printf("%d", &prr[1])은 결과가 같다. 시각화해서 생각하자.
	//prr[1] = 'c'로 할당된 값 수정 가능
	
	int array[3] = { 0,1,2 };
	int* parray = array;

	for (int i = 0; i < 3; i++)
	{
		parray[i] = 100 * (i + 1);
	}

	printf("%d\n",array[1]);

	//포인터와 별개로 배열에서 각 원소에 접근하는 다른 문법
	//*(arr + i) = arr[i]완전 동일한 표현, 포인터가 아닌 배열에서도, 포인터인 배열에서도 사용가능함.

	printf("%d = %d\n", *(array + 1), array[1]);
	printf("%d = '%d\n", *array, array[0]); //0번째 인덱스는 *(array + 0)이 아니다.
	//*로 표기하는 것은 포인터와는 무관하고 다른 변수가 아닌 배열형식에서만 가능하다.
	//*이라는 것은 그 값(=할당된 값)을 의미한다.
	//*&을 같이 사용하는 것은 그 주소에 할당된 값이므로 없는 것과 마찬가지다.

	printf("%d = %d = %d\n", *array, array[0], *&array[0]); // *array[0] 이거는 이중이여서 틀린 문법
	// *해당 할당된 값에 접근한다.

	char cod[7] = "coding";
	printf("%d\n", cod);
	printf("%d\n", &cod);
	printf("%d\n", &cod[0]);
	printf("%d\n", *cod);
	printf("%d\n", *(cod + 0)); //위에랑 같은 의미
	printf("%c\n", *cod);
	//printf("%s\n", *cod); 제어문자, 가능한 해석인 경우만 가능함. *cod는 c로 아스키코드 실수값 또는 문자만 가능함. 문자열은 불가능




	
	
	
}