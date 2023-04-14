//�����������
#include <iostream>
//�������������
#include <cstdlib>
//���ڻ�ȡ��ǰʱ��
#include <ctime>
//�����ռ� 
using namespace std;

// ���嵥������
struct Node {
	//���� 
    int data;
    //ָ��ָ����һ�ڵ� 
    Node* next;
    //���캯�� 
    Node(int d) : data(d), next(nullptr) {}
};

// ���嵥������
class LinkedList {
private:
	//ͷ���ָ�� 
    Node* head;
    //������� 
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    // �������10��100���ڵ����������뵥������
    void generate() {
        for (int i = 0; i < 10; ++i) {
            int data = rand() % 100;
            insert(data, i);
        }
    }

    // ����Ԫ��
    void insert(int data, int pos) {
    	//�ж�����λ���Ƿ�Ϸ� 
        if (pos < 0 || pos > size) {
            cout << "��Ч��λ��" << endl;
            return;
        }
        //�����½ڵ� 
        Node* new_node = new Node(data);
        if (pos == 0) {
        	//�������λ��Ϊ0�����½ڵ���뵽����ͷ�����½ڵ�� "next" ָ�뽫ָ��ԭ����ͷ�ڵ㣬
            new_node->next = head;
            //Ȼ�� "head" ָ���½ڵ㡣
            head = new_node;
        }
        else {
        	//���Ƚ�ָ�� "curr" ָ��ͷ�ڵ�
            Node* curr = head;
            //Ȼ��ͨ��������ͷ��ʼ�ƶ� "pos - 1" �Σ��Ե������λ��֮ǰ�Ľڵ㡣
            for (int i = 0; i < pos - 1; ++i) {
                curr = curr->next;
            }
            //���½ڵ�� "next" ָ��ָ��ǰ�ڵ�� "next" ָ��ָ��Ľڵ�
            new_node->next = curr->next;
            //����ǰ�ڵ�� "next" ָ��ָ���½ڵ�
            curr->next = new_node;
        }
        //�����С+1 
        ++size;
    }

    // ɾ��Ԫ��
    void remove(int pos) {
    	//�ж�λ���Ƿ�Ϸ� 
        if (pos < 0 || pos >= size) {
            cout << "��Ч��λ��" << endl;
            return;
        }
        //����һ��ָ������ͷ����ָ�� "curr"��
        Node* curr = head;
        if (pos == 0) {
        	//�� "head" ָ��ԭʼͷ�ڵ����һ���ڵ�
            head = head->next;
            //ɾ��ԭʼͷ�ڵ�
            delete curr;
        }
        else {
            for (int i = 0; i < pos - 1; ++i) {
            	//��ָ�� "curr" ָ��ͷ�ڵ㣬Ȼ��ͨ��������ͷ��ʼ�ƶ� "pos - 1" �Σ��Ե���Ҫɾ���Ľڵ�֮ǰ�Ľڵ㡣
                curr = curr->next;
            }
            //��һ��ָ�� "temp" ָ��Ҫɾ���Ľڵ�
            Node* temp = curr->next;
            //����ǰ�ڵ�� "next" ָ��ָ��Ҫɾ���ڵ����һ���ڵ�
            curr->next = temp->next;
            //ɾ���ڵ� 
            delete temp;
        }
        //�����С-1
        --size;
    }

    // ����Ԫ��
    int find(int data) {
    	//����һ��ָ������ͷ����ָ�� "curr"
        Node* curr = head;
        //��ʼ��λ�� "pos" Ϊ0
        int pos = 0;
        while (curr) {
            if (curr->data == data) {
                //�����ǰ�ڵ������ֵ����Ҫ���ҵ�����ֵ���򷵻ص�ǰλ�� "pos"
				return pos;
            }
            //�������� 
            curr = curr->next;
            ++pos;
        }
        //δ�ҵ� 
        return -1;
    }

    // ��ʾ�������е�Ԫ��
    void display() {
    	//����һ��ָ������ͷ����ָ�� "curr"���������ʼ��Ϊͷ�ڵ� "head"�� 
        Node* curr = head;
        while (curr) {
        	//�����ǰ�ڵ������ֵ
            cout << curr->data << " ";
            //�ƶ�ָ�� 
            curr = curr->next;
        } 
        cout << endl;
    }
    
    // ���ڹ鲢�����˼��ʵ��������������ĺϲ�
	LinkedList merge(LinkedList& L1, LinkedList& L2) {
	    // ����������
	    LinkedList L;
	
	    // ��ȡͷ�ڵ�
	    Node* curr1 = L1.head;
	    Node* curr2 = L2.head;
	
	    // ������������
	    while (curr1 && curr2) {
	        if (curr1->data <= curr2->data) {
	            // ���L1�е�Ԫ�ظ�С�����������������
	            L.insert(curr1->data, L.size);
	            curr1 = curr1->next;
	        } else {
	            // ���L2�е�Ԫ�ظ�С�����������������
	            L.insert(curr2->data, L.size);
	            curr2 = curr2->next;
	        }
	    }
	
	    // ��δ��������������е�ʣ��Ԫ�ز�����������
	    while (curr1) {
	        L.insert(curr1->data, L.size);
	        curr1 = curr1->next;
	    }
	    while (curr2) {
	        L.insert(curr2->data, L.size);
	        curr2 = curr2->next;
	    }
	
	    return L;
	}
};

int main() {
//    srand(time(NULL));
//    LinkedList list;
//    list.generate();
//    cout << "���ɵ�����Ϊ��";
//    list.display();
//    int data, pos;
//    cout << "������Ҫ���ҵ�������";
//    cin >> data;
//    pos = list.find(data);
//    if (pos != -1) {
//        cout << data << "��λ��Ϊ" << pos << endl;
//    }
//    else {
//        cout << "��Ԫ�ز�����" << endl;
//    }
//    cout << "������Ҫ�����������λ�ã�";
//    cin >> data >> pos;
//    list.insert(data, pos);
//    cout << "����Ԫ�غ������Ϊ��";
//    list.display();
//    cout << "������Ҫɾ����λ�ã�";
//    cin >> pos;
//    list.remove(pos);
//    cout << "ɾ��Ԫ�غ������Ϊ��";
//	list.display();

    // �������������
    srand(time(nullptr));

    // ����������������
    LinkedList L1, L2;

    // ����������ݲ�����������
    L1.generate();
    L2.generate();

    // ��ʾԭʼ������
    cout << "L1: ";
    L1.display();
    cout << "L2: ";
    L2.display();

    // �ϲ���������ʾ���
    LinkedList L3 = L1.merge(L1,L2);
    cout << "�ϲ���ĵ�����: ";
    L3.display();

    return 0;
}
