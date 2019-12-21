#include <stdio.h>
#include <stdlib.h>

typedef struct TreeNode{
    char ch;
    struct TreeNode *lchild, *rchild;
}Tree, *PTree;//�������ڵ�Ľṹ��

void createBiTree(PTree *p)//����������
{
    char ch;
    scanf("%c", &ch);
    getchar();//��ʱ%c��ȡ���ǵ����ַ����������Ǹ�getchar������һ��
    if(ch == '#')
         *p = NULL;
    else
    {
        *p = (PTree)malloc(sizeof(Tree));
        (*p) -> ch = ch;
        printf("������%c��������\n", ch);
        createBiTree(&(*p) -> lchild);
        printf("������%c��������\n", ch);
        createBiTree(&(*p) -> rchild);
    }

}
void preOrderTraverse(PTree p)//ǰ�����
{
    if(p == NULL)
        return ;
    printf("%c ", p -> ch);
    preOrderTraverse(p -> lchild);
    preOrderTraverse(p -> rchild);
}
void InOrderTraverse(PTree p)//�������
{
    if(p == NULL)
        return;
    InOrderTraverse(p -> lchild);
    printf("%c ", p -> ch);
    InOrderTraverse(p -> rchild);
}
void BackOrderTraverse(PTree p)//��������
{
    if(p == NULL)
        return ;
    BackOrderTraverse(p -> lchild);
    BackOrderTraverse(p -> rchild);
    printf("%c ", p -> ch);
}
int main()
{
    PTree pt;
    createBiTree(&pt);
    preOrderTraverse(pt);
    printf("\n");
    InOrderTraverse(pt);
    printf("\n");
    BackOrderTraverse(pt);
    printf("\n");
    return 0;
}
