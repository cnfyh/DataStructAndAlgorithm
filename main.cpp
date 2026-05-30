#include "Mylist.hpp"
#include "BinTree.hpp"
#include <array>
#include <iostream>
#include <vector>
#include "mysort.hpp"
#include "Myheap.hpp"

int main(){
    std::vector<int> arr={42,5,15,7,8,45,78,6,8,85};
    MySort m1;
    m1.heapSortnr(arr);
    for (int num : arr) {
        std::cout<<num<<'\n';
    }
    return 0;
}