#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* p = (int*)calloc(10, sizeof(int));//申请可以存放10个int型变量的空间；
	if (p == NULL)//判断是否申请失败，申请失败会返回空指针（NULL）.
	{
		printf("申请失败\n");
		return 0;//如果申请失败，我们程序就直接退出，因为申请失败也没有必要进行操作；
	}
	else//申请成功开始使用
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));//查看在为赋值的时候申请的空间里面存储是不是0；
			*(p + i) = i;//申请的10个空间，赋值0——9；
		}
		printf("\n");
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));//证明我们的数字已经存进去，打印出我们存进去的数字。
		}
	}
	printf("\n");
	//这时我们发现内存不够
	int* p1 = (int*)realloc(p, sizeof(int) * 15);//我们将申请空间扩大到可以存放15个int型数字。
	if (p1 == NULL)
	{
		printf("申请失败");
		return 0;
	}
	for (int i = 10; i < 15; i++)
	{
		*(p1 + i) = i;//将新申请的空间赋值10——14；
	}
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", *(p1 + i));
	}
	free(p1);
	p1 = NULL;

	return 0;
}