/**
 *   2018/10/24
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        if(head->next == NULL)return head;
        if(head == NULL)return NULL;
        if(n == m)return head;
        int i =1;
        ListNode*first = head,*second = head,*begin = head,*end = head,*p=head;
        
        while(i < m)
        {
            begin = first;
            first = first->next;
            i++;
        }
        p = first;
        ListNode*q = first->next;
        while(i < n&&q!=NULL)
        {
            ListNode*h = q->next;
            q->next = first;
            first = q;
            q = h;
            i++;
        }
        
        if(m == 1 && q !=NULL)
        {
            head->next = q;
            head = first;
        }
        if(m==1 && q== NULL)
        {
            head ->next = NULL;
            head = first;
        }
        if(m != 1 && q != NULL)
        {
            begin->next = first;
            p->next = q;
        }
        if(m!=1 && q == NULL)
        {
            begin->next = first;
            p->next = NULL;
        }
    
        return head;
    }
    
};
