#define _CRT_SECURE_NO_WARNINGS	//���windoows����strcpy����
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>


/*
	C�����к�����ָ��

*/

int add(int arg1,int arg2);
int operater(void(*method)(int, int), int num, int num2);
void test02t1();
void test02t2();
//void test02t3();

void test02t4();

int main() {

	printf("Test02... \n");
	//�߽׺������������á�
	//test02t1();

	//����ָ���ʹ��
	//test02t2();

	//C�����е�ָ�롣
	//test02t3();

	//ָ����Ϊ����ֵ��
	test02t4();

	return 0;
}

int* test02t4tt(int a, int b) {
	int* p;
	int re = a + b;
	p = &re;
	return p;
}

/*
	ָ��ΪΪ����ֵ��
*/
void test02t4() {
	int* p;
	p = test02t4tt(10, 20);
	printf("test02t4tt p=%p, *p=%d \n",p, *p);

}


/*
	����ָ��Ҳ�����ں���������������kotlin��ࡣ

	���ں���ָ���ַ����洢��������Լ��ĵ�ַ�����Ը�ֵ��&���ſ���ʡ�ԣ�����ʹ��ʱ����Ҫ��*��
*/
void test02t2() {
	//����һ��callback�ĺ���ָ�롣
	int (*callback)(int arg, int arg2);
	//�������ȡ��ַ��Ҳ���Բ�ȡ��ʵ��ֵ��һ���ģ�
	callback = &add;

	//ֱ�ӵ���,�Ӳ���*Ч����һ���ġ�
	//callback(1,2);
	(*callback)(1, 2);

	//���ߵ����������ݡ�
	operater(callback, 3, 4);
}

void test02t1() {
	//�����ǣ�ֱ�Ӵ��뺯�������ơ�
	operater(&add, 2, 3);

	//C�����У���������Ҳ��ָ���һ�֣�add�ĵ�ַ��&add��ͬ��
	printf("add��ָ���ַΪ��addp=%p, &addp=%p\n", add, &add);
}

/*
	��������Ҳ����Ϊ�������ݸ�����������kotlin�߽׺���һ������������ָ�롣
	��ʽ��
		����ֵ(*��������������1������2��
	���ã�
		����ĺ����������ص���

*/
int operater(int(*method)(int, int), int num, int num2) {
	return method(num, num2);
}

int add(int arg1, int arg2) {
	printf("arg1 + arg2 = %d \n",arg1 + arg2 );
	return arg1 + arg2;
}



