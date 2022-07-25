#include<stdio.h>
#include <stdlib.h>

void test05t1();
void test05t2();
void test05t3();
void test05t4();

/*
	#define 和typedef的区别：
		#define:预编译器进行字符串替换，可用于替换任何字符。
		typedef:编译器执行，只能用于定义类型。
*/
int mainT06() {

	//使用typedef定义结构体和结构体指针。
	//test05t1();

	//typedef结构体申明时初始化。
	//test05t2();

	//测试枚举
	//test05t3();

	//测试预编译处理定义
	test05t4();

	return 0;
}


void test05t4() {
//调试代码。
#if 0
	printf("11111111。。。 \n");
#else
	printf("2222222。。。 \n");
#endif



}


//枚举实际上就是一种对值的约束规范,可以赋值基础类型。
enum ctype {
	RED = 1,
	YEL = 2,
	BLU	//自动赋值。
};

void test05t3() {
	enum ctype c1 = RED;
	enum ctype c2 = YEL;
	enum ctype c3 = BLU;
	//enum ctype c4 = 10; 

	//printf("red=%d, yel=%d, blu=%d, c4=%d  \n", c1,c2,c3,c4);
}

//定义TRUE字符实际对应的是1
#define TRUE  1
#define TE  'b'
#undef TE

//typedef可以在结构体申明时定义。
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

	//错误，这等于返回了指针本身的大小。
	printf("pd size = %d \n", sizeof(pd));

	pd pc = malloc(sizeof(p));
	pc->age = 101;
	pc->name = "darren123";
	printf("person name=%s, age=%d \n", pc->name, pc->age);
	free(pc);

	i iii = 100;



}
