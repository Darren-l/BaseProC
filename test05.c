
#define _CRT_SECURE_NO_WARNINGS	//���windoows����strcpy����
#include<stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>

/*
	���Խṹ�塣
*/
void testStruct();
void testStruct2();
void test();
void test_struct3();
void test_struct4();
void test_struct5();

int mainT5() {

	//��򵥵Ľṹ����������ֵ��
	//testStruct();

	//�ṹ���а���char*
	//testStruct2();

	//�ṹ���еĽṹ�塣
	//test_struct3();

	//�ṹ��ָ��
	//test_struct4();

	//����char�ĸ�ֵ��
	//test();

	//�ṹ����Ϊ����������
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



//sizeof=24��
//��Ϊָ��ռ8,intռ4������ռ5����=17,�� 8����С����Ϊ24��
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
	�ṹ��ָ����ʶ����Ա�ķ�ʽ��->��

	�ṹ��sizeof�Ĵ�С:�ڴ�һҳ��ռ�ֽ����ı�����
*/
void test_struct4() {
	//ʹ�������Ķ���ֵָ�롣
	struct Person5* pp5 = &p5;
	pp5->age = 10;
	pp5->name = "darrenp5";
	strcpy(pp5->sex,"boy");
	//printf("pp5 name=%s, age=%d, sex=%s \n",pp5->name, pp5->age, pp5->sex);

	//ֱ��ʹ�ýṹ��ָ��
	struct Person5* ppp5;
	//
	ppp5 = malloc(sizeof(struct Person5));	//����24��8����С������
	printf("sizeof=%d \n", sizeof(struct Person5));

	//������ڴ���char*ָ��ģ�ʵ�ʸ�ֵ���ھ�̬����
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

	//�ṹ���еĽṹ������ʱ��ö���һ����Ա��
	//����ṹ���ڳ�Ա����ͬ����
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
	����ʱ�����Դ���ʼ����
*/
struct Person2 {
	char* name;
	int age;
	char sex[5];
}p2 = {"darren4",20,"boy"},p3
;

void testStruct2() {
	//������������
	struct Person2 person2;
	person2.name = "darren2";
	person2.age = 18;
	strcpy(person2.sex, "boy");
	printf("name=%s, age=%d, sex=%s \n", person2.name, person2.age, person2.sex);

	//��ӡ��ʼ����
	printf("name=%s, age=%d, sex=%s \n", p2.name, p2.age, p2.sex);

	//������ֵ��
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
	//�ṹ������� -- ��java��ͬ������Ҫnew�������ָ�룬��ô��Ҫmalloc��
	struct Person person;
	strcpy(person.name,"darren");
	person.age = 18;
	strcpy(person.sex,"boy");
	printf("name=%s, age=%d, sex=%s \n", person.name, person.age, person.sex);
}


/*
	����ֻ��char* ֧��ֱ�Ӹ�ֵ�ַ������൱��java�е�string��

	char[] ����Ҫ��strcpy���и�ֵ��

*/
void test() {
	char* name = "darren";
	printf("name= %s", name);

	//char*ָ�� ������Ҳ����ֱ�Ӹ�ֵ��
	char* name2;
	name2 = "darren2";
	printf("name= %s", name2);

	char* name3;
	name3 = malloc(10);//������ֵ������Ҫmalloc - free
	strcpy(name3, "darren3");
	printf("name= %s", name3);
	free(name3);
}
