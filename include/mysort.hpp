#include <iostream>
#include <vector>
class MySort{
    public:
        void selectionSort(std::vector<int> &nums);
        void bubbleSort(std::vector<int> &nums);
        void insertsort(std::vector<int> &nums);
        void quicksort(std::vector<int> &nums,int left, int right);
        void mergesort(std::vector<int> &nums,int left,int right);
        void mergesortnr(std::vector<int> &nums,int left,int right);
        void heapSort(std::vector<int> &nums);
        void heapSortnr(std::vector<int> &nums);
};