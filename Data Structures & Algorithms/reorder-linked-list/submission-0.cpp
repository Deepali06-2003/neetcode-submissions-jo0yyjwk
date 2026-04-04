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
ListNode* reverse(ListNode* s){
    ListNode* prev = NULL;
    ListNode* curr = s;
    ListNode* c_n = NULL;

    while(curr){
        c_n = curr->next;
        curr->next = prev;

        prev = curr;
        curr = c_n;
    }
    return prev;
}
    void reorderList(ListNode* head) {
        ListNode* s = head;
        ListNode* f = head;
        ListNode* p = NULL;

        while(f && f->next){
            p = s;
            s= s->next;
            f= f->next->next;
        }
        //cout<<p->val<<' '<<s->val;
        ListNode* l2 = reverse(s->next);
        s->next = NULL;

        ListNode* temp = head;

        ListNode* t = temp;
        ListNode* l = l2;

        while(l2){
            t = temp->next;
            l = l2->next;

            temp->next = l2;
            l2->next = t;

            temp = t;
            l2 = l;
        }

    }
};
