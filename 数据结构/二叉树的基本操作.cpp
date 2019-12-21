#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char BT[1000];
int sum=0;

typedef struct node{ //树的结点
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

void inorder(BiTree root){//先序 
	if (root){
		printf("%c ", root->data);
		inorder(root->lchild);
		inorder(root->rchild);
	}
}

void Exchange(BiTree root){//交换 
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
    printf("请输入二叉树的结点个数:");
    int x;
    scanf("%d",&x);
    for(int i=1;i<=100;i++){
    	BT[i]='#';
	}
    for(int i=1;i<=x;i++){
    	int nbr;
    	char tmp;
    	printf("请输入序号(从1开始)、值(没有值请输入#):\n");
    	scanf("%d %c",&nbr,&tmp);
    	BT[nbr]=tmp;
    	if(sum<nbr) sum=nbr;
	}
	printf("\n");
	BiTNode *root;
	CreateBiTree(&root,1);
	printf("先序遍历结果：");
	inorder(root);
	printf("\n");
	Exchange(root);
	printf("交换后先序遍历结果：");
	inorder(root);
    return 0;
}
