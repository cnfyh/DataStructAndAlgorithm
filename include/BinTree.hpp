#pragma once
#include <vector>
//二叉树
struct BinTreenode{
    int val;
    int height=0; //空节点为-1,叶子节点为0
    BinTreenode* left;
    BinTreenode* right;
    BinTreenode(int val):val(val),left(nullptr),right(nullptr){}
    int GetHeight(BinTreenode* node);
    //更新高度----递归返回，叶子节点为0
    void UpdateHeight(BinTreenode* node);
};
class BinTreeFunc{
    protected:
        BinTreenode* root;
    public:
        BinTreeFunc()=default;
        BinTreeFunc(BinTreenode* root){
            this->root=root;
        }
        std::vector<int> LevelOrderTraversal();
        std::vector<int> PreOrderTraversal();
        std::vector<int> MidOrderTraversal();
        std::vector<int> PosOrderTraversal();
};
class BinarySearchTree : public BinTreeFunc {
    public:
        BinarySearchTree()=default;
        BinarySearchTree(BinTreenode* root):BinTreeFunc(root){}
        BinTreenode* BinarySearch(int target);
        void BinarySearchTreeInsert(int target);
        void BinarySearchTreeRemove(int target);
};
class AVLTree  {
    public:
    int GetBalanceFactor(BinTreenode* node);   
    private:
    //旋转函数
    BinTreenode* RightRotate(BinTreenode* node);     //右旋--------------针对LL型
    BinTreenode* LeftRotate(BinTreenode* node);      //左旋--------------针对RR型
    BinTreenode* RightLeftRotate(BinTreenode* node); //先右旋，在左旋-----针对RL型
    BinTreenode* LeftRightRotate(BinTreenode* node); //先左旋，在右旋-----针对LR型
    public:
    BinTreenode* rotate(BinTreenode* node);          //执行平衡操作，使得bst平衡
};


