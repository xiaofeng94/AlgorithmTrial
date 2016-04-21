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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int listSize = 0;
        ListNode* temp = head;
        while(temp != NULL){
            listSize++;
            temp = temp->next;
        }
        if(listSize < 2){
            return head;
        }
        
        ListNode* front;
        ListNode* mid;
        if(listSize == 2){
            front = head;
            mid = head->next;
            if(k == 2){
                mid->next = front;
                front->next = NULL;
                head = mid;
            }
            return head;
        }
        
        front = head;
        mid = head->next;
        ListNode* right = mid->next;
        ListNode* end = head;
        ListNode* lastEnd = head;
        
        int indx = 0;
        while(indx+k-1 < listSize){
            for(int i = indx;i < indx+k-1;++i){
                mid->next = front;
                front = mid;
                mid = right;
                if(right != NULL){
                    right = right->next;
                }
            }
            if(indx == 0){
                head = front;
            }
           
            lastEnd->next = front;
            lastEnd = end;
            end = mid;
            
            front = mid;
            mid = right;
            if(right != NULL){
                right = right->next;
            }
            
            indx = indx+k;
        }
        if(k-1 < listSize){
            lastEnd->next = front;
        }
        
        return head;
    }
};





