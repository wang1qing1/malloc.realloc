#include<stdio.h>
#include<stdlib.h>
int main()
{
	int* p = (int*)calloc(10, sizeof(int));//������Դ��10��int�ͱ����Ŀռ䣻
	if (p == NULL)//�ж��Ƿ�����ʧ�ܣ�����ʧ�ܻ᷵�ؿ�ָ�루NULL��.
	{
		printf("����ʧ��\n");
		return 0;//�������ʧ�ܣ����ǳ����ֱ���˳�����Ϊ����ʧ��Ҳû�б�Ҫ���в�����
	}
	else//����ɹ���ʼʹ��
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));//�鿴��Ϊ��ֵ��ʱ������Ŀռ�����洢�ǲ���0��
			*(p + i) = i;//�����10���ռ䣬��ֵ0����9��
		}
		printf("\n");
		for (i = 0; i < 10; i++)
		{
			printf("%d ", *(p + i));//֤�����ǵ������Ѿ����ȥ����ӡ�����Ǵ��ȥ�����֡�
		}
	}
	printf("\n");
	//��ʱ���Ƿ����ڴ治��
	int* p1 = (int*)realloc(p, sizeof(int) * 15);//���ǽ�����ռ����󵽿��Դ��15��int�����֡�
	if (p1 == NULL)
	{
		printf("����ʧ��");
		return 0;
	}
	for (int i = 10; i < 15; i++)
	{
		*(p1 + i) = i;//��������Ŀռ丳ֵ10����14��
	}
	for (int i = 0; i < 15; i++)
	{
		printf("%d ", *(p1 + i));
	}
	free(p1);
	p1 = NULL;

	return 0;
}