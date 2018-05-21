/*
Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5
*/
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
    ListNode* sortList(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        // get the total count
        ListNode *node=head;
        int cnt=0;
        while(node!=NULL){
            cnt++;
            node = node->next;
        }
        // get medium
        node=head;
        int k=0;
        while(node!=NULL) {
            k++;
            if(k==cnt/2) break;
            node = node->next;
        }
        ListNode* head1 = head;
        ListNode* head2 = node->next;
        node->next = NULL;
        // merge sort
        head1 = sortList(head1); // left
        head2 = sortList(head2); // right
        head = merge(head1, head2);
        return head;
    }
    ListNode *merge(ListNode* head1, ListNode *head2) {
        ListNode *head, *node;
        if(head1==NULL) return head2;
        if(head2==NULL) return head1;
        if(head1->val<=head2->val) { 
            head=head1;
            head1 = head1->next;
        }
        else {
            head = head2;
            head2 = head2->next;
        }
        node = head;
        while(head1!=NULL&&head2!=NULL) {
            if(head1->val<=head2->val) {
                node->next = head1;
                head1 = head1->next;
            }
            else {
                node->next = head2;
                head2 = head2->next;
            }
            node = node->next;
        }
        
        if(head1!=NULL) {
            node->next = head1;
        }
        if(head2!=NULL) {
            node->next = head2;
        }

        return head;
    }
};
