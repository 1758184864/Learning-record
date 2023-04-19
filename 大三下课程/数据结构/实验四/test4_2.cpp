#include <iostream>
#include <cstring>
using namespace std;

const int N = 31; // ���峣��NΪ31�����ڴ�Ż÷��Ĵ�С

int a[N][N]; // �����ά����a��Ż÷���ֵ

int main()
{
	// ����n��Ż÷��Ĵ�С
    int n;
    // ����÷��Ĵ�С
    cout << "������÷���Сn��1<= n <= 30����";
	cin >> n;

	// ����ά����aȫ����0
    memset(a, 0, sizeof a);

	// �����ʼλ��Ϊ��һ�е��м�λ��
    int x = n / 2, y = n - 1;
    // ��1�����ʼλ��
    a[x][y] = 1;

	// ��2��ʼѭ�����÷�
    for (int i = 2; i <= n * n; i++) {
    	// ������һ��λ��
        int nx = (x - 1 + n) % n, ny = (y + 1) % n;
        // �����һ��λ���Ѿ�������
        if (a[nx][ny]) {
        	// �����ڵ�ǰλ�õ�����
            x = (x + 1) % n;
        } else {
        	// �������ڼ����������һ��λ��
            x = nx, y = ny;
        }
        // ����ǰ������÷���
        a[x][y] = i;
    }

	// ѭ������÷�
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
