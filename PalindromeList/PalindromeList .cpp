/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if(head == nullptr){
            return true;
        }
        int num = 0;
        ListNode* temp = head;
        while(temp != nullptr){
            ++num;
            temp = temp->next;
        }
        int mid = num/2;
        ListNode* midStart = head;
        for(int i = 0;i < mid;++i){
            midStart = midStart->next;
        }
        
        return readToMid(head,midStart,0,num);
    }
    
    bool readToMid(ListNode* curr,ListNode* &midStart,int pos,const int& num){
        bool record = true;
        if((num & 1) == 0){
            if(pos < num/2-1){
                record = readToMid(curr->next,midStart,pos+1,num);
            }
        }else{
            if(pos < num/2){
                record = readToMid(curr->next,midStart,pos+1,num);
            }
        }
        bool ret = (curr->val == midStart->val) && record;
        midStart = midStart->next;
        return ret;
    }
};