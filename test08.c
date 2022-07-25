#include "head01.h"
#include <errno.h>

void test08t2();
void test08t3();

/*
	1. 头文件的引用。
	2. 类型转化。
	3. 可变参数函数。

*/
int mainT08() {

	//头文件的引用。
	//test08t1();

	//类型强转。
	//test08t2();

	//perror("输出错误日志。。。。。");

	//可变参数
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

	//清理内存。
	//va_end(valist);
}

void test08t3() {
	

}

/*
	类型强转的方式和java一样。
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


