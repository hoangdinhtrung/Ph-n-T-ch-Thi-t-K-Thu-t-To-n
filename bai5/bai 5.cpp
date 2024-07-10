#include <iostream>
#include <vector>

int countPartitions(int n) {
    // T?o m?ng luu tr? k?t qu? ph�n t�ch
    std::vector<int> P(n + 1, 0);
    
    // Kh?i t?o gi� tr? ban d?u
    P[0] = 1;
    
    // T�nh s? lu?ng ph�n t�ch cho t?ng s? t? 1 d?n n
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= i; ++j) {
            P[i] += P[i - j];
        }
    }
    
    return P[n];
}

int main() {
    int n;
    std::cout << "Nhap so tu nhien n < 100: ";
    std::cin >> n;
    
    if (n < 100) {
        int result = countPartitions(n);
        std::cout << "So cach phan tich " << n << " thanh tong cac so nguyen duong la: " << result << std::endl;
    } else {
        std::cout << "Gia tri n phai nho hon 100." << std::endl;
    }
    
    return 0;
}

