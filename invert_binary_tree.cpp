#include<iostream>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
int diameter;

int height(TreeNode* root) {
        if (!root) return 0;

        int left = height(root->left);
        int right = height(root->right);

        diameter = max(diameter, left + right);

        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
TreeNode* invertTree(TreeNode* root) {
        if (!root) return nullptr;

        TreeNode* temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);

        return root;
    }

int main() {
    
    return 0;
}