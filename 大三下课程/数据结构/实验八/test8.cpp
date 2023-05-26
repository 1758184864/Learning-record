#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

// ��ӡ����
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// ֱ�Ӳ�������
void insertionSort(int arr[], int size) {
    int i, key, j;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// ϣ������
void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}

// ð������
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// ���������еķ�������
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

// ��������
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    const int size = 500;
    int arr[size];

    srand(time(0));

    // �����������
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 2000 + 1;
    }

    cout << "ԭʼ���飺" << endl;
    printArray(arr, size);

    // ֱ�Ӳ�������
    clock_t start = clock();
    insertionSort(arr, size);
    clock_t finish = clock();
    double insertionSortTime = double(finish - start) / CLOCKS_PER_SEC;
    cout << "ֱ�Ӳ�������ʱ�䣺" << insertionSortTime << " ��" << endl;
    printArray(arr, size);

    // ���������������
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 2000 + 1;
    }

    // ϣ������
    start = clock();
    shellSort(arr, size);
    shellSort(arr, size);
    finish = clock();
    double shellSortTime = double(finish - start) / CLOCKS_PER_SEC;
    cout << "ϣ������ʱ�䣺" << shellSortTime << " ��" << endl;
    printArray(arr, size);

    // ���������������
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 2000 + 1;
    }

    // ð������
    start = clock();
    bubbleSort(arr, size);
    bubbleSort(arr, size);
    finish = clock();
    double bubbleSortTime = double(finish - start) / CLOCKS_PER_SEC;
    cout << "ð������ʱ�䣺" << bubbleSortTime << " ��" << endl;
    printArray(arr, size);

    // ���������������
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 2000 + 1;
    }

    // ��������
    start = clock();
    quickSort(arr, 0, size - 1);
    quickSort(arr, 0, size - 1);
    finish = clock();
    double quickSortTime = double(finish - start) / CLOCKS_PER_SEC;
    cout << "��������ʱ�䣺" << quickSortTime << " ��" << endl;
    printArray(arr, size);

    return 0;
}
