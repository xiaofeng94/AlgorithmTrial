/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int rob(TreeNode* root) {
        // int temp1 = search(root, true);
        // int temp2 = search(root, false);
        
        int temp1 = 0;
        int temp2 = 0;
        
        search(root, temp1,temp2);
        
        if(temp1 < temp2){
            return temp2;
        }else{
            return temp1;
        }
    }
    
    void search(TreeNode* parent, int& robcSum,int& nrobcSum){
        if(parent == NULL){
            return;
        }
        int left1 = 0;
        int left2 = 0;
        int right1 = 0;
        int right2 = 0;
        search(parent->left,left1,left2);
        search(parent->right,right1,right2);
        robcSum = left2 + right2 + parent->val;
        nrobcSum = max(left1,left2) + max(right1,right2);
        
    }
};




