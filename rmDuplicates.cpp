/*
Given a sorted linked list, delete all duplicates such that each element appear only once.

For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL) return head;
        ListNode *node = head;
        while(node!=NULL&&node->next!=NULL) {
            if(node->next->val==node->val) {
                ListNode *throwNode = node->next;
                node->next = node->next->next;
                delete throwNode;
            }
            else node = node->next;
        }
        return head;
    }
};
