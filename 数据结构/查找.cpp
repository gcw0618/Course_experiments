#include<stdio.h>
int main(){
	int choose,n,fin;
	int num[200];
	printf("��ѡ��:\n");
	printf("1��һ�������������:\n");
	printf("2��һ�����������������С����:\n");
	scanf("%d",&choose); 
	int flag=1;
	if(choose==1){
		while(flag==1){	
			printf("�������������ĸ���:\n");
			scanf("%d",&n);
			printf("������������:\n");
			for(int i=1;i<=n;i++){
				scanf("%d",&num[i]);
			}
			printf("������Ҫ���ҵ�������:\n");
			scanf("%d",&fin);
			for(int i=1;i<=n;i++){
				if(num[i]==fin){
					printf("�Ѳ鵽�������ڵ�%dλ",i);
					flag=0;
					return 0;
				}
			}
			printf("δ�鵽����!\n");
		}
	}
	else if(choose==2){
		while(flag==1){	
			printf("�������������ĸ���:\n");
			scanf("%d",&n);
			printf("����������������С��������:\n");
			for(int i=1;i<=n;i++){
				scanf("%d",&num[i]);
			}
			printf("������Ҫ���ҵ�������:\n");
			scanf("%d",&fin);
			int l=1,r=n;
			int mid;
			while(l<=r){
				mid=(l+r)/2;
				if(num[mid]==fin){
					printf("�Ѳ鵽�������ڵ�%dλ",mid);
					flag=0;
					return 0;
				}
				else if(num[mid]>fin){
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			printf("δ�鵽����!\n");
		}
	}
	return 0;
} 
