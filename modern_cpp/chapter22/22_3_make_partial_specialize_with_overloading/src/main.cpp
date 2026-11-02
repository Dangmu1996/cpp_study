#include "SpreadSheetCell.hpp"
#include <iostream>
#include <cstddef>
#include <cstring>
#include <array>

using namespace std;

static const size_t NOT_FOUND = static_cast<size_t>(-1);

template <typename T>
size_t Find(const T& value, const T* arr, size_t size)
{
	cout << "original" << endl;
	for (size_t i = 0; i < size; i++) {
		if (arr[i] == value) {
			return i; 
		}
	}
	return NOT_FOUND; 
}


// overlaoding 부분 특수화 말고
template<typename T>
size_t Find(T* const& value, T* const* arr, size_t size)
{
    cout << "ptr special" << endl;
    for(size_t i = 0; i< size; i++){
        if(*arr[i] == *value){
            return i; // 값을 찾았다면 인덱스를 리턴한다.
        }
    }
    return NOT_FOUND; // 값을 찾지 못했다면 NOT_FOUND를 리턴한다.
}

// const char*에 대한 완전 특수화 버전
template<>
size_t Find<const char*>(const char* const& value, const char* const* arr, size_t size)
{
	cout << "Specialization" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; 
		}
	}
	return NOT_FOUND; 
}

size_t Find(const char* const& value, const char* const* arr, size_t size)
{
	cout << "overload" << endl;
	for (size_t i = 0; i < size; i++) {
		if (strcmp(arr[i], value) == 0) {
			return i; 
		}
	}
	return NOT_FOUND; 
}


int main()
{
    size_t res = NOT_FOUND;
    int myInt = 3, intArray[] = {1,2,3,4};
    size_t sizeArray = std::size(intArray);
    res = Find(myInt, intArray, sizeArray); //추론에 의해 Find<int>를 호출
    res = Find<int>(myInt, intArray, sizeArray); //명시적으로 Find<int>를 호출

    double myDouble = 5.6, doubleArray[] = { 1.2, 3.4, 5.7, 7.5 };
	sizeArray = std::size(doubleArray);
    res = Find(myDouble, doubleArray, sizeArray);//추론에 의해 Find<double>를 호출
    res = Find<double>(myDouble, doubleArray, sizeArray);//추론에 의해 Find<double>를 호출

    const char* word = "two";
	const char* words[] = { "one", "two", "three", "four" };
	sizeArray = std::size(words);
	res = Find<const char*>(word, words, sizeArray); // const char*s에 대한 템플릿 특수화 버전을 호출
    res = Find(word, words, sizeArray); // const char*s에 대한 오버로딩 버전을 호출

    int *intPointer = &myInt, *pointerArray[] = {&myInt, &myInt};
    sizeArray = std::size(pointerArray);
    res = Find(intPointer, pointerArray, sizeArray); // 포인터에 대한 오버로딩 버전을 호출

    SpreadsheetCell cell1(10), cellArray[] = {SpreadsheetCell(4), SpreadsheetCell(10)};
    sizeArray = std::size(cellArray);
    res = Find(cell1, cellArray, sizeArray); // 추론에 의해 Find<SpreadsheetCell>을 호출
    res = Find<SpreadsheetCell>(cell1, cellArray, sizeArray); // 명시적으로 Find<SpreadsheetCell>을 호출

    SpreadsheetCell *cellPointer = &cell1;
	SpreadsheetCell *cellPointerArray[] = { &cell1, &cell1 };
	sizeArray = std::size(cellPointerArray);
    res = Find(cellPointer, cellPointerArray, sizeArray); // 포인터에 대한 오버로딩 버전을 호출
    
    return 0;
}