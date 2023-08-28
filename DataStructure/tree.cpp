//
// Created by ASUS on 2023/8/14.
//
#include <iostream>
/*
 * 二叉树的最大距离
 * 从二叉树的节点A出发，可以向上或向下走，但沿途的节点只能经过一次，当到达几点B时，路径上的节点数叫作A到B的距离
 *
 * 最大距离=max(左子树最大距离，右子树最大距离，左子树高度+右子树高度+1)
 */
using namespace std;

struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x),left(nullptr),right(nullptr){}
    void Connect(TreeNode *left, TreeNode *right){
        this->left = left;
        this->right = right;
    }
};

void free(TreeNode *root){
    if(root != nullptr){ // 判断该节点是否存在，存在释放
        TreeNode *left = root->left;
        TreeNode *right = root->right;
        delete root;
        root = nullptr;
        free(left);
        free(right);
    }
}

class maxDistance {
public:
    struct Retval{
        int distance;
        int height;
        Retval(int dis, int hgt) : distance(dis), height(hgt) {}
    };
    static int Do(TreeNode *root){
        if (root == nullptr) return 0;
        return dfs(root).distance;
    }
private:
    static Retval dfs(TreeNode *root){ // 后序遍历
        if (root == nullptr) return Retval(0,0);
        Retval left = dfs(root->left);
        Retval right = dfs(root->right);
        int height = max(left.height, right.height) + 1;
        int maxHeight = left.height + right.height + 1;
        int distance = max(left.distance, right.distance);
        return Retval(max(distance, maxHeight), height);
    }
};

void test01(){
    TreeNode *node1 = new TreeNode(1);
    TreeNode *node2 = new TreeNode(2);
    TreeNode *node3 = new TreeNode(3);
    TreeNode *node4 = new TreeNode(4);
    TreeNode *node5 = new TreeNode(5);
    TreeNode *node6 = new TreeNode(6);
    TreeNode *node7 = new TreeNode(7);
    node1->Connect(node2,node3);
    node2->Connect(node4,node5);
    node3->Connect(node6,node7);

    cout << "test1:" << maxDistance::Do(node1) << endl;

    free(node1);
}

int main(){
    test01();
}