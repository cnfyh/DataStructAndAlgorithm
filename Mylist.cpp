#include "Mylist.hpp"
#include <cstdio>
#include <format>
#include <iostream>
int Mylist::getsize(){return arrsize;}
int Mylist::getarrcap(){return arrcap;}
void Mylist::arrex(){
    int* temp=arr;
    arr=new int[arrcap*arrraito];
    for (int i=0; i<arrcap; i++) {
        arr[i]=temp[i];
    }
    delete [] temp;
    arrcap=arrcap*arrraito;
}
//插入元素---尾插
void Mylist::pushval(int num){
    if (arrsize<arrcap) {
        arr[arrsize]=num;
    }else {
        arrex();
        arr[arrsize]=num;
    }
    arrsize++;
}
//指定索引插入
void Mylist::insert(int index,int num){
    if(index>arrsize){
        printf("index err,please input nums in 0~%d\n",arrsize-1);
        return;
    }else{
        if (arrsize==arrcap) {
            arrex();
        }
        for (int i=arrsize-1; i>=index; i--) {
            arr[i+1]=arr[i];
        }        
        arr[index]=num;
        arrsize++;
    }
}
    //删除元素
void Mylist::remove(int index){
    if(index>=arrsize){
        printf("index err,please input nums in 0~%d\n",arrsize-1);
        return;
    }else{
        for (int i=index; i<arrsize-1; i++) {
            arr[i]=arr[i+1];
        }
        arrsize--;
    }
}
//显示当前数组元素
int Mylist::shownum(int index){
    
    if (index>=arrsize) {
        std::cout<<"index err"<<'\n';
    }
    return arr[index];
}  

int LinknodeStack::top(){
    if (stacksize) {
        return stacktop->val;
    }else {
        std::cout<<std::format("stack is empty");
        return -1;
    }

}
bool LinknodeStack::isempty(){
    if (!stacksize) {
        return true;
    }else {
        return false;
    }
}
void LinknodeStack::push(int val){
    Linknode* temp=new Linknode(val);
    if (stacktop) {
        temp->next=stacktop;
    }
    stacktop=temp;
    temp=nullptr;
    stacksize++;
}
int LinknodeStack::pop(){
    int res;
    if (isempty()) {
        std::cout<<std::format("stack is empty");
        return -1;
    }else {
        Linknode* temp=stacktop;
        stacktop=stacktop->next;
        res=temp->val;
        delete temp;
        stacksize--;
    }
    return res;
}
