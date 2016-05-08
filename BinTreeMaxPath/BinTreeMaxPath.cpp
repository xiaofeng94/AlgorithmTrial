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
        TreeNode* auxiliary;
        int max = searchCompute(root,auxiliary);
        searchMax(root,auxiliary,max);
        return max;
    }
    int searchCompute(TreeNode* curr,TreeNode* &auxCurr){
        if(curr == nullptr){
            return 0;
        }
        auxCurr = new TreeNode(curr->val);
        int left = searchCompute(curr->left,auxCurr->left);
        int right = searchCompute(curr->right,auxCurr->right);
        if(left > 0 || right > 0){
            if(left > right){
                curr->val += left;
            }else{
                curr->val += right;
            }
        }
        return curr->val;
    }
    void searchMax(TreeNode* curr,TreeNode* auxCurr,int& max){
        if(curr == nullptr){
            return;
        }
        int tempSum = auxCurr->val;
        if(curr->left != nullptr && curr->left->val > 0){
            tempSum += curr->left->val;
        }
        if(curr->right != nullptr && curr->right->val > 0){
            tempSum += curr->right->val;
        }
        
        if(max < tempSum){
            max = tempSum;
        }
        searchMax(curr->left,auxCurr->left,max);
        searchMax(curr->right,auxCurr->right,max);
    }
};

TreeNode* createTree(TreeNode* &curr,vector<int>& data,int indx){
    if (indx >= data.size()) {
        return nullptr;
    }
    curr = new TreeNode(data[indx]);
    
    createTree(curr->left,data,2*indx+1);
    createTree(curr->right,data,2*indx+2);
    
    return curr;
}