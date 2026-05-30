#include <iostream>
#include <vector>
class MySort{
    public:
        void selectionSort(std::vector<int> &nums);
        void bubbleSort(std::vector<int> &nums);
        void insertsort(std::vector<int> &nums);
        void quicksort(std::vector<int> &nums,int left, int right);
};