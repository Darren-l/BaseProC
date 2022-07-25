
#define _CRT_SECURE_NO_WARNINGS	//规避windoows调用strcpy报错。
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/*
	测试结构体。
*/
void testStruct();
void testStruct2();
void test();
void test_struct3();
void test_struct4();
void test_struct5();

int mainT5() {

	//最简单的结构体声明及赋值。
	//testStruct();

	//结构体中包含char*
	//testStruct2();

	//结构体中的结构体。
	//test_struct3();

	//结构体指针
	//test_struct4();

	//测试char的赋值。
	//test();

	//结构体作为函数参数。
	test_struct5();

	return 0;
}


struct Person6 {
	char* name;
	int age;
	char sex[5];
}p66;

void struct5tt(struct Person6* p) {
	printf("struct5tt name= %s \n", p->name);
}

void struct5tt6(struct Person6 p) {
	printf("struct5tt name= %s \n", p.name);
}

void test_struct5() {
	p66.name = "darren";
	p66.age = 99;
	struct5tt(&p66);
	struct5tt6(p66);
}



//sizeof=24。
//因为指针占8,int占4，数组占5，总=17,而 8的最小倍数为24。
struct Person5 {
	char* name;
	int age;
	char sex[5];
}p5;

struct Ptest {
	char* a;
	int age;
	char sex[24];
};
/*
	结构体指针访问对象成员的方式是->。

	结构体sizeof的大小:内存一页所占字节数的倍数。
*/
void test_struct4() {
	//使用声明的对象赋值指针。
	struct Person5* pp5 = &p5;
	pp5->age = 10;
	pp5->name = "darrenp5";
	strcpy(pp5->sex,"boy");
	//printf("pp5 name=%s, age=%d, sex=%s \n",pp5->name, pp5->age, pp5->sex);

	//直接使用结构体指针
	struct Person5* ppp5;
	//
	ppp5 = malloc(sizeof(struct Person5));	//返回24，8的最小倍数。
	printf("sizeof=%d \n", sizeof(struct Person5));

	//分配的内存是char*指针的，实际赋值是在静态区。
	ppp5->name = "darren111111111111111111111";
	ppp5->age = 100;
	strcpy(ppp5->sex, "boy123");
	printf("pp5 name=%s, age=%d, sex=%s \n", ppp5->name, ppp5->age, ppp5->sex);
	free(ppp5);
	ppp5 = NULL;

	printf("sizeof=%d \n", sizeof(struct Ptest));

}

struct Person3 {
	char* name;
	int age;

	//结构体中的结构体申明时最好定义一个成员，
	//否则结构体内成员不能同名。
	struct Son {
		char* name;
		int age;
	}son;

	struct Son son2;
};

void test_struct3() {

	struct Person3 p;
	p.name = "darren123";
	p.age = 15;
	p.son2.name = "nuomi";
	p.son2.age = 4;

	printf("person3 name=%s, age=%d, son_name=%s, son_age=%d \n", \
		p.name,p.age,p.son2.name,p.son2.age);
}

/*
	申明时，可以带初始化。
*/
struct Person2 {
	char* name;
	int age;
	char sex[5];
}p2 = {"darren4",20,"boy"},p3
;

void testStruct2() {
	//方法中申明。
	struct Person2 person2;
	person2.name = "darren2";
	person2.age = 18;
	strcpy(person2.sex, "boy");
	printf("name=%s, age=%d, sex=%s \n", person2.name, person2.age, person2.sex);

	//打印初始化。
	printf("name=%s, age=%d, sex=%s \n", p2.name, p2.age, p2.sex);

	//声明后赋值。
	p3.name = "darren5";
	p3.age = 18;
	strcpy(p3.sex, "boy");
	printf("name=%s, age=%d, sex=%s \n", p3.name, p3.age, p3.sex);
}


struct Person {
	char name[10];
	int age;
	char sex[10];
};

void testStruct() {
	//结构体的声明 -- 与java不同，不需要new。如果是指针，那么需要malloc。
	struct Person person;
	strcpy(person.name,"darren");
	person.age = 18;
	strcpy(person.sex,"boy");
	printf("name=%s, age=%d, sex=%s \n", person.name, person.age, person.sex);
}


/*
	仅仅只有char* 支持直接赋值字符串。相当于java中的string。

	char[] 必须要用strcpy进行赋值。

*/
void test() {
	char* name = "darren";
	printf("name= %s", name);

	//char*指针 声明后也可以直接赋值。
	char* name2;
	name2 = "darren2";
	printf("name= %s", name2);

	char* name3;
	name3 = malloc(10);//声明后赋值，必须要malloc - free
	strcpy(name3, "darren3");
	printf("name= %s", name3);
	free(name3);
}
