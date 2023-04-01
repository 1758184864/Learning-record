//io�� 
#include <iostream>
//��������������ռ� 
using namespace std;

template<typename DataType>
struct Node {
    DataType data;  //������
    Node<DataType> *next;  //ָ����
};

template<typename DataType>
class LinkList {
public:
    LinkList(); //�޲ι��캯��������ֻ��ͷ���Ŀ�����
    LinkList(DataType a[], int n);  //�вι��캯����������n��Ԫ�صĵ�����
    ~LinkList();  //��������
    int Length();  //������ĳ���
    int Empety();

    DataType Get(int i);  //��λ���ҡ����ҵ�i������Ԫ��ֵ
    int Locate(DataType x); //��ֵ���ҡ�����ֵΪx��Ԫ�����
    void Insert(int i, DataType x);  //�����������i��λ�ò���ֵΪx�Ľ��
    DataType Delete(int i); //ɾ��������ɾ����i�����
    void PrintList(); //������������������������Ԫ��
private:
    Node<DataType> *first;  //�������ͷָ��
};

template<typename DataType>
LinkList<DataType>::LinkList() {
    first = new Node<DataType>; //����ͷ���
    first->next = nullptr; //ͷ����ָ�����ÿ�
}

template<class DataType>
LinkList<DataType>::~LinkList() {
    Node<DataType> *q = NULL;
    while (first != NULL)//�ͷŵ������ÿһ�����Ĵ洢�ռ�
    {
        q = first;  //�ݴ汻�ͷŽ��
        first = first->next;  // firstָ���ͷŽ�����һ�����
        delete q;
    }
}

template<typename DataType>
int LinkList<DataType>::Empety() {
    if (first->next == nullptr)
        return 1;
    else
        return 0;
}

template<typename DataType>
void LinkList<DataType>::PrintList() {
    Node<DataType> *p = first->next; //����ָ��p��ʼ��
    while (p != nullptr) {
        cout << p->data << "\t";
        p = p->next;  //����ָ��p���ƣ�ע�ⲻ��д��p++

    }
}

template<typename DataType>
int LinkList<DataType>::Length() {
    Node<DataType> *p = first->next;  //����ָ��p��ʼ��Ϊ��ʼ�ӵ�
    int count = 0; //�ۼ���count��ʼ��
    while (p != nullptr) {
        p = p->next;
        count++;

    }
    return count;//ע��count�ĳ�ʼ���ͷ���ֵ֮��Ĺ�ϵ
}

template<typename DataType>
DataType LinkList<DataType>::Get(int i) {
    Node<DataType> *p = first->next; //����ָ��p��ʼ��
    int count = 1;  //�ۼ���count��ʼ��
    while (p != nullptr && count < i) {
        p = p->next; //����ָ��p����
        count++;
    }
    if (p == nullptr) throw "λ��";
    else return p->data;
}

template<typename DataType>
int LinkList<DataType>::Locate(DataType x) {
    Node<DataType> *p = first->next;  //����ָ��p��ʼ��
    int count = 1;  //�ۼ���count��ʼ��
    while (p != nullptr) {
        if (p->data == x) return count;  //���ҳɹ��������������������
        p = p->next;
        count++;
    }
    return 0; //�˳�ѭ����������ʧ��
}

template<typename DataType>
void LinkList<DataType>::Insert(int i, DataType x) {
    Node<DataType> *p = first, *s = nullptr; //����ָ��p��ʼ��
    int count = 0;
    while (p != nullptr && count < i - 1) //���ҵ�i �C 1�����
    {
        p = p->next; //����ָ��p����
        count++;
    }
    if (p == nullptr) throw "λ��";//û���ҵ���i �C 1�����
    else {
        s = new Node<DataType>;
        s->data = x; //������s��������Ϊx
        s->next = p->next;
        p->next = s;  //�����s���뵽���p֮��
    }
}

// ͷ�巨����?
//template <typename DataType> ?
//LinkList<DataType> :: LinkList(DataType a[ ], int n)
//{
//? ??first = new Node<DataType>; first->next = nullptr; ? ? //��ʼ��һ��������
//? ??for (int i = 0; i < n; i++)
//? ??{?
//? ? ? ??Node<DataType> *s;
//? ? ? ??s = new Node<DataType>; s->data = a[i]; ? ?
// ? ? ? ??s->next = first->next; first->next = s; ? ?//�����s���뵽ͷ���֮��
//? ??}
//}

template<typename DataType>
LinkList<DataType>::LinkList(DataType a[], int n) {
    first = new Node<DataType>; //����ͷ���
    Node<DataType> *r = first, *s = nullptr;  //βָ���ʼ��
    for (int i = 0; i < n; i++) {
        s = new Node<DataType>;
        s->data = a[i];
        r->next = s;
        r = s;  //�����s���뵽�ն˽��֮��
    }
    r->next = nullptr; //����������ϣ����ն˽���ָ�����ÿ�
}

template<typename DataType>
DataType LinkList<DataType>::Delete(int i) {
    DataType x;
    Node<DataType> *p = first, *q = nullptr; //����ָ��pָ��ͷ���
    int count = 0;
    while (p != nullptr && count < i - 1)  //���ҵ�i-1�����
    {
        p = p->next;
        count++;
    }
    if (p == nullptr || p->next == nullptr) //���p�����ڻ�p�ĺ�̽�㲻����
        throw "λ��";
    else {
        q = p->next;
        x = q->data;  //�ݴ汻ɾ���
        p->next = q->next; //ժ��
        delete q;
        return x;
    }
}

int main()
{
    int a[100], n, x, i;
    cout << "������˳�����n: ";
    cin >> n;
    cout << "������˳����" << n << "��Ԫ��: ";
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    LinkList<int> L(a, n); // ��˳�������ݹ�������

    cout << "˳����е�Ԫ��Ϊ: ";
    L.PrintList(); // ����˳���

    cout << endl << "������Ҫ�����Ԫ��x�Ͳ���λ��i: ";
    cin >> x >> i;
    try {
        L.Insert(i, x);
        cout << "����Ԫ��x�ɹ���" << endl;
        cout << "����������Ϊ: ";
        L.PrintList();
    }
    catch (const char *e) {
        cout << "����λ�ô���" << endl;
    }

    cout << endl << "������Ҫɾ��Ԫ�ص�λ��i: ";
    cin >> i;
    try {
        x = L.Delete(i);
        cout << "ɾ��Ԫ��x=" << x << "�ɹ���" << endl;
        cout << "ɾ���������Ϊ: ";
        L.PrintList();
    }
    catch (const char *e) {
        cout << "ɾ��λ�ô���" << endl;
    }

    cout << endl << "������Ҫ���ҵ�Ԫ��: ";
    cin >> x;
    int pos = L.Locate(x);
    if (pos == 0) {
        cout << "δ�ҵ���Ԫ�أ�" << endl;
    }
    else {
        cout << "Ԫ��x=" << x << "�������е�λ��Ϊ: " << pos << endl;
    }

    return 0;
}

