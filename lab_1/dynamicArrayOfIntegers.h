#pragma once
#include <iostream>

class DynamicArray {
private:
    int* arr;
    size_t size;
public:
    //����������� �� ���������
    DynamicArray();
    //����������� �� �������
    DynamicArray(size_t size);
    //����������� �� ������� � ����� n
    DynamicArray(size_t size, int n);
    //����������� �����������
    DynamicArray(const DynamicArray& copy);
    //����������� �����������
    DynamicArray(DynamicArray&& other);
    //����������
    ~DynamicArray();
    //����� �������
    size_t getSize() const;
    //������ � �������� (�������� [])
    int operator[] (size_t index) const;
    int& operator[] (size_t index);
    //��������� �������
    void resize(size_t newSize);
    //�������� ������������
    DynamicArray& operator=(const DynamicArray& other);
    //�������� �����������
    DynamicArray& operator=(DynamicArray&& other);
    //�������� ==
    bool operator==(const DynamicArray& arr);
    //�������� !=
    bool operator!=(const DynamicArray& arr);
    //�������� <
    bool operator<(const DynamicArray& arr);
    //�������� <=
    bool operator<=(const DynamicArray& arr);
    //�������� >
    bool operator>(const DynamicArray& arr);
    //�������� >=
    bool operator>=(const DynamicArray& arr);
    //�������� +
    DynamicArray operator+(const DynamicArray& arr) const;
    //�������� �����
    friend std::istream& operator>>(std::istream& i, DynamicArray& arr);
    //�������� ������
    friend std::ostream& operator<<(std::ostream& o, const DynamicArray& arr);
};