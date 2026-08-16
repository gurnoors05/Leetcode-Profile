// Last updated: 8/16/2026, 7:04:09 PM
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        int prefixSum=0;
        unordered_map<int,ListNode*> mp;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        mp[0]=dummy;
        while(head){
            prefixSum+=head->val;
            if(mp.find(prefixSum)!=mp.end()){
                ListNode* temp=mp[prefixSum];
                ListNode* start=temp;
                int pSum=prefixSum;
                
                while(start!=head){
                    start=start->next;
                    pSum+=start->val;
                    if(start != head)
                        mp.erase(pSum);
                }
                temp->next=start->next;
            }
            else{
                mp[prefixSum]=head;
            }
            head=head->next;
        }
        return dummy->next;
    }
};
