#include <iostream>
#include <queue>
#include <chrono>
#include <thread>

using namespace std;

int main() {
    queue<int> patientQueue;

    // ��ȡ���˱�Ų��Ŷ�
    while (true) {
        cout << "�����벡�˱�ţ�����0��������" << endl;
        int patientId;
        cin >> patientId;
        if (patientId == 0) {
            break;
        }
        patientQueue.push(patientId);
    }

    // ģ�⿴������
    while (!patientQueue.empty()) {
        int currentPatient = patientQueue.front();
        patientQueue.pop();

        // ���е�ǰ���˿���
        cout << "�벡�� " << currentPatient << " ����" << endl;

        if (!patientQueue.empty()) {
            // ��ʾ��һ��׼�������Ĳ��˱��
            cout << "��һ������׼��������Ϊ��" << patientQueue.front() << endl;
        }

        // ��ͣ2����
        this_thread::sleep_for(chrono::seconds(2));
    }

    cout << "���в����ѿ��ꡣ" << endl;

    return 0;
}
