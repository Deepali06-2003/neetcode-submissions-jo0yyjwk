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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL )return NULL;
        
        
        ListNode* s = head;
        ListNode* f = head;
        ListNode* p = NULL;

        while(n!=0){
            f= f->next;
            n--;
        }

        if (f == NULL) {
        ListNode* newHead = head->next;
        delete head;
        return newHead;
        }

        while(f){
            p = s;
            s= s->next;
            f = f->next;
        }

        p->next = s->next;

        return head;
    }
};
