/*
Remove all elements from a linked list of integers that have value val.

Example
Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6, val = 6
Return: 1 --> 2 --> 3 --> 4 --> 5
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
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        ListNode *node=head, *throwNode;
        while(head->val==val) {
            throwNode = head;
            head = head->next;
            delete throwNode;
            if(head==NULL) return NULL;
        }
        node = head;
        while(node!=NULL&&node->next!=NULL) {
            if(node->next->val == val)// delete node
            {
                throwNode = node->next;
                node->next = node->next->next;
                delete throwNode;
            }
            else node = node->next;
        }
        return head;
    }
};
