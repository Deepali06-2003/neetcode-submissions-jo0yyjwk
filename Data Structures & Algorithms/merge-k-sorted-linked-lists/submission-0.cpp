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
ListNode* helper(ListNode* res ,ListNode* l){
    ListNode* x= new ListNode(0);
    ListNode* y = x;

    while(res && l){
        if(res->val <= l->val){
            y->next = res;
            y = y->next;
            res = res->next;
        }
        else{
            y->next = l;
            l = l->next;
            y = y->next;
        }
    }
    if(res){
        y->next = res;
    }
    if(l){
        y->next = l;
    }
    return x->next;

}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = NULL;
        if(lists.empty())return res;

        
        for(int i =0 ;i< lists.size();i++){
            res = helper(res , lists[i]);
        }
        return res;
    }
};
