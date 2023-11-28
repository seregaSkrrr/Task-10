#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
namespace SortUtils {

    template <typename T>
    void bubbleSort(std::vector<T>& arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    std::swap(arr[j], arr[j + 1]);
                }
            }
        }
    }

    template <typename T>
    void InsertionSort(std::vector<T>& arr) {
        int n = arr.size();
        for (int i = 1; i < n; ++i) {
            T key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key) {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
    }

    template <typename T>
    int quickSortdef(std::vector<T>& arr, int low, int high) {
        T pivot = arr[high];
        int i = (low - 1);
        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        std::swap(arr[i + 1], arr[high]);
        return (i + 1);
    }

    template <typename T>
    void quicksort(std::vector<T>& arr, int low, int high) {
        if (low < high) {
            int pi = quickSortdef(arr, low, high);
            quicksort(arr, low, pi - 1);
            quicksort(arr, pi + 1, high);
        }
    }
}

class MyClass {
public:
    std::string name;
    int age;

    MyClass(std::string name, int age) : name(name), age(age) {}

    bool operator < (const MyClass& other) const {
        return age < other.age;
    }
};

using namespace SortUtils;

int main() {
    setlocale(LC_ALL, "RU");
    std::vector<int> arr = { 64, 34, 25, 12, 22, 11, 90 };
    std::cout << "Ну типа не сортированный: ";
    for (auto val : arr) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;
    SortUtils::bubbleSort(arr);
    std::cout << "ббаулауахухлбуахлбаух сёрт: ";
    for (auto val : arr) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    std::vector<int> arr2 = { 64, 34, 25, 12, 22, 11, 90 };
    SortUtils::InsertionSort(arr2);
    std::cout << "Инсёрьт сёрт: ";
    for (auto val : arr2) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    std::vector<int> arr3 = { 64, 34, 25, 12, 22, 11, 90 };
    SortUtils::quicksort(arr3, 0, arr3.size() - 1);
    std::cout << "Типа квик сёрт: ";
    for (auto val : arr3) {
        std::cout << val << ", ";
    }
    std::cout << std::endl;

    std::vector<MyClass> temper = {
        MyClass("Bob", 34),
        MyClass("Alice", 25),
        MyClass("Tom", 12),
        MyClass("John", 22),
        MyClass("Mark", 11),
        MyClass("Mike", 90)
    };
    SortUtils::quicksort(temper, 0, temper.size() - 1);
    std::cout << "Быстри сёрьт челов по возрасту: ";
    for (auto val : temper) {
        std::cout << val.name << " (" << val.age << ") ";
    }
    std::cout << std::endl;

    return 0;
}
