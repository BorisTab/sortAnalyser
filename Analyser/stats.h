//
// Created by boris on 08.09.2020.
//
#include <iostream>

class Stats {
public:
    Stats(int sortId, size_t arrayLen);
    ~Stats();

    void printInfo();

private:
    int* array = nullptr;
    size_t arrayLen = 0;
    static size_t comparisonsNum;
    static size_t changeNum;
    int sortId = 0;

    void bubbleSort();

    bool compare(int& first, int& second);
    void swap(int& first, int& second);

    void arrayGen();
};
