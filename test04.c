#define _CRT_SECURE_NO_WARNINGS	//规避windoows调用strcpy报错。
#include <stdio.h>
#include <malloc.h>
#include <string.h>


void test04t1();
void test04t2();

/*
	指针补充。
	1. malloc()、relloc()和free()函数的使用。
	2. char*的特殊性。

*/
int mainT4() {

	//测试malloc、realloc和free函数。
	test04t1();

	//指针补充
	test04t2();

	return 0;
}

/*
	指针补充。
*/
void test04t2() {

	//对于基本类型，这种赋值不规范，指针是用来存对象地址的。
	int* i = 100;

	//对于char类型指针可以这么赋值，相对来说比较特殊，编译器会做特殊处理。
	char* c = "abc";
	//如果是字符串，则输出是给的是首个元素的地址，执行时会自动获取后面的值，
	//直到遇到\0后结束。*c会输出第一个元素的内容。
	printf("c=%s,  ccc=%c \n",c, *c);

	//C语言中没有字符串类型,要么数组装，要么指针装。
	char* str;
	str = (char*)malloc(5);	//指针的话需要申请控件
	strcpy(str,"abcd");	//char指针不可以直接赋值，需要借助strcpy。
	printf("str=%s \n", str);

}

/*
	测试指针，所谓指针指向a地址，实际上就是指针对象中存储了a地址。

	p = malloc(size);
		malloc()函数：在堆空间申请一块内存,并将地址赋值给p指针对象。

	free(p); p=NULL
		该函数不会清除p中之前申请的地址，而是将p中的地址标记为无效地址，
	接下来无法获取值。为了方便判断p是否被置空，free后一般会将p地址赋值
	NULL。

	p = realloc()
		该函数不会更改上一次malloc的地址，仅仅只是对指针大小进行扩容。

	总结：
		malloc和free成对出现，必须要释放内存，且free后还需要对指针进行赋值NULL。

*/
void test04t1() {
	//指针变量要么初始化时就要赋值，否则就需要malloc申请空间。
	int* p_int;
	//*p_int = 3;//错误，不允许直接赋值，p_int当前为空指针

	//先分配内存地址存储在p_int指针中
	p_int = malloc(sizeof(int));
	*p_int = 3;//后赋值。

	printf("pint=%d  pintAddr=%p \n", *p_int, p_int);

	//释放指针存储的地址
	//此时无法再访问*p_int
	free(p_int);
	//注意free不会将p指针中的地址清0，地址仍然存在，只不过存储的地址失效。
	p_int = NULL; //所以要手动将指针中存储的地址清空
	//赋值后不可以再打印
	//printf("free pint=%d, pintAddr=%p\n",*p_int, p_int);

	printf("################realloc() test..... \n");

	// realloc通常用于扩容之前申请的内存，指针地址不变。
	char* str;
	str = (char*)malloc(5);
	strcpy(str,"absd");
	printf("String = %s,  Address = %p\n", str, str);

	str = (char*)realloc(str, 25);
	strcat(str, "eeeeeee");
	printf("String = %s,  Address = %p\n", str, str);
	free(str);

}