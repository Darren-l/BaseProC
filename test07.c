#include <stdio.h>

void test07t1();
void test07t2();


int mainT7() {
	
	//����staticȫ�ֱ�����
	//test07t1();

	test07t2();

	return 0;
}

/*
	extern
		1. �����ڱ����ͺ�����
		2. ��Ҫ�ⲿ���庯������ʵ��ʱ������ʹ�ø�������
*/
int test07_ex;
extern void test07_ex_fun1();

void test07t2() {
	test07_ex = 100;

	test07_ex_fun1();

	printf("test07_ex=%d \n", test07_ex);
}

static int sta_int;
void test07t1() {

	sta_int = 100;

	printf("static int=%d \n", sta_int);
}


