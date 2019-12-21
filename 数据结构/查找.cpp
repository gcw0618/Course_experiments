#include<stdio.h>
int main(){
	int choose,n,fin;
	int num[200];
	printf("请选择:\n");
	printf("1、一组无序的整型数:\n");
	printf("2、一组有序的整型数（从小到大）:\n");
	scanf("%d",&choose); 
	int flag=1;
	if(choose==1){
		while(flag==1){	
			printf("请输入整型数的个数:\n");
			scanf("%d",&n);
			printf("请输入整形数:\n");
			for(int i=1;i<=n;i++){
				scanf("%d",&num[i]);
			}
			printf("请输入要查找的整形数:\n");
			scanf("%d",&fin);
			for(int i=1;i<=n;i++){
				if(num[i]==fin){
					printf("已查到该数，在第%d位",i);
					flag=0;
					return 0;
				}
			}
			printf("未查到该数!\n");
		}
	}
	else if(choose==2){
		while(flag==1){	
			printf("请输入整型数的个数:\n");
			scanf("%d",&n);
			printf("请输入整形数（从小到大排序）:\n");
			for(int i=1;i<=n;i++){
				scanf("%d",&num[i]);
			}
			printf("请输入要查找的整形数:\n");
			scanf("%d",&fin);
			int l=1,r=n;
			int mid;
			while(l<=r){
				mid=(l+r)/2;
				if(num[mid]==fin){
					printf("已查到该数，在第%d位",mid);
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
			printf("未查到该数!\n");
		}
	}
	return 0;
} 
