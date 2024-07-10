#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
    double ratio;
};

// Hàm so sánh hai d? v?t d?a trên t? l? giá tr?/kh?i lu?ng
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double greedyKnapsack(int W, std::vector<Item> &items) {
    // Tính t? l? giá tr?/kh?i lu?ng cho t?ng d? v?t
    for (auto &item : items) {
        item.ratio = (double)item.value / item.weight;
    }

    // S?p x?p các d? v?t theo th? t? gi?m d?n c?a t? l? giá tr?/kh?i lu?ng
    std::sort(items.begin(), items.end(), compare);

    int currentWeight = 0; // Kh?i lu?ng hi?n t?i c?a túi
    double totalValue = 0.0; // Giá tr? t?ng c?ng c?a các d? v?t dã ch?n

    // Duy?t qua các d? v?t dã s?p x?p
    for (auto &item : items) {
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // N?u không th? thêm c? d? v?t vào túi, thêm ph?n giá tr? tuong ?ng v?i ph?n kh?i lu?ng còn l?i
            int remain = W - currentWeight;
            totalValue += item.value * ((double)remain / item.weight);
            break;
        }
    }

    return totalValue;
}

int main() {
    int n, W;
    std::cout << "Nhap so luong do vat n: ";
    std::cin >> n;
    std::cout << "Nhap khoi luong toi da cua tui W: ";
    std::cin >> W;

    std::vector<Item> items(n);
    for (int i = 0; i < n; ++i) {
        std::cout << "Nhap khoi luong va gia tri cua do vat thu " << i + 1 << ": ";
        std::cin >> items[i].weight >> items[i].value;
    }

    double maxValue = greedyKnapsack(W, items);
    std::cout << "Gia tri lon nhat co the dat duoc la: " << maxValue << std::endl;

    return 0;
}

