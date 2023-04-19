#include <iostream>
#include <cstring>

using namespace std;

// ���ַ�������
int getLength(const char* str) {
    int length = 0;
    //������ȡ���� 
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

// �ַ���ƴ��
void concatenate(char* str1, char* str2) {
    strcat(str1, str2);
    cout << "ƴ�ӽ����" << str1 << endl;
}

// �Ƚϴ�С
void compare(char* str1, char* str2) {
    int result = strcmp(str1, str2);
    if (result == 0) {
        cout << "�����ַ������" << endl;
    }
    else if (result > 0) {
        cout << "��һ���ַ������ڵڶ����ַ���" << endl;
    }
    else {
        cout << "��һ���ַ���С�ڵڶ����ַ���" << endl;
    }
}

int main() {
    // ϵͳ������ַ���
    char str1[] = "Hello, world!";
    cout << "ϵͳ������ַ����ǣ�" << str1 << endl;

    // �û�������ַ���
    cout << "��������һ���ַ�����";
    char str2[100];
    cin >> str2;
    cout << "��������ַ����ǣ�" << str2 << endl;

    // ���ַ�������
    int length1 = getLength(str1);
    int length2 = getLength(str2);
    cout << "ϵͳ������ַ�������Ϊ��" << length1 << endl;
    cout << "��������ַ�������Ϊ��" << length2 << endl;

    // �ַ���ƴ��
    char str3[200];
    strcpy(str3, str1);
    concatenate(str3, str2);

    // �Ƚϴ�С
    compare(str1, str2);

    return 0;
}
