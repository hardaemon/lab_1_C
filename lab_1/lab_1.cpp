#include "dynamicArrayOfIntegers.h"
int main() {
    setlocale(LC_ALL, "RUS");
    DynamicArray arr1;
    //Проверка конструктора по умолчанию
    std::string flag1 = "true";
    if (arr1.getSize() != 0) { flag1 = "false"; }
    std::cout << "Проверка конструктора по умолчанию         - " + flag1 << std::endl;
    //Проверка конструктора по размеру
    std::string flag2 = "true";
    DynamicArray arr2(10);
    if (arr2.getSize() != 10) { flag2 = "false"; }
    for (size_t i = 0; i < 10; ++i) {
        if (arr2[i] != 0) { flag2 = "false"; }
    }
    std::cout << "Проверка конструктора по размеру           - " + flag2 << std::endl;
    //Проверка конструктора по размеру и числу n
    std::string flag3 = "true";
    DynamicArray arr3(15, 7);
    if (arr3.getSize() != 15) { flag3 = "false"; }
    for (size_t i = 0; i < 15; ++i) {
        if (arr3[i] != 7) { flag3 = "false"; }
    }
    std::cout << "Проверка конструктора по размеру и числу n - " + flag3 << std::endl;
    //Проверка конструктора копирования
    std::string flag4 = "true";
    DynamicArray arr4(arr3);
    if (arr4.getSize() != arr3.getSize()) { flag4 = "false"; }
    for (size_t i = 0; i < arr4.getSize(); ++i) {
        if (arr4[i] != arr3[i]) { flag4 = "false"; }
    }
    std::cout << "Проверка конструктора копирования          - " + flag4 << std::endl;
    //Проверка конструктора перемещения
    std::string flag5 = "true";
    DynamicArray arr5(std::move(arr4));
    if (arr4.getSize() != 0) { flag5 = "false"; }
    if (arr5.getSize() != 15) { flag5 = "false"; }
    for (size_t i = 0; i < arr5.getSize(); ++i) {
        if (arr5[i] != 7) { flag5 = "false"; }
    }
    std::cout << "Проверка конструктора перемещения          - " + flag5 << std::endl;
    //Проверка на получение длины массива
    std::string flag6 = "true";
    if (arr5.getSize() != 15) { flag6 = "false"; }
    std::cout << "Проверка на получение длины массива        - " + flag6 << std::endl;
    //Проверка на доступ к элементу
    std::string flag7_1 = "true";
    if (arr5[3] != 7) { flag7_1 = "false"; }
    std::cout << "Проверка на доступ к элементу (получение)  - " + flag7_1 << std::endl;
    std::string flag7_2 = "true";
    arr5[0] = 1;
    if (arr5[0] != 1) { flag7_2 = "false"; }
    std::cout << "Проверка на доступ к элементу (запись)     - " + flag7_2 << std::endl;
    //Проверка на изменение размера
    std::string flag8_1 = "true";
    DynamicArray arr6(3);
    arr6[0] = 1;
    arr6[1] = 2;
    arr6[2] = 3;
    arr6.resize(10);
    if (arr6.getSize() != 10) { flag8_1 = "false"; }
    if (arr6[0] != 1) { flag8_1 = "false"; }
    if (arr6[1] != 2) { flag8_1 = "false"; }
    if (arr6[2] != 3) { flag8_1 = "false"; }
    for (size_t i = 3; i < 10; ++i) {
        if (arr6[i] != 0) { flag8_1 = "false"; }
    }
    std::cout << "Проверка на изменение размера (увеличение) - " + flag8_1 << std::endl;
    std::string flag8_2 = "true";
    arr6.resize(2);
    if (arr6.getSize() != 2) { flag8_2 = "false"; }
    if (arr6[0] != 1) { flag8_2 = "false"; }
    if (arr6[1] != 2) { flag8_2 = "false"; }
    std::cout << "Проверка на изменение размера (уменьшение) - " + flag8_2 << std::endl;
    //Проверка оператора присваивания
    std::string flag9 = "true";
    DynamicArray arr7(3, 10);
    DynamicArray arr8 = arr7;
    if (arr8.getSize() != arr7.getSize()) { flag9 = "false"; }
    for (size_t i = 0; i < arr7.getSize(); ++i) {
        if (arr8[i] != arr7[i]) { flag9 = "false"; }
    }
    std::cout << "Проверка оператора присваивания            - " + flag9 << std::endl;
    //Проверка оператора перемещения
    std::string flag10 = "true";
    DynamicArray arr10 = DynamicArray(3, 10);
    if (arr10.getSize() != 3) { flag10 = "false"; }
    // if (arr9.getSize() != 0) { flag10 = "false"; }
    for (size_t i = 0; i < arr10.getSize(); ++i) {
        if (arr10[i] != 10) { flag10 = "false"; }
    }
    std::cout << "Проверка оператора перемещения             - " + flag10 << std::endl;
    //Проверка оператора ==
    DynamicArray arr11(3, 10);
    DynamicArray arr12(3, 10);
    try {
        if (arr11 == arr12) {
            std::cout << "Проверка оператора ==                      - true" << std::endl;
        }
        else {
            std::cout << "Проверка оператора ==                      - false" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
    }
    DynamicArray arr13(4, 10);
    std::cout << "Проверка оператора == на исключение:" << std::endl;
    try {
        arr12 == arr13;
        std::cout << "Проверка оператора ==                      - false" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
    }
    //Проверка оператора !=
    DynamicArray arr14(3, 10);
    DynamicArray arr15(3, 7);
    try {
        if (arr14 != arr15) {
            std::cout << "Проверка оператора !=                      - true" << std::endl;
        }
        else {
            std::cout << "Проверка оператора !=                      - false" << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
    }
    DynamicArray arr16(4, 10);
    std::cout << "Проверка оператора != на исключение:" << std::endl;
    try {
        arr15 != arr16;
        std::cout << "Проверка оператора !=                      - false" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << ">>>>> Исключение! Ошибка: " << e.what() << std::endl;
    }
    //Проверка оператора <
    std::string flag11 = "false";
    DynamicArray arr17(3, 7);
    DynamicArray arr18(4, 10);
    if (arr17 < arr18) { flag11 = "true"; }
    std::cout << "Проверка оператора <                       - " + flag11 << std::endl;
    std::string flag11_1 = "false";
    DynamicArray arr17_t(4, 10);
    arr17_t[3] = 7;
    DynamicArray arr18_t(4, 10);
    if (arr17_t < arr18_t) { flag11_1 = "true"; }
    std::cout << "Проверка оператора <                       - " + flag11_1 << std::endl;
    //Проверка оператора <=
    std::string flag12 = "false";
    DynamicArray arr19(4, 10);
    if (arr17 <= arr18) { flag12 = "true"; }
    if (arr18 <= arr19) { flag12 = "true"; }
    std::cout << "Проверка оператора <=                      - " + flag12 << std::endl;
    //Проверка оператора >
    std::string flag13 = "false";
    if (arr18 > arr17) { flag13 = "true"; }
    std::cout << "Проверка оператора >                       - " + flag13 << std::endl;
    //Проверка оператора >=
    std::string flag14 = "false";
    if (arr18 >= arr17) { flag14 = "true"; }
    if (arr18 >= arr19) { flag14 = "true"; }
    std::cout << "Проверка оператора <=                      - " + flag14 << std::endl;
    //Проверка оператора +
    std::string flag15 = "true";
    DynamicArray arr20(4, 10);
    DynamicArray arr21(5, 7);
    DynamicArray arr22(9);
    for (size_t i = 0; i < 4; ++i) { arr22[i] = 10; }
    for (size_t i = 4; i < 9; ++i) { arr22[i] = 7; }
    DynamicArray arr23 = arr20 + arr21;
    if (arr23 != arr22) { flag15 = "false"; }
    std::cout << "Проверка оператора +                       - " + flag15 << std::endl;
    //Проверка оператора ввода
    DynamicArray arr24;
    std::cin >> arr24;
    //Проверка оператора вывода
    std::cout << arr24 << std::endl;
}