#include <iostream>

int linear_search(int arr[], int size, int target) {
    for (int index = 0; index < size; ++index) {
        if (arr[index] == target) {
            return index; // ���������� ������ ���������� ��������
        }
    }
    return -1; // ���� ������� �� ������
}

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // ������� ������� ������
        if (arr[mid] == target) {
            return mid; // ���������� ������ ���������� ��������
        }
        else if (arr[mid] < target) {
            left = mid + 1; // ���� � ������ ��������
        }
        else {
            right = mid - 1; // ���� � ����� ��������
        }
    }
    return -1; // ���� ������� �� ������
}

int interpolation_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                return low; // ���������� ������ ���������� ��������
            }
            return -1; // ���� ������� �� ������
        }

        // ��������� �������
        int pos = low + ((high - low) / (arr[high] - arr[low]) * (target - arr[low]));

        if (arr[pos] == target) {
            return pos; // ���������� ������ ���������� ��������
        }
        if (arr[pos] < target) {
            low = pos + 1; // ���� � ������ ��������
        }
        else {
            high = pos - 1; // ���� � ����� ��������
        }
    }
    return -1; // ���� ������� �� ������
}

int main() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]); // ���������� ������ �������
    int target = 3;

    cout << "�������� �����: " << linear_search(arr, size, target) << std::endl;
    cout << "�������� �����: " << binary_search(arr, size, target) << std::endl;
    cout << "���������������� �����: " << interpolation_search(arr, size, target) << std::endl;

    return 0;
}

