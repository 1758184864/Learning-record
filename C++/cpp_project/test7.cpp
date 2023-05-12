#include <iostream>
//rand��srand����
#include <cstdlib>
//time������clock����
#include <ctime>
//setprecision����
#include <iomanip>
//sort���� 
#include <algorithm>

using namespace std;

//˳������㷨
int sequentialSearch(int numbers[], int n, int k) {
    for (int i = 0; i < n; i++) {
        if (numbers[i] == k) {
            return i;
        }
    }
    return -1;
}

//�۰�����㷨
int binarySearch(int numbers[], int n, int k) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = (left + right) / 2;
        if (numbers[mid] == k) {
            return mid;
        } else if (numbers[mid] < k) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    const int n = 10000;
    int numbers[n];
    //��ʼ�����������
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
    	//����0~99999֮��������
        numbers[i] = rand() % 100000;
    }
    //����0~99999֮����������ΪҪ���ҵ�ֵ
    int k = rand() % 100000;

    //˳�����
    //��¼���ҿ�ʼʱ��
    clock_t start = clock();
    //����˳�������ʱ����
    double sequentialTime = 0;
    //�ظ�ִ��1000��
    for (int i = 0; i < 1000; i++) {
        sequentialSearch(numbers, n, k);
    }
    //����˳�������ʱ����λΪ��
    sequentialTime = (clock() - start) * 1000.0 / CLOCKS_PER_SEC / 1000.0;

    //�۰����
    //����������
    sort(numbers, numbers + n);
    //��¼���ҿ�ʼʱ��
    start = clock();
    //�����۰������ʱ����
    double binaryTime = 0;
    //�ظ�ִ��1000��
    for (int i = 0; i < 1000; i++) { 
        binarySearch(numbers, n, k);
    }
    //�����۰������ʱ����λΪ��
    binaryTime = (clock() - start) * 1000.0 / CLOCKS_PER_SEC / 1000.0;

    //������
    cout << setprecision(3) << fixed;//�����������
    cout << "˳�������ʱ��" << sequentialTime << " s" << endl;
    cout << "�۰������ʱ��" << binaryTime << " s" << endl;

    return 0;
}
