#include<stdio.h>
#define MAX 10000 //(;)�� ������ �ʴ´�. ��𼭵� ��밡��(��������), MAX�� ���� ����ϰ� ����.

struct gameinfo { //main�Լ� �ۿ��� ����ü ����
	char* name; //* �����̸� �÷� ���ڼ� ���� ���� ���ڿ��� ���� �� �ִ�.
	int year;
	int price;
	char* company;
	struct gameinfo* friendgame;
	//����ü �ȿ� �ڽ��� ����ü(�ڷ���)�� ���� ������ ������ �����Ѱ�.
	//gameinfo1.friendgame = &gameinfo2
	//struct gameinfo �ڷ����� ���� gameinfo1�� �����ϸ�
	//struct gameinfo �ڷ����� ���� ������ ���� friendgame�� ����� �� ������(����� �Ͱ� ��������, ���� �ʱ�ȭ�� ���� �ʾ��� ��)
	//struct gameinfo �ڷ����� ���� gameinfo2�� �����ϸ� 
	//���� �����ͺ����� �ڷ����� ���� ������
	//gameinfo2�� �ּҸ� �Ҵ��� �� �ִ�.
	//�׷��� gameinfo1�ȿ� �ִ� friendgame�̶�� ������ ������ gameinfo2�� ����ȭ �Ȱ� 
	//�׷��� (*friendgame).name �Ǵ� friendgame->name���� gameinfo2.name�� ���ٰ����ϴ�.
};

typedef struct gameinformation_1 { 
	char* name; 
	int year;
	int price;
	char* company;
	struct gameinfo* friendgame;
} GAME_INFO_1; //�ڷ��� �� �� �� 1 : struct gameinformation �Ǵ� GAME_INFO

typedef struct {
	char* name;
	int year;
	int price;
	char* company;
	struct gameinfo* friendgame;
} GAME_INFO_2; //�̰� only �ڷ��� GAME_INFO�� �����ϴ�.

int main(void)
{
	printf("�������� MAX�� �� : %d\n", MAX);
	//����ü : �ؾ Ʋ 
	//�ݺ��Ǵ� ������ ���ϰ� ����ϱ� ����. ���̽� Ŭ������ �����.
	//���̽㿡���� Ŭ������ ��ü�� ����� �ش� �ν��Ͻ��� ���� ����(�̸� ������� Ŭ���� ���� ����(���ݷ�, ���� ��)�� �Ҵ�� ; self.name = "����")
	//�׸��� �̸� ������� Ŭ���� ���� �޼ҵ�� ��ü���� �޼ҵ� ��� ������.

	struct gameinfo gameinfo1; //struct gameinfo�� �ϳ��� �ڷ����̰�, gameinfo1�� �����̸�
							   //���̽����� �����ڸ� ���� ������ Ŭ���� ��ü(�ν��Ͻ� = gameinfo1)�� �����
	gameinfo1.name = "��������"; 
	gameinfo1.year = 2017;
	gameinfo1.price = 50;
	gameinfo1.company = "����ȸ��";

	//struct gameinfo�� �ڷ������� �ϴ� ���� ���� ���� ������.

	struct gameinfo gameinfo2 = { "��Ÿũ����Ʈ", 1998, 20, "���ڵ�" }; //�߰�ȣ �������� ���ʷ� ���԰�����.
	//�翬�� gameinfo2.name�� gameinfo1.name�� ���� �ٸ� �ּҸ� ���� ������.

	//�迭�� Ȱ���� ����ü
	//� �ڷ����� ���� �������� ������ ���ÿ� ����� ���� �� �迭�� ����� 
	//�̶� �ڷ����� ����ü�� ����Ѵٴ� �� 

	struct gameinfo gameinfo[2] =
	{
		{"��������", 2017, 50, "�ʵ�����"},
		{ "��Ÿũ����Ʈ", 1998, 20, "���ڵ�" }
	};
	//������ �迭�� ������ ���ߴµ� �� 2���� �迭 ���� ����ó�� ��?
	//1���� �迭������ ����ü �ȿ� ������ 4���� �ֱ� ������ ���� ���� ������.
	
	//�����̸� ����, ���� ����ü�� ���� ���� ������ �����ϰ� ���� �� : ����ü �迭�� �������.
	for (int i = 0; i < 2; i++)
	{
		printf("�����̸� : %s \n", gameinfo[i].name);
	}

	//����ü ������
	//������ ���� ����� : �ڷ���* �����̸� �ϵ���
	//����ü* �����̸� �ϸ� '����ü'�ڷ����� ���� ������ ������ �����ϴ� �� 

	struct gameinfo* gameptr = &gameinfo1;
	//struct gameinfo �ڷ����� ���� gameptr ������ ������ �����ϰ� �ռ� ������, struct gameinfo �ڷ����� ���� gameinfo1 �ּҸ� �Ҵ���
	//������ ������ ����� ������ �ڷ����� �ݵ��!! ���ƾ� �Ѵ�.
	
	//������ ������ ����ü ���� ������ �����ϴ� ���1
	printf("��������\n");
	printf("���Ӹ� : %s \n", (*gameptr).name);
	printf("�߸ų⵵ : %d \n", (*gameptr).year);
	printf("���� : %d \n", (*gameptr).price);
	printf("ȸ��� : %s \n", (*gameptr).company);

	//������ ������ ����ü ���� ������ �����ϴ� ���2
	printf("��������\n");
	printf("���Ӹ� : %s \n", gameptr->name);
	printf("�߸ų⵵ : %d \n", gameptr->year);
	printf("���� : %d \n", gameptr->price);
	printf("ȸ��� : %s \n", gameptr->company);

	//gameinfo2 �ڷ��� struct gameinfo, gameinfo1 �ȿ� ���� friendgame ������ ���� �ڷ��� struct gameinfo
	//���������ϴ�

	gameinfo1.friendgame = &gameinfo2;
	//(*friendgame).name --> �̰� Ʋ�� , friendgame�� gameinfo1�� ���κ����ϱ�. (*gameinfo1.friendgame).name = �̷������� ����
	(*gameinfo1.friendgame).name = "��Ÿũ����Ʈ2";
	gameinfo1.friendgame->year = 1980;
	printf("%s \n ", gameinfo2.name);


	//typedef �ڷ����� ������ �����Ѵ� : ����ü�� �ڷ����� ��⶧���� ������ �����ϸ� ���ϴ�.
	int i = 1;
	typedef int ����; //int �ڷ����� ������ ������ ���� 
	typedef float �Ǽ�;
	���� num = 2;
	int num_1 = 3; //�Ѵ� �����ؼ� ��� �����ϴ�.





	
	

}