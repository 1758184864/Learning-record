#include <iostream>
#include <cstring>
#include <string.h>

using namespace std;
const int StackSize = 10;           //10��ʾ���Ե����ݣ�����ʵ��������嶨��
template<typename DataType>         //����ģ����SeqStack
class SeqStack {
public:
    SeqStack();                 //���캯������ʼ��һ����ջ
    ~SeqStack();                //��������
    void Push(DataType x);      //��ջ��������Ԫ��x��ջ
    DataType Pop();             //��ջ��������ջ��Ԫ�ص���
    DataType GetTop();          //ȡջ��Ԫ�أ�����ɾ����
    int Empty();                //�ж�ջ�Ƿ�Ϊ��
    int Precedence(char ch);
    int Operate(int x, char ch, int y);


private:
    DataType data[StackSize];    //���ջԪ�ص�����
    int top;                    //�α꣬ջ��ָ�룬Ϊջ��Ԫ���������е��±�
};

template<typename DataType>
SeqStack<DataType>::SeqStack() {
    top = -1;
}

template<typename DataType>
SeqStack<DataType>::~SeqStack() {

}

//��ջ��������Ԫ��x��ջ
template<typename DataType>
void SeqStack<DataType>::Push(DataType x) {
    if (top == StackSize - 1) throw "����";
    top++;
    data[top] = x;
}

//��ջ��������ջ��Ԫ�ص���
template<typename DataType>
DataType SeqStack<DataType>::Pop() {
    DataType datapop;
    if (top == -1) throw "����";
    datapop = data[top--];
    return datapop;
}

//ȡջ��Ԫ�أ�����ɾ����
template<typename DataType>
DataType SeqStack<DataType>::GetTop() {
    if (top != -1)
        return data[top];
}

template<typename DataType>
int SeqStack<DataType>::Empty() {
    if (top == -1)
        return 1;
    else
        return 0;
}

//�ж����ȼ�
template<typename DataType>
int SeqStack<DataType>::Precedence(char ch) {
    int z = 0;
    switch (ch) {
        case '+':
            z = 1;
            break;
        case '-':
            z = 1;
            break;
        case '*':
            z = 2;
            break;
        case '/':
            z = 2;
            break;
        case '#':
            z = 0;
            break;
        case '=':
            z = 0;
            break;
        case '(':
            z = 3;
            break;
        default:
            printf("error!\n");
    }
    return z;
}

//�������
template<typename DataType>
int SeqStack<DataType>::Operate(int x, char ch, int y) {
    int z = 0;
    switch (ch) {
        case '+':
            z = x + y;
            break;
        case '-':
            z = x - y;
            break;
        case '*':
            z = x * y;
            break;
        case '/':
            z = x / y;
            break;
        default:
            printf("error!\n");
    }
    return z;
}




int main() {
    SeqStack<int> OPTR{}, OPND{};   //����˳��ջ����S  //OPTR�洢�������OPND�洢��������������
    char w;
    int x, y, z;
    char op[9];
    strcpy(op,"+-*/()=#");   //opΪ���������
    //init(OPTR);
    OPTR.Push('#');

    //init(OPND);

    //ջ��ʼ�������������ջ��ջ��ѹ����ʽ���������ַ���#��
    w = getchar();                 //���ն˶���һ���ַ�

    while (!((w == '#') && (OPTR.GetTop() == '#'))) {
        if (!strchr(op, w)) {
            OPND.Push(atoi(&w));
            w = getchar();        //��������������ջ
        } else if (OPTR.Precedence(w) > OPTR.Precedence(OPTR.GetTop())) {   //�Ƚ�������
            OPTR.Push(w);
            w = getchar();
        } else {
            char theta;
            theta = OPTR.Pop();  //����ջ�������
            y = OPND.Pop();
            x = OPND.Pop();   //������������������
            z = OPND.Operate(x, theta, y);    //��������x��y

            OPND.Push(z);     //��������ѹ�������ջ
        }
    }
    cout << z << endl;
    return (OPND.GetTop());  //�Ӳ�����ջ��ȡ�����ʽ����������
}
