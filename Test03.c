#define _CRT_SECURE_NO_WARNINGS	//���windoows����strcpy����
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
	����C�����п⺯����ע�⣬strxxx�Ŀ⺯����������char*��
		
		strlen()����ȡ�ַ������ȣ�������������\0��
		memset(): ��ʽ��ָ���ַ�����
		strcpy(): �����ַ�����
		strncpy():���������ַ�����
		strcmpi():�Ƚ��ַ����Ƿ���ͬ��
		strcat(); �����ַ���

*/
int mainT03() {

	//�����ַ�����ȡ���ȡ�
	//testStringStrlen();

	//�ַ�����ʽ����
	//testMemset();

	//�����ַ���������
	//testStringcpy();

	//�ַ����Ƚϡ�
	//testStrComp();

	//�����ַ�������ȡ��ƴ�ӡ�
	//test_stropt();

	test_strcat();

	//�ַ�����Сдת����
	//test_tran();

	return 0;
}

/*
	���������ַ�����
*/
void test_strcat() {
	char c1[10] = { 'a','b','c' };
	char c2[8] = { 'd','e'};
	strcat(c1, c2);
	printf(" string= %s \n", c1);
}

/*
	�ַ���Сдת����
		tolower: �ַ���дתСд��
		toupper���ַ�Сдת��д��
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
	strstr����������һ���ַ�������ȡ�ַ�����
	strncpy����ͷ��ʼ�����������ַ�����
	strcat��ƴ���ַ�����

*/
void test_stropt() {
	//������ָ���ַ�������ȡ�ַ��� -- char*
	char* str = "darrenTest";
	char* inSt = "T";
	char* ind = strstr(str,inSt);
	printf("index= %s \n", ind);

	//�������Ϳ����������
	char strarr[] = "darrenTest";
	char c = 'T';
	char* ret = strchr(strarr, c);
	printf("ret= %s \n", ret);


	//��ͷ��ʼ��ȡָ���ַ�����
	char strn[20];
	strncpy(strn,str,5);
	printf("strn= %s \n", strn);

	//ƴ���ַ�����
	char strn2[15];
	char* sta = "aaa";
	char* stb = "bbb";
	char* stc = "ccc";

	//���ȿ�����һ��
	strcpy(strn2,sta);
	//Ȼ��Ϳ���ƴ����
	strcat(strn2, stb);
	strcat(strn2, stc);
	printf("strn2= %s \n", strn2);
}

/*
	�ַ����Ƚ��Ƿ���ͬ��
		1. ��ͬ����0��
		2. ����1��2�̣����ظ�����
		3. ����1��2��������������
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
	��ʽ��ָ���ڴ档
*/
void testMemset() {
	char str[20];
	//strcpy(str,"this.");
	//��ʽ���ַ���Ϊָ���ַ���
	memset(str,'1', 8);
	printf("str= %s \n", str);
}

/*
	�ַ���������
*/
void testStringcpy() {
	char str[20];
	char str2[40];

	//���Զ���ĩβ����\0
	strcpy(str,"darren....test...");
	printf("str=%s \n", str);

	strcpy(str2, str);
	printf("str2=%s \n", str2);
}

/*
	strlen����ȡ�ַ������ȡ�
	
	1. C�����У�û��String���ͣ��洢�ַ����ķ�ʽֻ�����֣������char*��
	2. char* ��ʼ�����ַ���������ĩβ�Զ���\0��
	3. strlen��ȡ�ĳ��ȣ�������ĩβ��\0��strlen���Ի�ȡchar*�ĳ��ȣ�Ҳ�ܻ�ȡchar[]�ĳ��ȣ�����Ĭ��ȥ��\0��

*/
void testStringStrlen() {
	
	//sizeof���ص��ǵ�ǰ����ռ�ÿռ�Ĵ�С������������˼����ַ�����
	//ע�⣬������ַ�������������\0��β��ʶ�ַ���Ϊ��󣬷����ӡ�������롣
	char cs[5] = { 'a','b','c','d' ,'\0'};
	printf("��ǰ�ַ���Ϊ��%s, size=%d \n", cs, sizeof(cs));

	//�õ�������ַ�������Ϊ4���ýӿڻ�Ĭ�ϼ�ȥĩβ��\0��
	int len = strlen(cs);
	printf("��ǰ�ַ�����ĳ���Ϊ len=%d \n", len);

	//��������sizeof�ж�ָ��Ĵ�С���õ�����ָ�뱾��Ĵ�С��ʹ��ָ���ʼ����Ĭ�ϻ���ĩβ���\0
	char* cc = "abc";
	printf("��ǰ�ַ���Ϊ��%s, size=%d \n", cc, sizeof(cc));
	//�õ�������3��strlen�õ��ĳ��Ȳ�����\0
	printf("��ǰ�ַ�ָ��ĳ���Ϊ len=%d \n", strlen(cc));


}
