#include<iostream>
 struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* node = root; 

        preorder(root);
        return root;
    }

    void preorder(TreeNode *node){
        if(node != nullptr){
            preorder(node->left); 
            preorder(node->right); 
            std::cout << node->val << std::endl; 

            TreeNode* temp = node->left;
            node->left = node->right; 
            node->right= temp;  
        
        }
    }
};

int main (){


    TreeNode a(4),b(2),c(7),d(1),e(3),f(6),g(9); 

    a.left = &b; 
    a.right= &c; 

    b.left = &d;
    b.right = &e; 

    c.left = &f; 
    c.right = &g;

    Solution s; 
    s.invertTree(&a); 



    return 0; 
}