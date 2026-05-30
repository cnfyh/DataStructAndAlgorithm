#include "Myheap.hpp"
#include <utility>

 int MyHeap::getchildindex_l(int i){
    return 2*i+1;//左孩子节点索引
 }
    
int MyHeap::getparentindex(int i){
    return (i-1)/2;//父节点索引
}
int MyHeap::getchildindex_r(int i){
    return 2*i+2; //右孩子节点索引
}
int MyHeap::peek(){ //访问对顶元素
    return heaparr[0];
}
void MyHeap::heap_push(int val){
    heaparr.push_back(val);
    int i = heaparr.size() - 1;
    while (i > 0) {
        int p = getparentindex(i);
        bool shouldswap = (heapclass == MAX_HEAP) ? (heaparr[i] > heaparr[p])
                                                   : (heaparr[i] < heaparr[p]);
        if (!shouldswap) break;
        std::swap(heaparr[i], heaparr[p]);
        i = p;
    }
}
void MyHeap::heap_pop(){
    if (!heaparr.size()) {//空堆
        return;
    }
    if (heaparr.size()==1) { //只有一个元素
        heaparr.pop_back();
        return;
    }
    //交换后删除
    std::swap(heaparr[0], heaparr[heaparr.size() - 1]);
    heaparr.pop_back();
    int root = 0;
    while (true) {
        int l = getchildindex_l(root);
        int r = getchildindex_r(root);
        bool hasL = (l < heaparr.size()); //判断是否越界
        bool hasR = (r < heaparr.size());

        int target = root;
        //比较左右孩子哪一个更适合上浮
        if (hasL) {
            bool needSwap = (heapclass == MAX_HEAP) ? (heaparr[l] > heaparr[target])
                                                     : (heaparr[l] < heaparr[target]);
            if (needSwap) {
                target = l;
            }
        }
        if (hasR) {
            bool needSwap = (heapclass == MAX_HEAP) ? (heaparr[r] > heaparr[target])
                                                     : (heaparr[r] < heaparr[target]);
            if (needSwap) {
                target = r;
            }
        }
        if (target == root) break; //如果到达叶子节点，左右孩子都越界，那么tar==root
        std::swap(heaparr[root], heaparr[target]);
        root = target;
    }
}
void MyHeap::buildheap(const std::vector<int>& arr){
    heaparr.clear();
    for (int num : arr) {
        heaparr.push_back(num);
    }
    for (int i=getparentindex(heaparr.size()-1); i>=0; i--) {
        int root=i;
        while (true) {
            int l=getchildindex_l(root);
            int r=getchildindex_r(root);
            bool hasl=(l<heaparr.size());
            bool hasr=(r<heaparr.size());
            int temp=root;
            if (hasl) {
                bool needswap=(heapclass==MAX_HEAP) ? (heaparr[l] > heaparr[temp])
                                                     :(heaparr[l]<heaparr[temp]);
                if (needswap) {
                    temp = l;
                }                                        
            }
            if (hasr) {
                bool needswap=(heapclass==MAX_HEAP) ? (heaparr[r] > heaparr[temp])
                                                     :(heaparr[r]<heaparr[temp]);
                if (needswap) {
                    temp = r;
                }                                        
            }
            if (temp==root) {
                break;
            }
            std::swap(heaparr[root],heaparr[temp]);
            root=temp;
        }
    }
}