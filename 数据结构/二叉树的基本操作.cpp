#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char BT[1000];
int sum=0;

typedef struct node{ //���Ľ��
	char data;
	struct node *lchild;
	struct node *rchild;
}BiTNode,*BiTree;

void CreateBiTree(BiTree *root,int k){
    if(k>sum){
    	*root=NULL;
	}
	else{
		*root=(BiTree)malloc(sizeof(BiTNode));
		(*root)->data=BT[k];
		CreateBiTree(&((* root)->lchild),(2*k));
		CreateBiTree(&((* root)->rchild),(2*k+1));
	}
}

void inorder(BiTree root){//���� 
	if (root){
		printf("%c ", root->data);
		inorder(root->lchild);
		inorder(root->rchild);
	}
}

void Exchange(BiTree root){//���� 
	if(root->lchild==NULL&&root->rchild==NULL)
		;
	else{
		BiTree temp=root->lchild;
		root->lchild=root->rchild;
		root->rchild=temp;
	}
	if(root->lchild)    		
		Exchange(root->lchild);
	if(root->rchild)
		Exchange(root->rchild);
}

int main(){
    printf("������������Ľ�����:");
    int x;
    scanf("%d",&x);
    for(int i=1;i<=100;i++){
    	BT[i]='#';
	}
    for(int i=1;i<=x;i++){
    	int nbr;
    	char tmp;
    	printf("���������(��1��ʼ)��ֵ(û��ֵ������#):\n");
    	scanf("%d %c",&nbr,&tmp);
    	BT[nbr]=tmp;
    	if(sum<nbr) sum=nbr;
	}
	printf("\n");
	BiTNode *root;
	CreateBiTree(&root,1);
	printf("������������");
	inorder(root);
	printf("\n");
	Exchange(root);
	printf("������������������");
	inorder(root);
    return 0;
}
