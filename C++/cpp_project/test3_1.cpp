//�����������
#include <iostream>
// ���� rand() ������ͷ�ļ�
#include <cstdlib>
//�����ռ�
using namespace std;

// ��������ڵ�ṹ��
struct Node {
	// ������
    int data;
    // ָ����ָ����һ���ڵ�
    Node* next;
};

// ����ջ��
class Stack {
private:
	// ջ��ָ��
    Node* top;
    // ջ�Ĵ�С
    int size;
public:
	// ���캯������ʼ����ջ
    Stack() {
        top = NULL;
        size = 0;
    }

	// �����������ͷ�ջ�����нڵ���ڴ�
    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }

	// ��ջ����
    void push(int value) {
		// �ж�����   
        if (size >= 10) {
            cout << "����ջ���硣" << endl;
            return;
        }
		//����һ���½ڵ� 
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = top;
        //��ջ��Ԫ��ָ���½ڵ� 
        top = newNode;
        //ջ��С+1 
        size++;
    }

	// ��ջ����
    void pop(int n) {
		// �����Ƿ�   
        if (n <= 0) {
            cout << "������Ч�Ĳ�����" << endl;
            return;
        }

		// �ж�����
        if (size < n) {
            cout << "����ջ���硣" << endl;
            return;
        }

        cout << "��ջ�е��� " << n << " ��Ԫ�أ�" << endl;
        for (int i = 0; i < n; i++) {
            Node* temp = top;
            //�����ʾ����Ԫ�� 
            cout << temp->data << " ";
            top = top->next;
            delete temp;
            //ջ��С-1 
            size--;
        }
        cout << endl;
    }

	// ȡջ��Ԫ�غ���
    void getTop() {  
		// �ж�ջ��   
        if (size == 0) {
            cout << "����ջΪ�ա�" << endl;
            return;
        }

        cout << "ջ��Ԫ��Ϊ��" << top->data << endl;
    }
    
    //�������һ������������ӡջ��Ԫ����Ϣ
	//����۲�ջ��Ԫ�� 
    void printStack() {
    // �ж�ջ��
    if (size == 0) {
        cout << "��ǰջΪ�ա�" << endl;
        return;
    }

    cout << "��ǰջ��Ԫ��Ϊ����ջ����ջ�ף���" << endl;
    Node* temp = top;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
};

int main() {
    Stack s;

    // ��ջ
    for (int i = 0; i < 10; i++) {
        int value = rand() % 100;
        s.push(value);
    }
    
    s.printStack(); 

    // ��ջ
    int n;
    cout << "�����������ջ�е�����Ԫ�ظ�����С��10����";
    cin >> n;
    s.pop(n);
    
    s.printStack();

    // ȡջ��Ԫ��
    s.getTop();

    return 0;
}
