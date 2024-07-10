#include <iostream>
#include <vector>


void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}


int partition(std::vector<int>& arr, int low, int high) {
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


void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
       
        int pi = partition(arr, low, high);

       
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    std::vector<int> arr = {10, 12, 20, 31, 3, 5, 15, 21, 26};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    std::cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    return 0;
}
