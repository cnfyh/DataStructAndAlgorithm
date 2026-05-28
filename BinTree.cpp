#include "BinTree.hpp"
#include <functional>
#include <queue>
#include <system_error>
#include <vector>
//01---二叉树层序遍历
std::vector<int> BinTreeFunc::LevelOrderTraversal(){
    std::vector<int>res;
    std::queue<BinTreenode*>bintreequeue;
    if (!root) {
        return res;
    }
    bintreequeue.push(root);
    while (bintreequeue.size()) {
        BinTreenode*temp=bintreequeue.front(); //取得队头元素值，但不出队
        bintreequeue.pop();//出队
        res.push_back(temp->val);
        if (temp->left) {
            bintreequeue.push(temp->left);
        }
        if (temp->right) {
            bintreequeue.push(temp->right);
        }
    }
    return res;
}
//02---前序遍历，根节点 -> 左子树 -> 右子树
std::vector<int> BinTreeFunc::PreOrderTraversal(){
    std::vector<int> res;
    std::function<void(BinTreenode*)> dfs=[&](BinTreenode* node){
        if (!node) {
            return;
        }
        res.push_back(node->val); //操作步骤，位置决定前中后
        dfs(node->left);
        dfs(node->right);
    };
    dfs(root);
    return res;
}
//03---中序遍历，左子树-> 根节点 -> 右子树
std::vector<int> BinTreeFunc::MidOrderTraversal(){
    std::vector<int> res;
    std::function<void(BinTreenode*)> dfs=[&](BinTreenode* node){
        if (!node) {
            return;
        }
        dfs(node->left);
        res.push_back(node->val);
        dfs(node->right);
    };
    dfs(root);
    return res;
}
//03---后序遍历，左子树-> 右子树 -> 根节点 
std::vector<int> BinTreeFunc::PosOrderTraversal(){
    std::vector<int> res;
    std::function<void(BinTreenode*)> dfs=[&](BinTreenode* node){
        if (!node) {
            return;
        }
        dfs(node->left);
        dfs(node->right);
        res.push_back(node->val);
    };
    dfs(root);
    return res;
}
//二叉搜索树----寻找目标值
BinTreenode* BinarySearchTree:: BinarySearch(int target){
    BinTreenode*res=root;
    while (res) {
        if (res->val==target) {
            break;
        }else if (target < res->val) {
            res=res->left;
        }else {
            res=res->right;
        }
    }
    //出循环 res==target 或 res==nullptr
    return res;
}
//二叉搜索树(不允许存在重复值)----插入值
void BinarySearchTree::BinarySearchTreeInsert(int target){
    if (!root) { //空树
        root=new BinTreenode(target);
        return;
    }
    BinTreenode* curnode=root;
    BinTreenode* pernode=nullptr;
    while (curnode) {
        //查到重复值直接退出
        if (curnode->val==target) {
            return;
        }
        //确定cur位置，其位置一定为叶子节点处
        pernode=curnode;
        if (target < curnode->val) {
            curnode=curnode->left;
        }else {
            curnode=curnode->right;
        }
    }
    //赋值
    BinTreenode* node=new BinTreenode(target);
    if (target > pernode->val) {
        pernode->right=node;
    }else {
        pernode->left=node;
    }
}
//二叉搜索树----删除元素
void BinarySearchTree::BinarySearchTreeRemove(int target) {
    if (!root) { //空树
        return;
    }
    //查找目标值
    BinTreenode* curnode=root;
    BinTreenode* prenode=nullptr;
    while (curnode) {
        if (target==curnode->val) {
            break;
        }
        prenode=curnode;
        if (target<curnode->val) {
            curnode=curnode->left;
        }else {
            curnode=curnode->right;
        }
    }
    //未找到的处理
    if (!curnode) { 
        return;
    }
    //找到处理-----度为0/1----删除cur节点，然后per指向cur的孩子节点
    if (curnode->left==nullptr||curnode->right==nullptr) {
        BinTreenode* child=curnode->left ? curnode->left : curnode->right;
        if (curnode!=root) {
            if (prenode->left==curnode) {
                prenode->left=child;
            }else {
                prenode->right=child;
            }
        }else {
            root=child;
        }
        delete curnode;
    }else {  //度为2，将当前节点用其左子树最大值或者右子树最小值代替
        //寻找右子树最小值
        BinTreenode* temp=curnode->right;
        BinTreenode* pretemp=curnode;
        while (temp->left) {
            pretemp=temp;
            temp=temp->left;
        }
        int tempval=temp->val;
        //右子树最小值度一定为0或者1
        if (pretemp!=curnode) {       //当最小值为右子树的左节点时
            pretemp->left=temp->right;
        }else {                       //当最小值就为右子树本身时
            pretemp->right=temp->right;
        }
        delete temp;
        curnode->val=tempval;
    }
}
//获取高度，空节点为-1,叶子节点为0
int BinTreenode::GetHeight(BinTreenode* node){ 
        return node==nullptr ? -1: node->height;
    }
//更新高度----递归返回，叶子节点为0
void BinTreenode::UpdateHeight(BinTreenode* node){ 
    node->height=std::max(GetHeight(node->left),GetHeight(node->right))+1;
}
//定义：平衡因子为左子树高度-右子树高度
int AVLTree::GetBalanceFactor(BinTreenode* node){
    if (!node) { //nullptr平衡因子为0
        return 0;
    }
    return node->GetHeight(node->left)-node->GetHeight(node->right);
}
BinTreenode* AVLTree::RightRotate(BinTreenode* node){
    //假设当前节点node为失衡节点
    BinTreenode* child=node->left;
    BinTreenode* grandchild=child->right;
    //开始旋转
    child->right=node;
    node->left=grandchild;
    //更新高度
    node->UpdateHeight(node);
    child->UpdateHeight(child);

    return child;//返回新树的根节点
}
BinTreenode* AVLTree::LeftRotate(BinTreenode* node){
    BinTreenode*child=node->right;
    BinTreenode* grandchild=child->left;
    //开始旋转
    child->left=node;
    node->right=grandchild;
    //更新高度
    node->UpdateHeight(node);
    child->UpdateHeight(child);
    return child;
}
BinTreenode* AVLTree::RightLeftRotate(BinTreenode* node){
    //先右旋右孩子节点
    node->right=RightRotate(node->right);
    //后左旋根节点
   return LeftRotate(node);
}
BinTreenode* AVLTree::LeftRightRotate(BinTreenode* node){
    //先左旋左孩子节点
    node->left=LeftRotate(node->left);
    //后右旋根节点
   return RightRotate(node);
}
BinTreenode* AVLTree::rotate(BinTreenode* node){
    int balancefactorroot=GetBalanceFactor(node);
    if (balancefactorroot>1) { //左偏高树
        int balancefactorchild=GetBalanceFactor(node->left);
        if (balancefactorchild>=0) { //LL
            return RightRotate(node);
        }else {                      //LR
            return LeftRightRotate(node);
        }
    }
    if (balancefactorroot<-1) { //右偏高树
        int balancefactorchild=GetBalanceFactor(node->right);
        if (balancefactorchild<=0) {  //RR
            return LeftRotate(node);
        }else {                       //RL
            return RightLeftRotate(node);
        }
        
    }
    return node; //平衡树
}