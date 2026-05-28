#include "Mylist.hpp"
#include "BinTree.hpp"
#include <array>
#include <iostream>

#include "Myheap.hpp"

int main(){
    std::array<int, 5> arr={42,5,1,7,8};
    MyHeap h1(MIN_HEAP);
    for (int num : arr) {
        h1.heap_push(num);
    }
    std::cout<<h1.peek(); 
    return 0;
}