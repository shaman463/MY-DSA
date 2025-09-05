#include <iostream>

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

int checkheight(TreeNode *root)
{
    if (!root)
        return 0;

    int left = checkheight(root->left);
    if (left == -1)
        return -1;

    int right = checkheight(root->right);
    if (right == -1)
        return -1;

    if (abs(left - right) > 1)
        return -1;

    return max(left, right) + 1;
}
bool isBalanced(TreeNode *root)
{
    return checkheight(root) != -1;
}

int maxDepth(TreeNode *root)
{
    if (!root)
        return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(TreeNode *root)
{
    if (!root)
        return 0;

    if (!root->left)
        return 1 + minDepth(root->right);
    if (!root->right)
        return 1 + minDepth(root->left);

    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main()
{

    return 0;
}