#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int n,a[1000]={},b,m,o;
	char ab[100];
	printf("输入数组长度\n");
	scanf("%d",&n);
	printf("输入数据\n");
	for(int i=0;i<n;i++)
	{
		int flag;
		scanf("%s",ab);
		while(ab[0]<'0'||ab[0]>'9')
		{
			printf("请重新输入 ");
			scanf("%s",ab); 
		}
		
		
			for(int j=0;j<strlen(ab);j++)
			{
				a[i]*=10;
				a[i]+=(ab[j]-'0');
			}
		
		for(int j=0;j<i;j++)
		{
			if(a[i]<a[j])
			{
				b=a[j];
				a[j]=a[i];
				for(int k=i;k>j+1;k--)
				{
					a[k]=a[k-1];
				}
				a[j+1]=b;
				break;
			}
		}
	}
	printf("输入需要添加的数字个数\n");
	scanf("%d",&o);
	while(o!=0)
	{
		printf("输入需要插入的数字\n");
		scanf("%d",&m);
		for(int i=0;i<n;i++)
		{
			if(m<a[i])
			{
				b=a[i];
				a[i]=m;
				for(int k=n;k>i+1;k--)
				{
					a[k]=a[k-1];
				}
				a[i+1]=b;
				o--;
				n++;
				break;
			}
			if(i==n-1)
			{
				a[n]=m;
				o--;
				n++;
				break;
			}
		}	
	}
	printf("最后的数据：\n");
	for(int i=0;i<n;i++)
		printf("%d ",a[i]);
} 
