#include<stdio.h>
#include <stdlib.h>

void test05t1();
void test05t2();
void test05t3();
void test05t4();

/*
	#define ��typedef������
		#define:Ԥ�����������ַ����滻���������滻�κ��ַ���
		typedef:������ִ�У�ֻ�����ڶ������͡�
*/
int mainT06() {

	//ʹ��typedef����ṹ��ͽṹ��ָ�롣
	//test05t1();

	//typedef�ṹ������ʱ��ʼ����
	//test05t2();

	//����ö��
	//test05t3();

	//����Ԥ���봦����
	test05t4();

	return 0;
}


void test05t4() {
//���Դ��롣
#if 0
	printf("11111111������ \n");
#else
	printf("2222222������ \n");
#endif



}


//ö��ʵ���Ͼ���һ�ֶ�ֵ��Լ���淶,���Ը�ֵ�������͡�
enum ctype {
	RED = 1,
	YEL = 2,
	BLU	//�Զ���ֵ��
};

void test05t3() {
	enum ctype c1 = RED;
	enum ctype c2 = YEL;
	enum ctype c3 = BLU;
	//enum ctype c4 = 10; 

	//printf("red=%d, yel=%d, blu=%d, c4=%d  \n", c1,c2,c3,c4);
}

//����TRUE�ַ�ʵ�ʶ�Ӧ����1
#define TRUE  1
#define TE  'b'
#undef TE

//typedef�����ڽṹ������ʱ���塣
typedef struct Son {
	char* name;
	int age;
}son;

void test05t2() {
	son s;
	s.name = "son";
	s.age = 10;
	printf("son name=%s, age=%d \n",s.name,s.age);
}


struct Person123 {
	char* name;
	int age;
};

typedef struct Person123 p;
typedef struct Person123* pd;
typedef int i;

void test05t1() {
	p ppp;
	ppp.name = "darren";
	ppp.age = 99;

	printf("person name=%s, age=%d \n", ppp.name, ppp.age);

	printf("p size = %d \n", sizeof(p));

	//��������ڷ�����ָ�뱾��Ĵ�С��
	printf("pd size = %d \n", sizeof(pd));

	pd pc = malloc(sizeof(p));
	pc->age = 101;
	pc->name = "darren123";
	printf("person name=%s, age=%d \n", pc->name, pc->age);
	free(pc);

	i iii = 100;



}
