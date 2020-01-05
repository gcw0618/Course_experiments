#include <bits/stdc++.h>
using namespace std;
 
bool Safe;
int M, C, K, B;
int st[100][100][2]; // ���״̬
int add[][2] = {1,1, 0,2, 2,0, 1,0, 0,1}; //��������
 
struct Node {
    int pid; //���ױ��
    int id; // ��ţ���¼·��
    int m;  // ����޵�ʿ����
    int c;  // ���Ұ������
    int b;  // ��ߴ�ֻ����
    Node() {}
    Node(int _m, int _c, int _b, int _id, int _pid = -1) {
        m = _m; c = _c; b = _b; id = _id; pid = _pid;
    }
};
 
struct AstarNode {
    int f; // ����ֵ
    int g; // ��ǰ�ѻ�������
    Node node;
    AstarNode() {}
    AstarNode(int _g, Node _node) {
        node = _node;
        g = _g;
        f = g + h();
    }
    bool operator < (const AstarNode& a) const {
        return f > a.f;
    }
    int h() { //�����������ӵ�ǰ״̬��������״̬��Ҫ�����ٴ���
        return node.m + node.c - K * node.b;
    }
};
 
// �ж�״̬�Ƿ�Ϸ�
bool OK(int m, int c, int b) {
    if(m > M || m < 0 || c > C || c < 0 || (m != 0 && m < c) || (M-m != 0 && (M-m) < (C-c))) return false;
    if(st[m][c][b] != -1) return false;
    return true;
}
 
vector<Node> PathNode;
priority_queue<AstarNode> Q;
 
void printPath(int id) {
    if(id != -1) {
        printPath(PathNode[id].pid);
        if(PathNode[id].pid == -1) printf("��ʼ״̬: ");
        else if(PathNode[id].m == 0 && PathNode[id].c == 0) printf("��ֹ״̬: ");
        else printf("    ----> ");
        printf("(%d, %d, %d)\n", PathNode[id].m, PathNode[id].c, PathNode[id].b);
    }
}
 
void Astar() {
    while(!Q.empty()) Q.pop();
    PathNode.clear();
 
    memset(st, -1, sizeof(st));
    PathNode.push_back(Node(M, C, B, 0, -1));
    Q.push(AstarNode(0, PathNode[0]));
    st[M][C][B] = 0;
 
    int m, c, b, flag, id;
    while(!Q.empty()) {
        AstarNode as = Q.top(); Q.pop();
        //printf("----%d %d %d %d %d----\n", as.f, as.g, as.node.m, as.node.c, as.node.b);
        if(as.node.m == 0 && as.node.c == 0) {
            printf("�ɺӷ������£�\n");
            printf("          (M, C, B)\n");
            printPath(as.node.id);
            printf("���԰�ȫ�ɺӣ����������� %d �α��!\n", as.g);
            Safe = true;
            return;
        }
 
        if(as.node.b == 1) flag = -1;
        else flag = 1;
        b = 1 - as.node.b;
        id = PathNode.size() - 1;
 
        for(int i = 0; i < 5; ++i) {
            m = as.node.m + flag * add[i][0];
            c = as.node.c + flag * add[i][1];
 
            if(OK(m, c, b)) {
                ++id;
                st[m][c][b] = as.g + 1;
                PathNode.push_back(Node(m, c, b, id, as.node.id));
                Q.push(AstarNode(as.g + 1, PathNode[id]));
            }
        }
    }
}
 
int main(int argc, char *argv[]) {
	while(1)
	{
		cout<<"�������޵�ʿ��Ұ�˵�����������Ϊ0�˳�"<<endl;
		cin>>M>>C;
		if(M==0&&C==0) break;
		B = 1; K = 2;
		printf("M(�޵�ʿ) = %d ��, C(Ұ��) = %d ��, K(�޳�) = %d ��, B(��) = %d��.\n", M, C, K, B);
		Safe = false; Astar();
		if(!Safe) {
		    printf("�ɺ�ʧ��!!!\n");
		}
		putchar(10);	
	}
    return 0;
}

