#define _CRT_SECURE_NO_WARNINGS	//规避windoows调用strcpy报错。
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void testStringStrlen();
void testStringcpy();
void testMemset();
void testStrComp();
void test_stropt();
void test_tran();
void test_strcat();

/*
	测试C语言中库函数。注意，strxxx的库函数不能用于char*。
		
		strlen()：获取字符串长度，不包括结束符\0。
		memset(): 格式化指定字符串。
		strcpy(): 拷贝字符串。
		strncpy():拷贝部分字符串。
		strcmpi():比较字符串是否相同。
		strcat(); 连接字符串

*/
int mainT03() {

	//测试字符串获取长度。
	//testStringStrlen();

	//字符串格式化。
	//testMemset();

	//测试字符串拷贝。
	//testStringcpy();

	//字符串比较。
	//testStrComp();

	//操作字符串，截取、拼接。
	//test_stropt();

	test_strcat();

	//字符串大小写转化。
	//test_tran();

	return 0;
}

/*
	连接两个字符串。
*/
void test_strcat() {
	char c1[10] = { 'a','b','c' };
	char c2[8] = { 'd','e'};
	strcat(c1, c2);
	printf(" string= %s \n", c1);
}

/*
	字符大小写转化。
		tolower: 字符大写转小写。
		toupper：字符小写转大写。
*/
void test_tran() {

	int i = 0;
	char str[] = "DARREN";

	while (str[i]){
		char cc = tolower(str[i]);
		printf("str = %c \n", cc);
		i++;
	}

	char strl[] = "asdfasdf";
	i = 0;
	while (strl[i]) {
		char bb = toupper(strl[i]);
		printf("strl = %c \n", bb);
		i++;
	}

}

/*
	strstr：索引到第一个字符后，向后截取字符串。
	strncpy：从头开始，拷贝部分字符串。
	strcat：拼接字符串。

*/
void test_stropt() {
	//索引到指定字符后，向后截取字符串 -- char*
	char* str = "darrenTest";
	char* inSt = "T";
	char* ind = strstr(str,inSt);
	printf("index= %s \n", ind);

	//数组类型可以用这个。
	char strarr[] = "darrenTest";
	char c = 'T';
	char* ret = strchr(strarr, c);
	printf("ret= %s \n", ret);


	//从头开始截取指定字符串。
	char strn[20];
	strncpy(strn,str,5);
	printf("strn= %s \n", strn);

	//拼接字符串。
	char strn2[15];
	char* sta = "aaa";
	char* stb = "bbb";
	char* stc = "ccc";

	//首先拷贝第一个
	strcpy(strn2,sta);
	//然后就可以拼接了
	strcat(strn2, stb);
	strcat(strn2, stc);
	printf("strn2= %s \n", strn2);
}

/*
	字符串比较是否相同。
		1. 相同返回0。
		2. 参数1比2短，返回负数。
		3. 参数1比2长，返回正数。
*/
void testStrComp() {
	char* str1 = "darren";
	char* str2 = "darren";
	char str3[] = {'a','a'};

	int res = strcmpi(str1,str2);
	printf("result = %d \n", res);

	res = strcmpi(str3, str2);
	printf("result = %d \n", res);
}

/*
	格式化指定内存。
*/
void testMemset() {
	char str[20];
	//strcpy(str,"this.");
	//格式化字符串为指定字符。
	memset(str,'1', 8);
	printf("str= %s \n", str);
}

/*
	字符串拷贝。
*/
void testStringcpy() {
	char str[20];
	char str2[40];

	//会自动在末尾加上\0
	strcpy(str,"darren....test...");
	printf("str=%s \n", str);

	strcpy(str2, str);
	printf("str2=%s \n", str2);
}

/*
	strlen：获取字符串长度。
	
	1. C语言中，没有String类型，存储字符串的方式只有两种：数组和char*。
	2. char* 初始化的字符串，会在末尾自动加\0。
	3. strlen获取的长度，不包括末尾的\0，strlen可以获取char*的长度，也能获取char[]的长度，都会默认去除\0。

*/
void testStringStrlen() {
	
	//sizeof返回的是当前对象占用空间的大小，而非里面存了几个字符串。
	//注意，如果是字符串，最后最好是\0结尾标识字符串为最后，否则打印会有乱码。
	char cs[5] = { 'a','b','c','d' ,'\0'};
	printf("当前字符串为：%s, size=%d \n", cs, sizeof(cs));

	//得到数组的字符串长度为4，该接口会默认减去末尾的\0。
	int len = strlen(cs);
	printf("当前字符数组的长度为 len=%d \n", len);

	//不可以用sizeof判断指针的大小，得到的是指针本身的大小。使用指针初始化，默认会在末尾添加\0
	char* cc = "abc";
	printf("当前字符串为：%s, size=%d \n", cc, sizeof(cc));
	//得到长度是3，strlen得到的长度不包括\0
	printf("当前字符指针的长度为 len=%d \n", strlen(cc));


}
