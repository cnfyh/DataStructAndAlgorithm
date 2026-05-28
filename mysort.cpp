#include "mysort.hpp"
/*选择排序---时间复杂度O(n^2) 从未排序区间中选取最小值放置到区间头部地方*/
void MySort::selectionSort(std::vector<int> &nums){
    int end = nums.size();
    for (int i = 0; i < end - 1; i++) {
        int min_index = i;
        for (int j = i + 1; j < end; j++) {
            if (nums[j] < nums[min_index]) {
                min_index = j;
            }
        }
        if (min_index != i) {
            std::swap(nums[i], nums[min_index]);
        }
    }
}
/*冒泡排序 ---时间复杂度O(n^2) 将每轮最大的数排到最后面*/
void MySort::bubbleSort(std::vector<int> &nums){
    int end=nums.size();
    for (int i=end-1; i>0; i--) {
        for (int j=0; j<i; j++) {
            if (nums[j]>nums[j+1]) {
                std::swap(nums[j],nums[j+1]);
            }
        }
    }
}
