#define _CRT_SECURE_NO_WARNINGS	//规避windoows调用strcpy报错。
#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>


/*
	C语言中函数及指针

*/

int add(int arg1,int arg2);
int operater(void(*method)(int, int), int num, int num2);
void test02t1();
void test02t2();
//void test02t3();

void test02t4();

int main() {

	printf("Test02... \n");
	//高阶函数申明及调用。
	//test02t1();

	//函数指针的使用
	//test02t2();

	//C语言中的指针。
	//test02t3();

	//指针作为返回值。
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
	指针为为返回值。
*/
void test02t4() {
	int* p;
	p = test02t4tt(10, 20);
	printf("test02t4tt p=%p, *p=%d \n",p, *p);

}


/*
	函数指针也可以在函数中声明，这点和kotlin差不多。

	由于函数指针地址本身存储对象就是自己的地址，所以赋值是&符号可以省略，另外使用时不需要加*。
*/
void test02t2() {
	//声明一个callback的函数指针。
	int (*callback)(int arg, int arg2);
	//这里可以取地址，也可以不取，实际值是一样的，
	callback = &add;

	//直接调用,加不加*效果是一样的。
	//callback(1,2);
	(*callback)(1, 2);

	//或者当做参数传递。
	operater(callback, 3, 4);
}

void test02t1() {
	//调用是，直接传入函数的名称。
	operater(&add, 2, 3);

	//C语言中，函数本身也是指针的一种，add的地址与&add相同。
	printf("add的指针地址为：addp=%p, &addp=%p\n", add, &add);
}

/*
	函数本身也能作为参数传递给函数，这点和kotlin高阶函数一样，叫做函数指针。
	格式：
		返回值(*函数名）（参数1，参数2）
	作用：
		传入的函数可用作回调。

*/
int operater(int(*method)(int, int), int num, int num2) {
	return method(num, num2);
}

int add(int arg1, int arg2) {
	printf("arg1 + arg2 = %d \n",arg1 + arg2 );
	return arg1 + arg2;
}



