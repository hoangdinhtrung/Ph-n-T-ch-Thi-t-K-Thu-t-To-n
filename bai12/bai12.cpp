#include <iostream>
#include <vector>
#include <algorithm>

struct Item {
    int weight;
    int value;
    double ratio;
};

// H�m so s�nh hai d? v?t d?a tr�n t? l? gi� tr?/kh?i lu?ng
bool compare(Item a, Item b) {
    return a.ratio > b.ratio;
}

double greedyKnapsack(int W, std::vector<Item> &items) {
    // T�nh t? l? gi� tr?/kh?i lu?ng cho t?ng d? v?t
    for (auto &item : items) {
        item.ratio = (double)item.value / item.weight;
    }

    // S?p x?p c�c d? v?t theo th? t? gi?m d?n c?a t? l? gi� tr?/kh?i lu?ng
    std::sort(items.begin(), items.end(), compare);

    int currentWeight = 0; // Kh?i lu?ng hi?n t?i c?a t�i
    double totalValue = 0.0; // Gi� tr? t?ng c?ng c?a c�c d? v?t d� ch?n

    // Duy?t qua c�c d? v?t d� s?p x?p
    for (auto &item : items) {
        if (currentWeight + item.weight <= W) {
            currentWeight += item.weight;
            totalValue += item.value;
        } else {
            // N?u kh�ng th? th�m c? d? v?t v�o t�i, th�m ph?n gi� tr? tuong ?ng v?i ph?n kh?i lu?ng c�n l?i
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

