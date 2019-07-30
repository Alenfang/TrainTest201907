// algorithm2.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"iostream"
using namespace std;

void swap(int &a, int &b);
void print(int *p, int nLen);

void Bubble_sort(int * p, int nNum);
void Select_srot(int *p, int nNum);
void Insert_sort(int *p, int nNum);
int Quick_srot_front(int low, int high, int *p);
void Quick_srot(int low, int high, int *p);
void Insrtsort(int *p, int n, int dk);
void ShellSort(int *p, int n);

int main()
{
	int n = 0;
	int nLen = 0;
	int nszBuf[] = { 55, 82, 28, 19, 37, 73, 91, 46, 64 };
	
	nLen = sizeof(nszBuf) / sizeof(int);//计算数组的长度

	print(nszBuf, nLen);
	ShellSort(nszBuf, nLen);
	print(nszBuf, nLen);
    return 0;
}

void swap(int &a, int &b) // 用于交换两个int类型的元素
{
	int nTemp = 0;

	nTemp = a;
	a = b;
	b = nTemp;
}

void print(int *p, int nLen)
{
	int i = 0;

	if (NULL != p)
	{
		for (i = 0; i < nLen; i++)      
		{
			cout << *(p++) << "    ";     //打印显示数组
		}
		cout << endl;
	}	
}

void Bubble_sort(int *p, int nLen)
{
	int i = 0;
	int j = 0;
	
	for (i = 0; i < nLen - 1; i++)
	{
		for (j = 0; j < nLen - i - 1; j++)
		{
			if (p[j] > p[j + 1])
			{
				swap(p[j],p[j+1]);    // 将最大值沉降
			}
		}
	}
}

void Select_srot(int *p, int nLen)
{
	int i = 0;
	int j = 0;

	if (NULL != p)
	{
		for (i = 0; i < nLen - 1; i++) // 通过i的自增，持续寻找当前序列中的最小值
		{
			for (j = i + 1; j < nLen; j++)
			{
				if (p[i] > p[j])
				{
					swap(p[i],p[j]); // 将最小值放在当前序列首元素的位置
				}
			}
		}
	}
}

void Insert_sort(int *p, int nLen)
{
	int i = 0;
	int j = 0;
	int nTemp = 0;

	if (NULL != p)
	{
		for (i = 1; i < nLen - 1; i++)
		{
			nTemp = p[i];        //保存第i值，并将i处的位置空出以供插入位置前的数据的后移

			for(j = i-1; j >= 0 && nTemp <= p[j]; j--) //J的值代指与nTemp比较的值的位置
			{
				p[j+1] = p[j];          // 插入位置前的数据的后移
			}
			p[j+1] = nTemp;              //将插入值插入到j的下一个值
		}
	}
}

int Quick_srot_front(int low, int high, int *p)
{
	while (low < high)
	{
		while (low < high && p[high] > p[low])  
		{
			high--;            //在p[high] > p[low]时，指向高地址位的指针向低地址位偏移
		}
		swap(p[high],p[low]);                 //通过交换使满足p[high] > p[low]
		while (low < high && p[low] < p[high])
		{
			low++;            //在p[low] < p[high]时，指向低地址位的指针向高地址位偏移
		}
		swap(p[high],p[low]);
	}

	return low;
}

void Quick_srot(int low, int high, int *p)
{
	int n = 0;

	n = Quick_srot_front(low, high, p);
	
	if (low < high)
	{
		Quick_srot(low, n-1, p);
		Quick_srot(n+1, high,p);
	}
}

void Insrtsort(int *p, int n, int dk)
{
	int i = 0;
	int j = 0;

	for (i = dk; i < n; i++)       //i处的值为后区间的首元素，控制它更方便控制循环的复杂度
	{
		j = i - dk;                //前区间的首元素

		while (p[i] < p[j])
		{
			swap(p[i],p[j]);       //区间相对位置有序   
			j -= dk;               //同简单插入的排序思想一致
		}
	}
}

void ShellSort(int *p, int n)
{
	int dk = 0;

	dk = n;                        
	while (dk >= 1)
	{
		dk /= 2;                             //分段的区间为dk/2
		Insrtsort(p, n, dk);                 //根据区间排序
	}
}
