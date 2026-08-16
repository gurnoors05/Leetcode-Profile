// Last updated: 8/16/2026, 6:51:17 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        int max = -1;
        for (int num : nums) {
            max = num > max ? num : max;
        }
        vector<bool> set(max+1,false);
        for(int n:nums){
            set[n]=true;
        }        
        ListNode* prev=NULL;
        ListNode* temp=head;
        while (temp != NULL) {
            if (temp->val >= 0 && temp->val <= max && set[temp->val]) {
                // Remove the current node
                if (prev == NULL) {
                    // Removing head node
                    head=head->next;
                    temp->next=NULL;
                    temp=head;
                } 
                else {
                    prev->next=temp->next;
                    temp->next=NULL;
                    temp=prev->next;
                }
            } 
            else {
                // Move to the next node
                prev = temp;
                temp = temp->next;
            }
        }
        return head;
        
    }
};