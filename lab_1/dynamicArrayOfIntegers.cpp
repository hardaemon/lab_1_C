#include "dynamicArrayOfIntegers.h"
#include "dynamicArrayError.h"

//����������� �� ���������
DynamicArray::DynamicArray() : arr(new int[0]), size(0) {}

//����������� �� �������
DynamicArray::DynamicArray(size_t size) : arr(new int[size]), size(size) {
    for (size_t i = 0; i < size; ++i) { arr[i] = 0; }
}

//����������� �� ������� � ����� n
DynamicArray::DynamicArray(size_t size, int n) : size(size) {
    arr = new int[size];
    for (size_t i = 0; i < size; ++i) { arr[i] = n; }
}
//����������� �����������
DynamicArray::DynamicArray(const DynamicArray& copy) : size(copy.size) {
    arr = new int[size];
    for (size_t i = 0; i < size; ++i) { arr[i] = copy.arr[i]; }
}
//����������� �����������
DynamicArray::DynamicArray(DynamicArray&& other) : arr(other.arr), size(other.size) {
    other.arr = nullptr;
    other.size = 0;
}
//����������
DynamicArray::~DynamicArray() { delete[] arr; }
//����� �������
size_t DynamicArray::getSize() const { return size; }
//������ � �������� (�������� [])
int DynamicArray::operator[] (size_t index) const { return arr[index]; }
int& DynamicArray::operator[] (size_t index) { return arr[index]; }
//��������� �������
void DynamicArray::resize(size_t newSize) {
    if (newSize < size) {
        int* temp = arr;
        arr = new int[newSize];
        size = newSize;
        for (size_t i = 0; i < newSize; ++i) { arr[i] = temp[i]; }
        delete[] temp;
    }
    else if (newSize > size) {
        int* temp = arr;
        arr = new int[newSize];
        for (size_t i = 0; i < size; ++i) {
            arr[i] = temp[i];
        }
        for (size_t j = size; j < newSize; ++j) { arr[j] = 0; }
        size = newSize;
        delete[] temp;
    }
}
//�������� ������������
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] arr;
        this->size = other.size;
        arr = new int[size];
        for (size_t i = 0; i < size; ++i) { arr[i] = other.arr[i]; }
    }
    return *this;
}
//�������� �����������
DynamicArray& DynamicArray::operator=(DynamicArray&& other) {
    if (this != &other) {
        delete[] arr;
        this->arr = other.arr;
        this->size = other.size;
        other.arr = nullptr;
        other.size = 0;
    }
    return *this;
}
//�������� ==
bool DynamicArray::operator==(const DynamicArray& arr) {
    if (this->getSize() != arr.getSize()) { throw Error("������� �������� �� ���������"); }
    else {
        for (size_t i = 0; i < this->getSize(); ++i) {
            if (this->arr[i] != arr[i]) { return false; }
        }
        return true;
    }
}
//�������� !=
bool DynamicArray::operator!=(const DynamicArray& arr) {
    if (this->getSize() != arr.getSize()) { throw Error("������� �������� �� ���������"); }
    else {
        for (size_t i = 0; i < this->getSize(); ++i) {
            if (this->arr[i] == arr[i]) { return false; }
        }
        return true;
    }
}
//�������� <
bool DynamicArray::operator<(const DynamicArray& arr) {
    for (size_t i = 0; i < std::min(this->getSize(), arr.getSize()); ++i)
    {
        if (this->arr[i] > arr[i]) { return false; }
        else if (this->arr[i] < arr[i]) { return true; }
    }
    return (this->getSize() < arr.getSize());
}
//�������� <=
bool DynamicArray::operator<=(const DynamicArray& arr) {
    for (size_t i = 0; i < std::min(this->getSize(), arr.getSize()); ++i)
    {
        if (this->arr[i] > arr[i]) { return false; }
    }
    return true;
}
//�������� >
bool DynamicArray::operator>(const DynamicArray& arr) {
    for (size_t i = 0; i < std::min(this->getSize(), arr.getSize()); ++i)
    {
        if (this->arr[i] < arr[i]) { return false; }
        if (this->arr[i] > arr[i]) { return true; }
    }
    return (this->getSize() > arr.getSize());
}
//�������� >=
bool DynamicArray::operator>=(const DynamicArray& arr) {
    for (size_t i = 0; i < std::min(this->getSize(), arr.getSize()); ++i)
    {
        if (this->arr[i] < arr[i]) { return false; }
    }
    return true;
}
//�������� +
DynamicArray DynamicArray::operator+(const DynamicArray& arr) const
{
    DynamicArray result(this->getSize() + arr.getSize());
    for (size_t i = 0; i < this->getSize(); ++i) { result[i] = this->arr[i]; }
    for (size_t i = 0; i < this->getSize(); ++i) {
        result[this->getSize() + i] = arr[i];
    }
    return result;
}
//�������� �����
std::istream& operator>>(std::istream& i, DynamicArray& arr) {
    std::cout << "������� ������ �������: ";
    size_t newSize;
    i >> newSize;
    arr.resize(newSize);
    std::cout << "������� " + std::to_string(newSize) + " ��������� �������: ";
    for (size_t j = 0; j < arr.getSize(); ++j) {
        i >> arr[j];
    }
    return i;
}
//�������� ������
std::ostream& operator<<(std::ostream& o, const DynamicArray& arr)
{
    o << "[ ";
    for (size_t i = 0; i < arr.getSize(); ++i) { o << arr[i] << " "; }
    o << "]";
    return o;
}