#include "mysort.hpp"
#include <utility>
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
/*插入排序（小数据用插入） ------时间复杂度O(n^2)，类似于整理扑克牌*/
void MySort::insertsort(std::vector<int> &nums) {
    // 外循环：未排序区间
    for (int i = 1; i < nums.size(); i++) {
        int base = nums[i], j = i - 1;
        // 内循环：j为有序区间最大值下标，如果排序区间元素大于基准，需要将其往后移动，
        // 将 base 插入到已排序部分的正确位置
        while (j >= 0 && nums[j] > base) {
            nums[j + 1] = nums[j]; // 将 nums[j] 向右移动一位
            j--;
        }
        nums[j + 1] = base; // 将 base 赋值到正确位置
    }
}
/*快速排序 ------时间复杂度O(n log n)，最坏O(n²)，分治思想的经典体现*/
void MySort::quicksort(std::vector<int> &nums,int left,int right) {
    if (left>=right) { //左>=右,代表区间为1，有序
        return;
    }
    //快速排序优化思路----基准值选取可以随机化，选取基准值后与区间最左端元素互换
    int mid=left+(right-left)/2;
    std::swap(nums[mid],nums[left]);
    int p=nums[left];// 基准值--用于分区比较
    int i=left;
    int j=right;
    while (i<j) {
        while (nums[j]>=p && i<j) { //寻找nums[j]<p的值的下标，如果没有，就会在mid处停下来
            j--;
        }
        std::swap(nums[i],nums[j]);
        while (nums[i]<=p && i<j) { //寻找nums[i]>p的值的下标，如果没有，就会在mid处停下来
            i++;
        }
        std::swap(nums[i],nums[j]);
    }
    nums[i]=p;
    quicksort(nums, left, i-1);
    quicksort(nums, i+1, right);
}
