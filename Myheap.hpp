#pragma once
#define MAX_HEAP 1
#define MIN_HEAP 0
#include <vector>
struct MyHeap{
    private:
        int heapclass;
        std::vector<int> heaparr;
        int getchildindex_l(int i);
        int getchildindex_r(int i);
        int getparentindex(int i);
    public:
        int getheapsize(){
            return heaparr.size();
        }
        int peek();
        void heap_push(int val);
        void heap_pop();
        void buildheap(const std::vector<int>& arr);
        MyHeap(int x):heapclass(x){}
};