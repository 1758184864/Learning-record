//�����������
#include <iostream>
//�������������
#include <cstdlib>
//���ڻ�ȡ��ǰʱ��
#include <ctime>
//�����ռ�
using namespace std;

// �����������
const int MAX_SIZE = 10;

class Queue {
private:
	// ���ڴ洢����Ԫ�ص�����
    int arr[MAX_SIZE];
	// ��ͷ�Ͷ�βָ�� 
    int front, rear; 

public:
    Queue() {
    	// ��ʼ����ͷָ��
        front = 0;
        // ��ʼ����βָ��
        rear = 0;
    }
	//�����Ƿ�Ϊ�� 
    bool isEmpty() {
    	// ����Ϊ�յ������Ƕ�ͷ�Ͷ�βָ�����
        return front == rear;
    }
	//�����Ƿ����� 
    bool isFull() {
    	// ���������������Ƕ�βָ��� 1 ���ڶ�ͷָ��
        return (rear + 1) % MAX_SIZE == front;
    }

	//��Ӻ��� 
    void enqueue(int value) {
    	// ������������������ʾ��Ϣ������
        if (isFull()) {
            cout << "����������" << endl;
            return;
        }
        // ��Ԫ�ش洢����β
        arr[rear] = value;
        // ��βָ��� 1
        rear = (rear + 1) % MAX_SIZE;
    }

	//���Ӻ��� 
    int dequeue(int n) {
    	// �������Ϊ�գ������ʾ��Ϣ������ -1
        if (isEmpty()) {
            cout << "����Ϊ�ա�" << endl;
            return -1;
        }
        // ��¼����Ԫ�ص�����
        int count = 0;
        // ֻҪ���зǿ��ҳ���Ԫ���������� n����һֱѭ��
        while (!isEmpty() && count < n) {
        	// ȡ����ͷԪ��
            int value = arr[front];
            // ��ͷָ��� 1
            front = (front + 1) % MAX_SIZE;
            // �������Ԫ��
            cout << value << " ";
			// �������� 1 
            count++;
        }
        // ������з�
        cout << endl;
        // ���س���Ԫ������
        return count;
    }

	//���ض�ͷԪ�� 
    int peek() {
    	// �������Ϊ�գ������ʾ��Ϣ������ -1
        if (isEmpty()) {
            cout << "����Ϊ�ա�" << endl;
            return -1;
        }
        // ���ض�ͷԪ��
        return arr[front];
    }
};

int main() {
	//����һ�����ж��� 
    Queue q;
    // ��ʼ�������������
	srand(time(NULL));
	
	// ���10�������
	for (int i = 0; i < 10; i++) {
	    int value = rand() % 100;
	    q.enqueue(value);
	}
	
	// �Ӷ����г���n��Ԫ��
	int n;
	cout << "��������Ҫ���ӵ�Ԫ��������";
	cin >> n;
	int count = q.dequeue(n);
	cout << "�ѳ��� " << count << " ��Ԫ�ء�" << endl;
	
	// ��ȡ��ͷԪ��
	int front = q.peek();
	if (front != -1) {
	    cout << "��ͷԪ��Ϊ��" << front << endl;
	}
	
	return 0;
}
