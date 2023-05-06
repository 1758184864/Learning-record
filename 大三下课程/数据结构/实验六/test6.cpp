#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 100;
// �ڽӾ���洢ͼ
bool graph[MAXN][MAXN];
// ��ǽڵ��Ƿ񱻷��ʹ�
bool visited[MAXN];
// n ��ʾ�ڵ�����m ��ʾ����
int n, m;

// ������ȱ���
void dfs(int u) {
	// ��ǵ�ǰ�ڵ��ѱ�����
    visited[u] = true;
    // �����ǰ�ڵ�
    cout << u << " ";
    // ö���뵱ǰ�ڵ����ڵĽڵ�
    for (int v = 0; v < n; v++) {
    	// ����뵱ǰ�ڵ����ڵĽڵ�δ�����ʹ�
        if (graph[u][v] && !visited[v]) {
        	// ����������ȱ����ýڵ�
            dfs(v); 
        }
    }
}

// ��ʹ�� queue �Ĺ�����ȱ���
void bfs(int u) {
	// ����һ������ q
    int q[MAXN];
    // head �� tail �ֱ�ָ����׺Ͷ�β
    int head = 0, tail = 0;
    // �����ʼ�ڵ��ѱ�����
    visited[u] = true;
    // ����ʼ�ڵ�������
    q[tail++] = u;
    // �����зǿ�ʱ
    while (head < tail) {
    	// ȡ������Ԫ��
        int x = q[head++];
        // �����ǰ�ڵ�
        cout << x << " ";
        // ö���뵱ǰ�ڵ����ڵĽڵ�
        for (int v = 0; v < n; v++) {
        	// ����뵱ǰ�ڵ����ڵĽڵ�δ�����ʹ�
            if (graph[x][v] && !visited[v]) {
            	// ��Ǹýڵ��ѱ�����
                visited[v] = true;
                // ���ýڵ�������
                q[tail++] = v;
            }
        }
    }
}

int main() {
	// ����ڵ����ͱ���
    cin >> n >> m;

    // ��ʼ���ڽӾ���ͱ������
    memset(graph, false, sizeof(graph)); 
    memset(visited, false, sizeof(visited)); 

    // ����ߵ���Ϣ�������ڽӾ�������ӱ�
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v; 
        graph[u][v] = graph[v][u] = true;
    }

    // ������ȱ���
    cout << "DFS: ";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    cout << endl;

    // ������ȱ���
    // ���ñ������
    memset(visited, false, sizeof(visited));
    cout << "BFS: ";
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            bfs(i);
        }
    }
    cout << endl;

    return 0;
}
