#include <iostream>
#include <vector>
#include <algorithm>

struct MatHang {
    int trongLuong;
    int giaTri;
    double tiLe;
};

// Hàm so sánh các mặt hàng dựa trên tỷ lệ giá trị/trọng lượng
bool soSanh(MatHang a, MatHang b) {
    return a.tiLe > b.tiLe;
}

double giaiBaiToanCaiTui(int sucChua, std::vector<MatHang> matHang) {
    // Sắp xếp các mặt hàng dựa trên tỷ lệ giá trị/trọng lượng
    std::sort(matHang.begin(), matHang.end(), soSanh);
    
    double tongGiaTri = 0.0;
    
    for (const auto& hang : matHang) {
        if (sucChua == 0) break;  // Cái túi đã đầy
        
        if (hang.trongLuong <= sucChua) {
            // Nếu có thể lấy toàn bộ mặt hàng, lấy nó
            sucChua -= hang.trongLuong;
            tongGiaTri += hang.giaTri;
        } else {
            // Lấy một phần của mặt hàng còn lại
            tongGiaTri += hang.giaTri * ((double)sucChua / hang.trongLuong);
            sucChua = 0;
        }
    }
    
    return tongGiaTri;
}

int main() {
    // Danh sách các mặt hàng với trọng lượng và giá trị của chúng
    std::vector<MatHang> matHang = {{18, 25}, {15, 24}, {10, 25}};
    
    // Tính tỷ lệ giá trị/trọng lượng cho mỗi mặt hàng
    for (auto& hang : matHang) {
        hang.tiLe = (double)hang.giaTri / hang.trongLuong;
    }
    
    int sucChua = 20;  // Trọng lượng tối đa của cái túi
    
    double giaTriToiDa = giaiBaiToanCaiTui(sucChua, matHang);
    std::cout << "Giá trị tối đa trong cái túi: " << giaTriToiDa << std::endl;
    
    return 0;
}
