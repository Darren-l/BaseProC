#include "head01.h"
#include <errno.h>

void test08t2();
void test08t3();

/*
	1. ͷ�ļ������á�
	2. ����ת����
	3. �ɱ����������

*/
int mainT08() {

	//ͷ�ļ������á�
	//test08t1();

	//����ǿת��
	//test08t2();

	//perror("���������־����������");

	//�ɱ����
	test08t3();

	return 0;
}

void test08ttt(int num, ...) {

	//va_list valist;
	//va_start(valist, num);

	//for (int i = 0; i < num; i++) {
	//	int aa = va_arg(valist, int);
	//	printf("aa = %d \n", aa);
	//}

	//�����ڴ档
	//va_end(valist);
}

void test08t3() {
	

}

/*
	����ǿת�ķ�ʽ��javaһ����
*/
void test08t2() {
	float f = 3.14f;
	int i = (int)f;
	printf(" i = %d \n", i);
}

void test08t1() {
	an.name = "darren";
	an.age = 101;
	mm = 10;
	printf(" an---- name=%s , mm=%d \n", an.name, mm);
}


