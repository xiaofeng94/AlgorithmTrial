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
    int maxPathSum(TreeNode* root) {
        int max = 0;
        searchBoth(root,max);
        return max;
    }
    void searchBoth(TreeNode* curr,int& max){
        if(curr == nullptr){
            return;
        }
        int sideMaxLeft = 0;
        int sideMaxRight = 0;
        searchSide(curr->left,0,sideMaxLeft);
        searchSide(curr->right,0,sideMaxRight);
        int currSum = curr->val + sideMaxLeft + sideMaxRight;
        
        if(currSum > max){
            max = currSum;
        }
        
        searchBoth(curr->left,max);
        searchBoth(curr->right,max);
    }
    
    void searchSide(TreeNode* curr,int lastSum ,int& sideMax){
        if(curr == nullptr){
            return;
        }
        int currSum = lastSum + curr->val;
        if(currSum > sideMax){
            sideMax = currSum;
        }
        searchSide(curr->left,currSum ,sideMax);
        searchSide(curr->right,currSum ,sideMax);
    }
};