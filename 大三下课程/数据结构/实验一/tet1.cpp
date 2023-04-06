#include<iostream>
// ���� rand() �� srand() ����
#include<cstdlib>
// ���� time() ����
#include<ctime>

using namespace std;

// ���峣��
// ˳�����������
const int MAXSIZE = 10;
// ��������������ֵ
const int MAXNUM = 100;

// ����˳���ṹ��
struct SeqList{
	// �洢����Ԫ�ص�����
    int data[MAXSIZE];
    // ��ǰ˳����е�Ԫ�ظ���
	int length;
};

// ��ʼ��˳���
void InitList(SeqList &L)
{
	// ��˳���ĳ��ȳ�ʼ��Ϊ 0
    L.length = 0;
}

// ������� 10 �� 100 ���ڵ��������洢��˳�����
void CreateList(SeqList &L)
{
	// ��ϵͳʱ����Ϊ��������ӣ�ȷ��ÿ�����г���ʱ���ɵ��������ͬ
    srand(time(NULL));
    for(int i=0;i<MAXSIZE;i++){
    	// ���� 1 ~ 100 ������������洢��˳�����
        L.data[i] = rand() % MAXNUM + 1;
    }
    // ˳���ĳ�����Ϊ MAXSIZE
    L.length = MAXSIZE;
}

// ���˳����е�����Ԫ��
void DisplayList(SeqList L)
{
    cout << "��ǰ˳����е�Ԫ��Ϊ��";
    for(int i=0;i<L.length;i++){
        cout << L.data[i] << " ";
    }
    cout << endl;
}

// ��˳����в���ָ��Ԫ�أ���������λ�ã��� 0 ��ʼ�����������Ҳ������� -1
int FindElem(SeqList L, int x)
{
    for(int i=0;i<L.length;i++){
        if(L.data[i] == x){
            return i;
        }
    }
    return -1;
}

// ��˳����ָ��λ�ò���Ԫ��
void InsertElem(SeqList &L, int x, int pos)
{
	// ���˳����������޷�������Ԫ��
    if(L.length == MAXSIZE){
        cout << "˳����������޷�������Ԫ�أ�" << endl;
        return;
    }
    // �������λ�ò��Ϸ����޷�������Ԫ��
    if(pos < 0 || pos > L.length){
        cout << "����λ�ò��Ϸ����޷�������Ԫ�أ�" << endl;
        return;
    }
    // �� pos ��������Ԫ�غ���
    for(int i=L.length-1;i>=pos;i--){
        L.data[i+1] = L.data[i];
    }
    // �� pos ��������Ԫ��
    L.data[pos] = x;
    // ˳����ȼ� 1
    L.length++;
}

// ɾ��˳�����ָ��λ�õ�Ԫ��
void DeleteElem(SeqList &L, int pos)
{
	// �ж�ɾ��λ���Ƿ�Ϸ�
    if(pos < 0 || pos >= L.length){
        cout << "ɾ��λ�ò��Ϸ���" << endl;
        return;
    }

	// �������Ԫ����ǰ�ƶ�
    for(int i = pos; i < L.length - 1; i++){
        L.data[i] = L.data[i + 1];
    }
    L.length--; // ˳����ȼ� 1
}

// ������
int main()
{
	// ����˳���
	SeqList L;
	// ����Ԫ�ص�ֵ�Ͳ���λ��
	int x, pos;
	// ����Ԫ�ص�ֵ
	int elem;
	// ��ʼ��˳���
	InitList(L);
	
	// ������� 10 �� 100 ���ڵ��������洢��˳�����
	CreateList(L);
	
	// ���˳����е�����Ԫ��
	DisplayList(L);
	
	// ����Ԫ��
	cout << "������Ҫ���ҵ�Ԫ��ֵ��";
	cin >> elem;
	int idx = FindElem(L, elem);
	if(idx == -1){
	    cout << "��Ԫ�ز���˳����У�" << endl;
	}else{
	    cout << "��Ԫ����˳����е�λ��Ϊ��" << idx << endl;
	}
	
	// ɾ��Ԫ��
	cout << "������Ҫɾ����Ԫ��λ�ã��� 0 ��ʼ��������";
	cin >> pos;
	DeleteElem(L, pos);
	DisplayList(L);
	
	// ����Ԫ��
	cout << "������Ҫ�����Ԫ��ֵ�Ͳ���λ�ã��� 0 ��ʼ��������";
	cin >> x >> pos;
	InsertElem(L, x, pos);
	DisplayList(L);

	return 0;
}
