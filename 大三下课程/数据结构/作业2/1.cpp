//io�� 
#include <iostream>
//��������������ռ� 
using namespace std;
//���� 
const int MaxSize = 100;
//ģ����(Java����) 
template <class DataType>
class SeqList
{
//�������� 
public:
	//�޲ι��캯���������յ�˳���
    SeqList();
    //�вι��캯������������Ϊn��˳���
    SeqList(DataType a[ ], int n);
    //��������
    //���ڶ�������ʱ���Զ����ã������ͷŶ���ռ�õ���Դ��������ڴ桢�ļ�����ȣ���
	//һ������Զ���һ�����������������ڶ�������ʱִ���������������
	~SeqList();
	//�����Ա�ĳ���
    int Length();
    //�ж����Ա��Ƿ�Ϊ�գ�1����ա�0����ǿ� 
    int Empety();
    //��λ���ң����ҵ�i��Ԫ�ص�ֵ
    DataType Get(int i);
    //��ֵ���ң�����ֵΪx��Ԫ�����
    int Locate(DataType x);
    //����������ڵ�i��λ�ò���ֵΪx��Ԫ��
    void Insert(int i, DataType x);
    //ɾ��������ɾ����i��Ԫ��
    DataType Delete(int i);
    //������ӡ����������������Ԫ��
   	void PrintList( );
//˽�з��� 
private:
	//�������Ԫ�ص�����
    DataType data[MaxSize];
    //���Ա�ĳ���
    int length;
};

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
    if(length == 0){
    	return 1;
	}else{
		return 0;
	}
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
void SeqList<DataType> :: PrintList()
{
    for (int i = 0; i < length; i++){
		//����������Ա��Ԫ��ֵ
		cout << data[i];
	} 
}

template <class DataType>
int SeqList<DataType> :: Locate(DataType x)
{
    for (int i = 0; i < length; i++){
		if (data[i] == x){
			//���������i+1
			return i+1;
		}
	}
	//�˳�ѭ����˵������ʧ��
	return 0;
}

template <class DataType>
DataType SeqList<DataType> :: Get(int i)
{
    if (i < 1 && i > length){
    	throw "����λ�÷Ƿ�";
	}else{
		return data[i - 1];
	}
}

template <class DataType>
DataType SeqList<DataType> :: Delete(int i)
{
//    if (length == 0)
//     throw "����";
//     if (i < 1 || i > length)
//     throw "λ��";
//     int x = data[i - 1]; //ȡ��λ��i��Ԫ��
//     for (int j = i; j < length; j++)
//     data[j - 1] = data[j];  //�˴�j�Ѿ���Ԫ�����ڵ������±�
//     length--;
//     return x;
	if (length == 0){ 
		throw "����"; 
	}
	
	if (i < 1 || i > length){ 
		throw "λ�ô���"; 
	}
	
	//ȡ��λ��i��Ԫ�� 
	int x = data[i-1]; 
	
	for (int j=i; j<length; j++){
		//�˴�j�Ѿ���Ԫ�����ڵ������±� 
		data[j-1] = data[j];
	}
	length--;
	return x; 
}

template <class DataType>
void SeqList<DataType> :: Insert(int i, DataType x)
{
	if (length >= MaxSize){
		throw "����";
	}
	
	if (i < 1 || i > length + 1){
		throw "λ�ô���";
	}
     
	for (int j = length; j >= i; j--){
		//��j��Ԫ�ش��������±�Ϊj-1��
		data[j] = data[j - 1];
		data[i - 1] = x;	
	}
	length++;
}

int main() {
	//�������Ա� 
    int data[MaxSize];
    //ʹ�ñ���n���洢����ĳ���ֵ 
    int n;
    cout << "���������Ա���: ";
    cin >> n;
    cout << "���������Ա�Ԫ��: ";
    for(int i=0; i<n; i++) {
        cin >> data[i];
    }
    
    //��ʼ�����Ա� 
    SeqList<int> L(data, n);
    
    cout << "��ǰ���Ա������Ϊ��";
    //�����ǰ���Ա�
	L.PrintList( );
    
    try {
        int i, x;
        cout << endl << "����������λ�ú�Ԫ��ֵ��";
        cin >> i >> x;
        //�ڵ�i��λ�ò���ֵΪx��Ԫ��
        L.Insert(i, x);
        cout << "ִ�в������������Ϊ��";
        //������������Ա�
        L.PrintList();
        cout << endl;
    } catch(char* str) {
        cout << str << "�����������" << endl;
    }

	//������Ա�ĳ���
    cout << "��ǰ���Ա�ĳ���Ϊ��" << L.Length( );
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
