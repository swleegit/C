#include<stdio.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);

int main_func_pointer(void)
{
	//swap함수
	int a = 10;
	int b = 20; //main함수의 a와b,swap함수에서 a와b는 변수이름만 같다. 실제 주소는 서로 다름
	printf("a의 주소 : %d", &a);
	printf("b의 주소 : %d", &b);
	printf("swap 함수 전 : a : %d, b : %d\n", a, b);
	swap(a, b);//swap 함수에 10과 20이라는 숫자를 대입한것. 값에 의한 복사 (call by value)
	printf("swap 함수 후 : a : %d, b : %d\n", a, b); //결과는 같음.

	swap_addr(&a, &b); //포인터 변수에 a와 b의 주소를 대입함. 동기화됨.
	printf("swap_addr 함수 후 : a : %d, b : %d\n", a, b); //포인터 변수를 활용해서 다른{}에서 할당값을 변경함.

	//배열에서 어떤 변수의 값을 변경 
	int arr2[3] = { 10,20,30 };
	changeArray(arr2); //포인터 매개변수에 arr2의 주소를 할당함.
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}

}

void swap(int a, int b)
{
	printf("a의 주소 : %d\n", &a);
	printf("b의 주소 : %d\n", &b); //이때 &a와&b는 swap함수에서 선언된 지역변수 a와b에 대한 주소다.
	
	int temp = a;
	a = b;
	b = temp;
	printf("swap 함수 내 : a : %d, b : %d", a, b); //여기서 할당값을 바꾼것은 swap함수의 a와b를 바꾼것
												   //main함수의 a와 b를 바꾼게 아니다.
	
}

void swap_addr(int* a, int* b) //함수 매개변수로 main함수에서 선언된 &a를 하면 포인터 변수에 주소를 할당했으므로
							   //swap_addr함수 포인터 변수a와 main함수의a는 동기화 된것
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap 함수 내 : a : %d, b : %d", *a, *b);
}
void changeArray(int* ptr)
{
	ptr[2] = 50;
}
