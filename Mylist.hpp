#pragma once
class Mylist{
    private:
        int *arr;         // 创建数组
        int arrsize=0;    //数组元素个数
        int arrcap=10;    //数组容量 
        int arrraito=2;   //扩容比例
        void arrex();
    public:
        Mylist(){
            arr=new int[arrcap];
        }
        ~Mylist(){
            delete [] arr;
        }
    int getsize();
    int getarrcap();
    //插入元素---尾插
    void pushval(int num);
    //指定索引插入
    void insert(int index,int num);
    //删除元素
    void remove(int index);
    int shownum(int index);
};
struct Linknode{
    int val;
    Linknode* next;
    Linknode(int x):val(x),next(nullptr){} //构造函数
};
class LinknodeStack{
    private:
        Linknode* stacktop;
        int stacksize;
    public:    
    LinknodeStack(){
        stacktop=nullptr;
        stacksize=0;
    }
    ~LinknodeStack(){
        while (stacktop) {
            Linknode* temp=stacktop;
            stacktop=stacktop->next;
            delete temp;
        }
    }
    int top();
    void push(int val);
    int pop();
    bool isempty();
};