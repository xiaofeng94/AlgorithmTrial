class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr){
            return true;
        }
        getDepth(root);
        return isSubTreeBalance(root);
    }
    
    bool isSubTreeBalance(TreeNode* root){
        if(root->left == nullptr && root->right == nullptr){
            return true;
        }
        if(root->left == nullptr){
            if( root->right->val <= 1){
                return true;
            }else{
                return false;
            }
        }
        if(root->right == nullptr ){
            if (root->left->val <= 1) {
                return true;
            }else{
                return false;
            }
        }
        int diff = root->left->val - root->right->val;
        if(diff >= -1 && diff <= 1){
            return isSubTreeBalance(root->left)&&isSubTreeBalance(root->right);
        }else{
            return false;
        }
    }
    
    int getDepth(TreeNode* curr){
        if(curr == nullptr){
            return 0;
        }
        int left = getDepth(curr->left);
        int right = getDepth(curr->right);
        curr->val = ((left>right)?(left+1):(right+1));
        return curr->val;
    }
};