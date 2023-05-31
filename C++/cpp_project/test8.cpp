#include <iostream>
#include <vector>
#include <random>
#include <chrono>
using namespace std;
using namespace chrono;

// ֱ�Ӳ�������
void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; ++i) {
    	// ѡȡ��ǰԪ����Ϊ����Ԫ��
        int key = arr[i];
        int j = i - 1;
        // ��ǰ���Ҳ���λ�ò��ƶ�Ԫ��
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        // ����Ԫ�ص���ȷλ��
        arr[j + 1] = key;
    }
}

// ϣ������
void shellSort(vector<int>& arr) {
    int n = arr.size();
    // �����������з���
    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; ++i) {
        	// ѡȡ��ǰԪ����Ϊ����Ԫ��
            int temp = arr[i];
            int j;
            // ��ǰ���Ҳ���λ�ò��ƶ�Ԫ��
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            // ����Ԫ�ص���ȷλ��
            arr[j] = temp;
        }
    }
}

// ð������
void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; ++i) {
    	// ���αȽ����ڵ�Ԫ�ز�����
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ��������
int partition(vector<int>& arr, int low, int high) {
	// ѡȡ���һ��Ԫ����Ϊ��׼
    int pivot = arr[high]; 
    int i = low - 1;
    for (int j = low; j <= high - 1; ++j) {
    	// ��С�ڻ�׼��Ԫ�طŵ����
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    // ����׼�ŵ���ȷλ��
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
    	// �������飬����ȡ��׼��λ��
        int pi = partition(arr, low, high);
        // �ݹ�ض���벿�ֽ��п�������
        quickSort(arr, low, pi - 1);
        // �ݹ�ض��Ұ벿�ֽ��п�������
        quickSort(arr, pi + 1, high);
    }
}

// ���������
vector<int> generateRandomNumbers(int count, int minValue, int maxValue) {
    vector<int> numbers(count);
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(minValue, maxValue);
    for (int i = 0; i < count; ++i) {
        numbers[i] = dis(gen);
    }
    return numbers;
}

int main() {
    // ���������
    vector<int> numbers = generateRandomNumbers(500, 1, 2000);

    // ֱ�Ӳ�������
    vector<int> numbersInsertion = numbers;
    auto startInsertion = high_resolution_clock::now();
    insertionSort(numbersInsertion);
    auto stopInsertion = high_resolution_clock::now();
    auto durationInsertion = duration_cast<microseconds>(stopInsertion - startInsertion);
    cout << "ֱ�Ӳ�����������ʱ�䣨΢�룩: " << durationInsertion.count() << endl;

    // ϣ������
    vector<int> numbersShell = numbers;
    auto startShell = high_resolution_clock::now();
    shellSort(numbersShell);
    auto stopShell = high_resolution_clock::now();
    auto durationShell = duration_cast<microseconds>(stopShell - startShell);
    cout << "ϣ����������ʱ�䣨΢�룩: " << durationShell.count() << endl;

    // ð������
    vector<int> numbersBubble = numbers;
    auto startBubble = high_resolution_clock::now();
    bubbleSort(numbersBubble);
    auto stopBubble = high_resolution_clock::now();
    auto durationBubble = duration_cast<microseconds>(stopBubble - startBubble);
    cout << "ð����������ʱ�䣨΢�룩: " << durationBubble.count() << endl;

    // ��������
    vector<int> numbersQuick = numbers;
    auto startQuick = high_resolution_clock::now();
    quickSort(numbersQuick, 0, numbersQuick.size() - 1);
    auto stopQuick = high_resolution_clock::now();
    auto durationQuick = duration_cast<microseconds>(stopQuick - startQuick);
    cout << "������������ʱ�䣨΢�룩: " << durationQuick.count() << endl;

    return 0;
}

