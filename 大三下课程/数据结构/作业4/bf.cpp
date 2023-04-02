#include <iostream>
#include <cstring>

using namespace std;

int BF_Search(char* s, char* p) {
	//�����������Ӵ�����ȡ���Գ�����Ϣ 
    int s_len = strlen(s);
    int p_len = strlen(p);

	//�������б���ÿһ�����ܵ���ʼλ�ã�ֱ�����һ�����ܵ�λ��Ϊֹ��
	//�����Ӵ����Ȳ������������ȣ���˿��Ա�֤��Щ��ʼλ���ǺϷ���
    for (int i = 0; i <= s_len - p_len; i++) {
    	//��ÿ����ʼλ���ϣ�ʹ��ѭ�������Ӵ���ÿһ���ַ������Ƚ�����������Ӧλ�õ��ַ��Ƿ���ȡ�
		//�����ĳ��λ�÷��ֲ�ƥ����ַ�����ô���˳�ѭ���� 
        int j;
        for (j = 0; j < p_len; j++) {
            if (s[i + j] != p[j]) {
                break;
            }
        }
        //������Ӵ���ÿ��λ���϶��ҵ�����������Ӧλ����ȵ��ַ������ʾ�Ӵ�ƥ��ɹ������ص�ǰ��ʼλ�� i��
        if (j == p_len) {
            return i;
        }
    }
    //�����������û���ҵ�ƥ����Ӵ����򷵻� -1����ʾƥ��ʧ�ܡ�
    return -1;
}

int main() {
    char s[100], p[100];
    cout << "����������: ";
    cin >> s;
    //�����������еĻس���
    cin.ignore();
    cout << "�������Ӵ�: ";
    cin.getline(p, 100);

    int pos = BF_Search(s, p);
    if (pos == -1) {
        cout << "�޷�ƥ��" << endl;
    }
    else {
        cout << "ƥ��λ��: " << pos << endl;
    }

    return 0;
}
