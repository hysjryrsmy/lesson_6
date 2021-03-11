#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

//函数指针
//指针变量也是变量，变量是用来存储值的，所以指针变量也是存储值
/*
int g(int (*f1)(int), int (*f2)(int), int (*f3)(int), int x)
{
	if (x < 0)
	{
		return f1(x);
	}
	if (x < 100)
	{
		return f2(x);
	}
	return f3(x);
}
*/


/*
#define MAX_N 100
//二分查找用递归的方法
int binary_search(int* arr, int l, int r, int x)
{
	if (l > r)
		return -1;
	int mid = (l + r) >> 1;
	if (arr[mid] == x)
		return mid;
	if (arr[mid] < x)
		l = mid + 1;
	else
		r = mid - 1;
	return binary_search(arr, l, r, x);
}

//二分查找的方法
//指针
//int binary_search(int* arr, int n, int x)
//{
//	int head = 0, tail = n - 1, mid;
//	while (head <= tail)
//	{
//		mid = (head + tail) / 2;  //可以优化  : (head+tail) >> 1
//		if (arr[mid] == x)
//			return mid;
//		if (arr[mid] < x)
//			head = mid + 1;
//		else
//			tail = mid - 1;
//	}
//	return -1;
//}

int main()
{
	int arr[MAX_N + 5] = { 0 };
	int n, x;
	scanf_s("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf_s("%d", &arr[i]);
	}
	while (~scanf("%d", &x))
	{
		printf("%d\n", binary_search(arr, 0, n - 1, x));
	}

	return 0;
}
*/



//函数指针的应用
/*二分查找/ 折半查找：待查找区间具有单调性
三角形，五边形和六边形的数字由以下公式生成：

三角形	 	T = n（n +1）/ 2	 	    1，3，6，10，15，...
五角形	 	P = n（3 n -1）/ 2	 	1，5，12，22，35，...
六角形	 	H = n（2 n -1）	 	    1，6，15，28，45，...

可以验证T 285 = P 165 = H 143 = 40755。
查找下一个也是五边形和六边形的三角形。
*/
#include <inttypes.h>
int64_t Triangle(int64_t n)
{
	return n * (n + 1) >> 1;
}

int64_t Pentagonal(int64_t n)
{
	return n * (3 * n - 1) >> 1;
}

int64_t Hexagonal(int64_t n)
{
	return n * (2 * n - 1);
}

int64_t binary_search(int64_t(* arr)(int64_t), int64_t n, int64_t x)
{
	int64_t head = 1, tail = n, mid;
	while (head <= tail)
	{
		mid = (head + tail) >> 1;
		if (arr(mid) == x)
			return 0;
		if (arr(mid) < x)
			head = mid + 1;
		else
			tail = mid - 1;
	}
	return -1;
}
int main()
{
	int64_t n = 143;
	while (1)
	{
		n++;
		int64_t temp = Hexagonal(n);
		//if (!binary_search(Pentagonal, temp, temp)) continue;
		if (binary_search(Triangle, temp, temp))   continue;
		if (binary_search(Pentagonal, temp, temp)) continue;
		printf("%lld\n", temp);
		break;
		
	}

	return 0;
}