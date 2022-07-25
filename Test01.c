#include <stdio.h>

/*
	总结：
		1. C语言的报错位置通常是准确的，但错误信息提示，可能不会向java那么准确。
		2. sizeof算的是当前对象占用内存空间的字节数。
*/

//若方法写在main后面，则需要在mian前面声明。
void test01();
void test02();
void test02_attach(int* arg);
void test03();
void test04();
void test05();

int mainT01() {
	//C基本数据类型及打印方式。
	//test01();

	//C语言的指针。
	//test02();

	//多级指针。
	//test03();

	//数组声明及遍历。
	//test04();

	//test05();

	return 0;
}

/*
	存储字符串两种方式：
		1. 字符数组，可以修改。
		2. 字符指针，相当于final，处于静态去，不可被修改，可以理解为只读。
	如果字符指针存储的值需要被修改，那么需要拷贝出栈再操作。
*/
void test05() {
	//申明char型数组，可以使用下标访问，并修改。
	char arr[] = { 'a','b','c','d','\0'};
	arr[2] = 'e';
	//打印字符串，需要传首地址。
	printf("arr=%s \n", arr);
	//如果是获取数组指定下标，可以有两种方式。
	printf("arr ====  arr[2]=%c,  arrp2=%c \n" , arr[2], *(arr + 2));

	//字符指针初始化的值，处于静态区，相当于final属性，不能被修改。
	char* aap = "abcd";
	printf("aap=%s \n", aap);
	printf("aap ====  aap[2]=%c,  aap=%c \n", aap[2], *(aap + 2));
	
	//如果声明是指针，获取可以用数组的方式，但是修改值不可以这么做。
	//aap[2] = 'z';//指针声明的字符串属于静态区，不可以直接修改会报错。
	//*(aap + 2) = 'z';	//也不可以使用指针的方式修改。
	//printf("aap ====  aap[2]=%c,  aap=%c \n", aap[2], *(aap + 2));

}

/*
	数组的声明、值获取及遍历。
	1. C语言数组规定的声明有点特殊，通常int[] args应该才更符合逻辑，但实际
	是int args[];
	2. 数组的指针仅仅只需要将指针指向第一个元素即可，因为数组的元素在内存
	地址上是连续的，可以直接通过p+n来获取后面的元素。
	3. 数组一旦初始化了大小，就不可以再改变，所以通常可以申请大一点，预估值*2.5。
*/
void test04() {
	//数组声明时需要给定大小，如果做了初始化则可省略，但大小不可变了。
	int args[] = {1,2,3,4,5};

	//C语言中如果想获取当前数组的大小，可以通过sizeof。
	printf("args的元素个数为：%d \n", sizeof(args)/sizeof(int));

	//获取指定位置的元素。
	printf("args的第三个元素args3=%d \n", args[2]);

	//遍历方式。
	for (int i=0; i < 5; i++) {
		printf("遍历数组元素第%d个元素，值为%d \n",i, args[i]);
	}

	//由于数组在地址上是连续的，数组的指针仅需要将第一个元素赋值给指针即可。
	int* p = args;
	//遍历的时候地址+1即可。
	for (int i = 0; i < 5; i++) {
		printf("###指针 遍历数组元素第%d个元素，值为%d \n", i, *(p+i));
	}
}

/*
	多级指针。
	1. 指针本来也有地址，多级指针实际上存储的就是它上一级指针的地址。
	2. 针对与int* ip的声明，一定要清楚int* p和*p的区别，否则容易被指针*符号混淆。
	3. N级指针通常用于N-1级指针的初始化。
	4. 指针sizeof与类型无关，都是固定4个字节。
*/
void test03() {
	int i = 10;
	//一级指针ip存储的是i的地址。
	int* ip = &i;
	//二级指针存储的是ip指针的地址。
	int** ipp = &ip;
	//三级指针存储的是ipp指针的地址。
	int*** ippp = &ipp;
	printf("i=%d, ip=%d, ipp=%d, ippp=%d \n",i,*ip,**ipp,***ippp);

	//不要把高级指针赋值给低级指针，虽然不会报错，但无法访问其他层级所指向的值。
	int* ipppp = &ippp;
	printf("ipppp = %d \n",*ipppp);//仅仅能输出ippp地址存储的对象，无法继续向上。

	printf("指针本身的大小与类别无关，都是4字节。p_size=%d" + sizeof(ip));
}

/*
	演示指针的使用。
	1. 每个对象存储在内存中都有地址，&就是获取地址的符号。
	2. * 和 & 可以理解为相对的，*为获取地址对应存储的对象。
	3. 注意理解int* 它是一种特殊的类型 ---- 指针类型。
*/
void test02() {
	int i = 10;
	//&为取对象的地址，*代表当前地址存储的对象。
	//%p用于输出对象地址值。
	int* b = &i;
	printf("i=%d, b=%d \n，p=%p", i, *b, &i);
	//使用*或取地址对应对象后，修改的是原值。
	*b = 20;
	printf("i=%d, b=%d \n", i, *b);
	//传递指针，修改b地址对应对象的值。
	test02_attach(&i);
	printf("i=%d, b=%d \n", i, *b);

}

/*
	接受一个int型的指针，非指针类型都为形参。

	如果需要修改参数的值，则需要传指针类型将对象的地址传进来，
	这样可以使用*获取到地址对应的对象，然后进行修改。
*/
void test02_attach(int* arg) {
	*arg = 30;
}

/*
	演示基本类型的打印方式。
*/
void test01() {
	int i = 10;
	long l = 100;
	short s = 8;
	float f = 20.1;
	double d = 21.11;
	char c = 'A';
	//C语言没有String类型，使用字符指针类型代替。
	char* str = "darren";
	
	//C使用printf输出，必须以函数方式输出，%d为占位符
	printf("依次打印值 var_int=%d\n var_long=%d\n var_short=%d\n var_float=%f\n \
	var_double=%lf\n var_char=%c\n var_string=%s\n", i, l,\
	s, f, d, c, str);

	//sizeof函数可输出参数的字节大小
	printf("###输出i的字节大小：%d", sizeof(i));

}