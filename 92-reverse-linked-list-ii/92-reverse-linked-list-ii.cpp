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
    ListNode* reverseBetween(ListNode* h, int l, int r) {
        ListNode *b=h,*x=b;
        int c=1;
        while(c<l){
            c++;
            h=h->next;
            if(c==l)
                b->next=NULL;
            else
                b=b->next;
            }
        ListNode *p=h,*u=p,*n=NULL;
        while(c<=r){
            n=h->next;
            if(!p){
                p=h;
                p->next=NULL;
                u=p;
            }
            else{
                h->next=p;
                p=h;
            }
            h=n;
            c++;
        }
        u->next=h;
        if(l!=1){
            b->next=p;
            return x;
        }
        return p;
    }
};