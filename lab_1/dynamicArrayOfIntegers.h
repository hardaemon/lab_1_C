#pragma once
#include <iostream>

class DynamicArray {
private:
    int* arr;
    size_t size;
public:
    //конструктор по умолчанию
    DynamicArray();
    //конструктор по размеру
    DynamicArray(size_t size);
    //конструктор по размеру и числу n
    DynamicArray(size_t size, int n);
    //конструктор копирования
    DynamicArray(const DynamicArray& copy);
    //конструктор перемещения
    DynamicArray(DynamicArray&& other);
    //деструктор
    ~DynamicArray();
    //длина массива
    size_t getSize() const;
    //доступ к элементу (оператор [])
    int operator[] (size_t index) const;
    int& operator[] (size_t index);
    //изменение размера
    void resize(size_t newSize);
    //оператор присваивания
    DynamicArray& operator=(const DynamicArray& other);
    //оператор перемещения
    DynamicArray& operator=(DynamicArray&& other);
    //оператор ==
    bool operator==(const DynamicArray& arr);
    //оператор !=
    bool operator!=(const DynamicArray& arr);
    //оператор <
    bool operator<(const DynamicArray& arr);
    //оператор <=
    bool operator<=(const DynamicArray& arr);
    //оператор >
    bool operator>(const DynamicArray& arr);
    //оператор >=
    bool operator>=(const DynamicArray& arr);
    //оператор +
    DynamicArray operator+(const DynamicArray& arr) const;
    //оператор ввода
    friend std::istream& operator>>(std::istream& i, DynamicArray& arr);
    //оператор вывода
    friend std::ostream& operator<<(std::ostream& o, const DynamicArray& arr);
};