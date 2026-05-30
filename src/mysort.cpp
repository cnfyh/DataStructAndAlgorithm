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
/*归并排序  递归版*/
void MySort::mergesort(std::vector<int> &nums,int left,int right){
    auto merge=[&nums](int left,int mid,int right){
        //临时数组
        std::vector<int>temp(right-left+1);
        int i=left;
        int j=mid+1;
        int k=0;
        //二者均为到边界时归并到临时数组
        while (i<=mid && j<=right) {
            if (nums[i]<=nums[j]) {
                temp[k++]=nums[i++];
            }else{
                temp[k++]=nums[j++];
            }
        }
        //将剩余有序元素赋值到临时数组中
        while (i<=mid) {
            temp[k++]=nums[i++];
        }
        while (j<=right) {
            temp[k++]=nums[j++];
        }
        //将临时数组值覆盖到原数组
        for (int i=0; i<k; i++) {
            nums[left+i]=temp[i];
        }
    };
    if (left>=right) {
        return;
    }
    int mid=left+(right-left)/2;
    //递归划分左右子树
    mergesort(nums, left,  mid);
    mergesort(nums, mid+1,  right);
    //归并
    merge(left,mid,right);
}
/*归并排序  非递归版（自底向上迭代）*/
void MySort::mergesortnr(std::vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    auto merge = [&nums](int left, int mid, int right) {
        std::vector<int> temp(right - left + 1);
        int i = left;
        int j = mid + 1;
        int k = 0;
        while (i <= mid && j <= right) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }
        while (i <= mid) {
            temp[k++] = nums[i++];
        }
        while (j <= right) {
            temp[k++] = nums[j++];
        }
        for (int idx = 0; idx < k; ++idx) {
            nums[left + idx] = temp[idx];
        }
    };
    int n = right - left + 1;
    // width: 已经排好序的数组宽度，初始时1个数为有序，每轮由于归并，会时其翻倍
    for (int width = 1; width < n; width = 2*width) {
        // 每次处理相邻的两个子数组 [l, mid] 和 [mid+1, r]
        for (int l = left; l < right; l = 2 * width + l) {
            //正常情况下左边界为l + width - 1，右边界为right，但是循环中会有越界现象
            //std::min防止越界
            int mid = std::min(l + width - 1, right);
            int r   = std::min(l + 2 * width - 1, right);
            //当不存在右边界时，跳过
            if (mid < right) {
                merge(l, mid, r);
            }
        }
    }
}
/*堆排序  --小顶堆(空间复杂度为O(n))*/
void MySort::heapSort(std::vector<int> &nums){
    std::vector<int> heaparr;
    auto leftindex=[](int pindex)->int{
        return 2*pindex+1;
    };
    auto rightindex=[](int pindex)->int{
        return 2*pindex+2;
    };
    auto pindex=[](int childindex)->int{
        return (childindex-1)/2;
    };
    auto heap_push=[&](int val){
        heaparr.push_back(val);
        int valindex=heaparr.size()-1;
        while (valindex>0) {
            int p=pindex(valindex);
            if (val<heaparr[p]) {
                std::swap(heaparr[p],heaparr[valindex]);
                valindex=p;
            }else {
                break;
            }
        }
    };
    auto heap_pop=[&]()->int{
        int res=heaparr[0];
        std::swap(heaparr[0],heaparr[heaparr.size()-1]);
        heaparr.pop_back();
        int root=0;
        while (1) {
            int target=root;
            int l=leftindex(target);
            int r=rightindex(target);
            if (l< heaparr.size()) { //判断是否越界
                if (heaparr[target]>heaparr[l]) {
                    target=l;
                }
            }
            if (r< heaparr.size()) { //判断是否越界
                if (heaparr[target]>heaparr[r]) {
                    target=r;
                }
            }
            //如果到达叶子节点，左右孩子都越界，那么tar==root
            if (target == root) break; 
            std::swap(heaparr[root], heaparr[target]);
            root = target;
        }
        return res;
    };
    for (int i=0; i<nums.size(); i++) {
        heap_push(nums[i]);
    }
    for (int i=0; i<nums.size(); i++) {
        nums[i]=heap_pop();
    }
}
/*堆排序  --大顶堆(原地排序，无需要额外空间)*/
/*
构建一个大顶堆，然后将堆顶与堆底互换，然后size-1，再次执行构建
*/
void MySort::heapSortnr(std::vector<int> &nums){
    auto leftindex=[](int pindex)->int{
        return 2*pindex+1;
    };
    auto rightindex=[](int pindex)->int{
        return 2*pindex+2;
    };
    auto pindex=[](int childindex)->int{
        return (childindex-1)/2;
    };
    auto heapSort=[&leftindex,&rightindex,&pindex](std::vector<int> &nums,int size){
        int p=pindex(size-1);
        for (int i=p; i>=0; i--) {
            while (1) {
                int root=i;
                int target=root;
                int l=leftindex(target);
                int r=rightindex(target);
                if (l< size) { //判断是否越界
                    if (nums[target]<nums[l]) {
                        target=l;
                    }
                }
                if (r< size) { //判断是否越界
                    if (nums[target]<nums[r]) {
                        target=r;
                    }
                }
                //如果到达叶子节点，左右孩子都越界，那么tar==root
                if (target == root) break; 
                std::swap(nums[root], nums[target]);
                root = target;
            }
        }
        std::swap(nums[0], nums[size-1]);
    };

    for (int i=nums.size(); i>0; i--) {
        heapSort(nums, i);
    }
}

