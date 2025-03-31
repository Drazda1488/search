#include <iostream>

int linear_search(int arr[], int size, int target) {
    for (int index = 0; index < size; ++index) {
        if (arr[index] == target) {
            return index; // Возвращаем индекс найденного элемента
        }
    }
    return -1; // Если элемент не найден
}

int binary_search(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // Находим средний индекс
        if (arr[mid] == target) {
            return mid; // Возвращаем индекс найденного элемента
        }
        else if (arr[mid] < target) {
            left = mid + 1; // Ищем в правой половине
        }
        else {
            right = mid - 1; // Ищем в левой половине
        }
    }
    return -1; // Если элемент не найден
}

int interpolation_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high && target >= arr[low] && target <= arr[high]) {
        if (low == high) {
            if (arr[low] == target) {
                return low; // Возвращаем индекс найденного элемента
            }
            return -1; // Если элемент не найден
        }

        // Вычисляем позицию
        int pos = low + ((high - low) / (arr[high] - arr[low]) * (target - arr[low]));

        if (arr[pos] == target) {
            return pos; // Возвращаем индекс найденного элемента
        }
        if (arr[pos] < target) {
            low = pos + 1; // Ищем в правой половине
        }
        else {
            high = pos - 1; // Ищем в левой половине
        }
    }
    return -1; // Если элемент не найден
}

int main() {
    using namespace std;
    setlocale(LC_ALL, "RU");
    int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int size = sizeof(arr) / sizeof(arr[0]); // Определяем размер массива
    int target = 3;

    cout << "Линейный поиск: " << linear_search(arr, size, target) << std::endl;
    cout << "Бинарный поиск: " << binary_search(arr, size, target) << std::endl;
    cout << "Интерполяционный поиск: " << interpolation_search(arr, size, target) << std::endl;

    return 0;
}

