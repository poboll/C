#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
void getNodeNumbs(struct TreeNode* root,int *count){
    if(root==NULL)return;
    (*count)++;
    getNodeNumbs(root->left,count);
    getNodeNumbs(root->right,count);
}
void getXNode(struct TreeNode* root,int x,struct TreeNode** cur,int *count){
    if(root==NULL)return;
    if(root->val==x){
        *cur=root;
        return;
    }
    (*count)++;
    getXNode(root->left,x,cur,count);
    getXNode(root->right,x,cur,count);
}
bool btreeGameWinningMove(struct TreeNode* root, int n, int x){
    int xCount=0,yCount=0,zCount=0;
    struct TreeNode* cur;
    int half=n/2;
    getXNode(root,x,&cur,&zCount);
    getNodeNumbs(cur->right,&xCount);
    getNodeNumbs(cur->left,&yCount);
    if(xCount>half||yCount>half||zCount>half)return true;
    return false;
}