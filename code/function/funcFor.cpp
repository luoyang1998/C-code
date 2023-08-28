#include <iostream>

int main() {
    int a[10]{10, 6, 4, 9, 3, 8, 7, 5, 1, 2};
    int temp{};
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10 - i; j++) {
            if (a[j] > a[j + 1]) {
                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;
            }
        }
    }
    for (int i = 0; i < 10; i++) {
        std::cout << a[i] << std::endl;
    }
}