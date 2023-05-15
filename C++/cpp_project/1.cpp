#include <iostream>
using namespace std;

const int MaxSize = 100; //100ֻ��ʾ���Ե����ݣ�����ʵ��������嶨��
template <class DataType> //����ģ����SeqList
class SeqList
{
//ͳһ�������� 
public:
    SeqList( );  //�޲ι��캯���������յ�˳���
    SeqList(DataType a[ ], int n); //�вι��캯������������Ϊn��˳���
    ~SeqList( ); //��������
    int Length( );  //�����Ա�ĳ���
    int Empety();
    DataType Get(int i); //��λ���ң����ҵ�i��Ԫ�ص�ֵ
    int Locate(DataType x ); //��ֵ���ң�����ֵΪx��Ԫ�����
    void Insert(int i, DataType x);//����������ڵ�i��λ�ò���ֵΪx��Ԫ��
    DataType Delete(int i); //ɾ��������ɾ����i��Ԫ��
   	void PrintList( ); //������������������������Ԫ��
private:
    DataType data[MaxSize]; //�������Ԫ�ص�����
    int length; //���Ա�ĳ���
};

//���庯�� 
template<class DataType>
SeqList<DataType> :: ~SeqList()
{

}

template <class DataType>
SeqList<DataType> :: SeqList()
{
     length = 0;
}

template <class DataType>
int SeqList<DataType> :: Empety()
{
     if(length == 0)
    return 1;
     else
     return 0;
}

template <class DataType>
int SeqList<DataType> :: Length()
{
     return length;
}

template <class DataType>
SeqList<DataType> :: SeqList(DataType a[ ], int n)
{
    if (n > MaxSize)
     throw "�����Ƿ�";
     for (int i = 0; i < n; i++)
     data[i] = a[i];
     length = n;
}

template <class DataType>
void SeqList<DataType> :: PrintList( )
{
    for (int i = 0; i < length; i++)
    cout << data[i];  //����������Ա��Ԫ��ֵ
}

template <class DataType>
int SeqList<DataType> :: Locate(DataType x)
{
    for (int i = 0; i < length; i++)
     if (data[i] == x) return i+1; //���������i+1
   return 0;
   //�˳�ѭ����˵������ʧ��
}

template <class DataType>
DataType SeqList<DataType> :: Get(int i)
{
    if (i < 1 && i > length)
     throw "����λ�÷Ƿ�";
    else
     return data[i - 1];
}

template <class DataType>
DataType SeqList<DataType> :: Delete(int i)
{
    if (length == 0)
     throw "����";
     if (i < 1 || i > length)
     throw "λ��";
     int x = data[i - 1]; //ȡ��λ��i��Ԫ��
     for (int j = i; j < length; j++)
     data[j - 1] = data[j];  //�˴�j�Ѿ���Ԫ�����ڵ������±�
     length--;
     return x;
}

template <class DataType>
void SeqList<DataType> :: Insert(int i, DataType x)
{
     if (length >= MaxSize)
     throw "����";
     if (i < 1 || i > length + 1)
     throw "λ��";
    for (int j = length; j >= i; j--)
     data[j] = data[j - 1]; //��j��Ԫ�ش��������±�Ϊj-1��
     data[i - 1] = x;
     length++;
}

int main() {
    int data[MaxSize];
    int n;
    cout << "���������Ա���: ";
    cin >> n;
    cout << "���������Ա�Ԫ��: ";
    for(int i=0; i<n; i++) {
        cin >> data[i];
    }
    //ʵ����һ��ģ���� 
    SeqList<int> L(data, n);
    
    cout << "��ǰ���Ա������Ϊ��";
    L.PrintList( ); //�����ǰ���Ա�
    
    try {
        int i, x;
        cout << endl << "����������λ�ú�Ԫ��ֵ��";
        cin >> i >> x;
        L.Insert(i, x); //�ڵ�i��λ�ò���ֵΪx��Ԫ��
        cout << "ִ�в������������Ϊ��";
        L.PrintList( ); //������������Ա�
        cout << endl;
    } catch(char* str) {
        cout << str << "�����������" << endl;
    }

    cout << "��ǰ���Ա�ĳ���Ϊ��" << L.Length( );//������Ա�ĳ���
    cout << endl;
    
    try {
        cout << "��������ҵ�Ԫ��ֵ��";
        int x;
        cin >> x;
        int i = L.Locate(x);
        if (0 == i) cout << "����ʧ��" << endl;
        else cout << "Ԫ��" << x << "��λ��Ϊ��" << i << endl;
    } catch(char* str) {
        cout << str << "���Ҳ�������" << endl;
    }

    try {
        cout << "������Ҫɾ����Ԫ��λ��: ";
        int i;
        cin >> i;
        int x = L.Delete(i);
        cout << "ɾ��Ԫ��" << x << "�����Ա������Ϊ��";
        L.PrintList();
        cout << endl;
    } catch(char* str) {
        cout << str << "ɾ����������" << endl;
    }

    return 0;
}
