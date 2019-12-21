#include <stdio.h>
#include <stdlib.h>
#define N 100
void charu();
void xuanze();
void dui();
void shuchu();

int s[1000];
int n;

void HeapSort(){
	int end=n;     
	while(end!=1)  {
		while(1){
			int pa=end/2; 
			int tag=0;   
			while(pa>0){
				if(s[pa]<s[2*pa])  {
					tag=1;
					int temp=s[pa];
					s[pa]=s[2*pa];
					s[2*pa]=temp;
				}
				if((2*pa+1<=end)&&s[pa]<s[2*pa+1]){
					tag=1;
					int temp=s[pa];
					s[pa]=s[2*pa+1];
					s[2*pa+1]=temp;
				}
				pa--; 
			}
			if(tag==0){
				int t=s[1];
				s[1]=s[end];
				s[end]=t;
				break;
			}
		}
		end--; 
	}
	printf("������������Ϊ��\n");
	for(int i=1;i<=n;i++)
		printf("%d ",s[i]);
	printf("\n");
}

void charu(){
	int i,j,temp;
	for(i=2;i<=n;i++){
		j=i;
		temp=s[i];
		while(j>1&&temp<s[j-1]){
			s[j]=s[j-1];
			j--;
		}
		s[j]=temp;
	}
	shuchu() ;
	return;
}

void xuanze(){
	for(int i=1;i<=n;i++){
		int temp=s[i];
		int minm=1000000;
		int wei=i;
		for(int j=i+1;j<=n;j++){
			if(s[j]<minm){
				minm=s[j];
				wei=j;
			}
		}
		s[i]=s[wei];
		s[wei]=temp;
	}
	shuchu();
	return;
}

void shuchu(){
	printf("������Ϊ��");
	for(int i=1;i<=n;i++){
		printf("%d ",s[i]);
	}
	printf("\n");
	return;
}

int main(){
	int choose;
	printf("����������������");
	scanf("%d",&n);
	printf("������������");
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
	}
	printf("��ѡ������\n");
	printf("1��ֱ�Ӳ�������\n");
	printf("2����ѡ������\n");
	printf("3���������㷨��С��������\n");
	scanf("%d",&choose);
	if(choose==1) charu();
	else if(choose==2) xuanze();
	else if(choose==3){
		HeapSort();
	}
	return 0;
} 
/*
8
49 38 65 97 76 13 27 49
*/
