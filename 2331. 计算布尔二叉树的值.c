/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
bool evaluateTree(struct TreeNode* root){
    if(root->left==NULL&&root->right==NULL)
        return root->val;
    if(root->val==2)
        return evaluateTree(root->left)||evaluateTree(root->right);
    if(root->val==3)
        return evaluateTree(root->left)&&evaluateTree(root->right);
    //力扣要求函数必须返回一个值，实际上并不会运行到下面这一步
    return true;
}
