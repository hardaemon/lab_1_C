#include "dynamicArrayOfIntegers.h"
#include "dynamicArrayError.h"

//êîíñòðóêòîð ïî óìîë÷àíèþ
DynamicArray::DynamicArray() : arr(new int[0]), size(0) {}

//êîíñòðóêòîð ïî ðàçìåðó
DynamicArray::DynamicArray(size_t size) : arr(new int[size]), size(size) {
    for (size_t i = 0; i < size; ++i) { arr[i] = 0; }
}

//êîíñòðóêòîð ïî ðàçìåðó è ÷èñëó n
DynamicArray::DynamicArray(size_t size, int n) : size(size) {
    arr = new int[size];
    for (size_t i = 0; i < size; ++i) { arr[i] = n; }
}
//êîíñòðóêòîð êîïèðîâàíèÿ
DynamicArray::DynamicArray(const DynamicArray& copy) : size(copy.size) {
    arr = new int[size];
    for (size_t i = 0; i < size; ++i) { arr[i] = copy.arr[i]; }
}
//êîíñòðóêòîð ïåðåìåùåíèÿ
DynamicArray::DynamicArray(DynamicArray&& other) : arr(other.arr), size(other.size) {
    other.arr = nullptr;
    other.size = 0;
}
//äåñòðóêòîð
DynamicArray::~DynamicArray() { delete[] arr; }
//äëèíà ìàññèâà
size_t DynamicArray::getSize() const { return size; }
//äîñòóï ê ýëåìåíòó (îïåðàòîð [])
int DynamicArray::operator[] (size_t index) const { return arr[index]; }
int& DynamicArray::operator[] (size_t index) { return arr[index]; }
//èçìåíåíèå ðàçìåðà
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
//îïåðàòîð ïðèñâàèâàíèÿ
DynamicArray& DynamicArray::operator=(const DynamicArray& other) {
    if (this != &other) {
        delete[] arr;
        this->size = other.size;
        arr = new int[size];
        for (size_t i = 0; i < size; ++i) { arr[i] = other.arr[i]; }
    }
    return *this;
}
//îïåðàòîð ïåðåìåùåíèÿ
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
//îïåðàòîð ==
bool DynamicArray::operator==(const DynamicArray& arr) {
    if (this->getSize() != arr.getSize()) { throw Error("Ðàçìåðû ìàññèâîâ íå ñîâïàäàþò"); }
    else {
        for (size_t i = 0; i < this->getSize(); ++i) {
            if (this->arr[i] != arr[i]) { return false; }
        }
        return true;
    }
}
//îïåðàòîð !=
bool DynamicArray::operator!=(const DynamicArray& arr) {
    if (this->getSize() != arr.getSize()) { throw Error("Ðàçìåðû ìàññèâîâ íå ñîâïàäàþò"); }
    else {
        for (size_t i = 0; i < this->getSize(); ++i) {
            if (this->arr[i] == arr[i]) { return false; }
        }
        return true;
    }
}
//îïåðàòîð <
bool DynamicArray::operator<(const DynamicArray& arr) {
    for (size_t i = 0; i < std::min(this->getSize(), arr.getSize()); ++i)
    {
        if (this->arr[i] > arr[i]) { return false; }
        else if (this->arr[i] < arr[i]) { return true; }
    }
    return (this->getSize() < arr.getSize());
}
//îïåðàòîð <=
bool DynamicArray::operator<=(const DynamicArray& arr) {
    for (size_t i = 0; i < std::min(this->getSize(), arr.getSize()); ++i)
    {
        if (this->arr[i] > arr[i]) { return false; }
    }
    return true;
}
//îïåðàòîð >
bool DynamicArray::operator>(const DynamicArray& arr) {
    for (size_t i = 0; i < std::min(this->getSize(), arr.getSize()); ++i)
    {
        if (this->arr[i] < arr[i]) { return false; }
        if (this->arr[i] > arr[i]) { return true; }
    }
    return (this->getSize() > arr.getSize());
}
//îïåðàòîð >=
bool DynamicArray::operator>=(const DynamicArray& arr) {
    for (size_t i = 0; i < std::min(this->getSize(), arr.getSize()); ++i)
    {
        if (this->arr[i] < arr[i]) { return false; }
    }
    return true;
}
//îïåðàòîð +
DynamicArray DynamicArray::operator+(const DynamicArray& arr) const
{
    DynamicArray result(this->getSize() + arr.getSize());
    for (size_t i = 0; i < this->getSize(); ++i) { result[i] = this->arr[i]; }
    for (size_t i = 0; i < this->getSize(); ++i) {
        result[this->getSize() + i] = arr[i];
    }
    return result;
}
//îïåðàòîð ââîäà
std::istream& operator>>(std::istream& i, DynamicArray& arr) {
    std::cout << "Ââåäèòå ðàçìåð ìàññèâà: ";
    size_t newSize;
    i >> newSize;
    arr.resize(newSize);
    std::cout << "Ââåäèòå " << newSize << " ýëåìåíòîâ ìàññèâà: ";
    for (size_t j = 0; j < arr.getSize(); ++j) {
        i >> arr[j];
    }
    return i;
}
//îïåðàòîð âûâîäà
std::ostream& operator<<(std::ostream& o, const DynamicArray& arr)
{
    o << "[ ";
    for (size_t i = 0; i < arr.getSize(); ++i) { o << arr[i] << " "; }
    o << "]";
    return o;
}
