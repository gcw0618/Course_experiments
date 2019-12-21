#include <stdio.h>
#include <stdlib.h>

char a[20000],b[20000];

struct node{
    char n;
    struct node *pNext;
}; 

int main(){
    struct node *pHead = NULL, *pEnd = NULL, *pNode = NULL;
    char i;
    printf("请输入数据(回车结束):\n");
    do{
        scanf("%c",&i);
        pNode = (struct node *)malloc(sizeof(struct node));
        if(pNode != NULL){
            pNode -> n = i;
            pNode -> pNext = NULL;
            if(pHead == NULL){
                pHead = pNode;
                pEnd = pNode;
            }
            else{
                pEnd -> pNext = pNode;
                pEnd = pNode;
            }
        }
    }while(getchar()!='\n');
    pNode = pHead; 
    int flag=1,a1=0,b1=0; 
    while(pNode != NULL){
    	if(flag==1){
    		a[a1]=pNode->n;
        	flag=0;
        	a1++;
		}
		else{
			b[b1]=pNode->n;
        	flag=1;
        	b1++;
		}
        pNode = pNode -> pNext;
	}
    pNode = pHead;
    printf("输入的数据:\n");
    while(pNode != NULL){
        printf("%c ", pNode -> n);
        pHead = pNode;
        pNode = pNode -> pNext;
        free(pHead);
    }
    printf("\n");
	printf("奇数结点:\n");
	for(int i=0;i<a1;i++){
		printf("%c ",a[i]);
	}
	printf("\n");
	printf("偶数结点:\n");
	for(int i=0;i<b1;i++){
		printf("%c ",b[i]);
	}
    return 0;
}
