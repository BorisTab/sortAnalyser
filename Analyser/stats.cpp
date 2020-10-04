//
// Created by boris on 08.09.2020.
//

#include "stats.h"

size_t Stats::comparisonsNum = 0;
size_t Stats::changeNum = 0;

Stats::Stats(int sortId, size_t arrayLen): sortId(sortId), arrayLen(arrayLen) {
    array = new int[arrayLen];
    arrayGen();
    bubbleSort();
}

Stats::~Stats() {
    delete[] array;
}

void Stats::bubbleSort() {
    comparisonsNum = 0;
    changeNum = 0;

    int i, j;
    for (i = 0; i < arrayLen-1; ++i) {
        for (j = 0; j < arrayLen-i-1; ++j) {
            if (compare(array[j], array[j+1]))
                swap(array[j], array[j+1]);
        }
    }
}

bool Stats::compare(int &first, int &second) {
    ++comparisonsNum;
    return first > second;
}

void Stats::swap(int &first, int &second) {
    ++changeNum;

    int tmp = first;
    first = second;
    second = tmp;
}

void Stats::arrayGen() {
    for (size_t i = 0; i < arrayLen; ++i) {
        array[i] = std::rand();
    }
}

void Stats::printInfo() {
    printf("Len: %6zu | Com: %6zu | Xcg: %6zu\n", arrayLen, comparisonsNum, changeNum);
}
