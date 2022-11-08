#include<stdio.h>

void swap(int a, int b);
void swap_addr(int* a, int* b);
void changeArray(int* ptr);

int main_func_pointer(void)
{
	//swap�Լ�
	int a = 10;
	int b = 20; //main�Լ��� a��b,swap�Լ����� a��b�� �����̸��� ����. ���� �ּҴ� ���� �ٸ�
	printf("a�� �ּ� : %d", &a);
	printf("b�� �ּ� : %d", &b);
	printf("swap �Լ� �� : a : %d, b : %d\n", a, b);
	swap(a, b);//swap �Լ��� 10�� 20�̶�� ���ڸ� �����Ѱ�. ���� ���� ���� (call by value)
	printf("swap �Լ� �� : a : %d, b : %d\n", a, b); //����� ����.

	swap_addr(&a, &b); //������ ������ a�� b�� �ּҸ� ������. ����ȭ��.
	printf("swap_addr �Լ� �� : a : %d, b : %d\n", a, b); //������ ������ Ȱ���ؼ� �ٸ�{}���� �Ҵ簪�� ������.

	//�迭���� � ������ ���� ���� 
	int arr2[3] = { 10,20,30 };
	changeArray(arr2); //������ �Ű������� arr2�� �ּҸ� �Ҵ���.
	for (int i = 0; i < 3; i++)
	{
		printf("%d\n", arr2[i]);
	}

}

void swap(int a, int b)
{
	printf("a�� �ּ� : %d\n", &a);
	printf("b�� �ּ� : %d\n", &b); //�̶� &a��&b�� swap�Լ����� ����� �������� a��b�� ���� �ּҴ�.
	
	int temp = a;
	a = b;
	b = temp;
	printf("swap �Լ� �� : a : %d, b : %d", a, b); //���⼭ �Ҵ簪�� �ٲ۰��� swap�Լ��� a��b�� �ٲ۰�
												   //main�Լ��� a�� b�� �ٲ۰� �ƴϴ�.
	
}

void swap_addr(int* a, int* b) //�Լ� �Ű������� main�Լ����� ����� &a�� �ϸ� ������ ������ �ּҸ� �Ҵ������Ƿ�
							   //swap_addr�Լ� ������ ����a�� main�Լ���a�� ����ȭ �Ȱ�
{
	int temp = *a;
	*a = *b;
	*b = temp;
	printf("swap �Լ� �� : a : %d, b : %d", *a, *b);
}
void changeArray(int* ptr)
{
	ptr[2] = 50;
}
