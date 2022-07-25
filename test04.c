#define _CRT_SECURE_NO_WARNINGS	//���windoows����strcpy����
#include <stdio.h>
#include <malloc.h>
#include <string.h>


void test04t1();
void test04t2();

/*
	ָ�벹�䡣
	1. malloc()��relloc()��free()������ʹ�á�
	2. char*�������ԡ�

*/
int mainT4() {

	//����malloc��realloc��free������
	test04t1();

	//ָ�벹��
	test04t2();

	return 0;
}

/*
	ָ�벹�䡣
*/
void test04t2() {

	//���ڻ������ͣ����ָ�ֵ���淶��ָ��������������ַ�ġ�
	int* i = 100;

	//����char����ָ�������ô��ֵ�������˵�Ƚ����⣬�������������⴦��
	char* c = "abc";
	//������ַ�����������Ǹ������׸�Ԫ�صĵ�ַ��ִ��ʱ���Զ���ȡ�����ֵ��
	//ֱ������\0�������*c�������һ��Ԫ�ص����ݡ�
	printf("c=%s,  ccc=%c \n",c, *c);

	//C������û���ַ�������,Ҫô����װ��Ҫôָ��װ��
	char* str;
	str = (char*)malloc(5);	//ָ��Ļ���Ҫ����ؼ�
	strcpy(str,"abcd");	//charָ�벻����ֱ�Ӹ�ֵ����Ҫ����strcpy��
	printf("str=%s \n", str);

}

/*
	����ָ�룬��νָ��ָ��a��ַ��ʵ���Ͼ���ָ������д洢��a��ַ��

	p = malloc(size);
		malloc()�������ڶѿռ�����һ���ڴ�,������ַ��ֵ��pָ�����

	free(p); p=NULL
		�ú����������p��֮ǰ����ĵ�ַ�����ǽ�p�еĵ�ַ���Ϊ��Ч��ַ��
	�������޷���ȡֵ��Ϊ�˷����ж�p�Ƿ��ÿգ�free��һ��Ὣp��ַ��ֵ
	NULL��

	p = realloc()
		�ú������������һ��malloc�ĵ�ַ������ֻ�Ƕ�ָ���С�������ݡ�

	�ܽ᣺
		malloc��free�ɶԳ��֣�����Ҫ�ͷ��ڴ棬��free����Ҫ��ָ����и�ֵNULL��

*/
void test04t1() {
	//ָ�����Ҫô��ʼ��ʱ��Ҫ��ֵ���������Ҫmalloc����ռ䡣
	int* p_int;
	//*p_int = 3;//���󣬲�����ֱ�Ӹ�ֵ��p_int��ǰΪ��ָ��

	//�ȷ����ڴ��ַ�洢��p_intָ����
	p_int = malloc(sizeof(int));
	*p_int = 3;//��ֵ��

	printf("pint=%d  pintAddr=%p \n", *p_int, p_int);

	//�ͷ�ָ��洢�ĵ�ַ
	//��ʱ�޷��ٷ���*p_int
	free(p_int);
	//ע��free���Ὣpָ���еĵ�ַ��0����ַ��Ȼ���ڣ�ֻ�����洢�ĵ�ַʧЧ��
	p_int = NULL; //����Ҫ�ֶ���ָ���д洢�ĵ�ַ���
	//��ֵ�󲻿����ٴ�ӡ
	//printf("free pint=%d, pintAddr=%p\n",*p_int, p_int);

	printf("################realloc() test..... \n");

	// reallocͨ����������֮ǰ������ڴ棬ָ���ַ���䡣
	char* str;
	str = (char*)malloc(5);
	strcpy(str,"absd");
	printf("String = %s,  Address = %p\n", str, str);

	str = (char*)realloc(str, 25);
	strcat(str, "eeeeeee");
	printf("String = %s,  Address = %p\n", str, str);
	free(str);

}