/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int minDepth(struct TreeNode* root)
{
    if (!root)
        return 0;

    if (!root->left)
        return 1 + minDepth(root->right);
    
    if (!root->right)
        return 1 + minDepth(root->left);

    int left = 1 + minDepth(root->left);
    int right = 1 + minDepth(root->right);

    if (left > right)
        return right;
    
    return left;
}