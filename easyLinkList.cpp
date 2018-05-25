// leetcode 82
// clean code is badly needed
/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

Example 1:

Input: 1->2->3->3->4->4->5
Output: 1->2->5
Example 2:

Input: 1->1->1->2->3
Output: 2->3
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
        ListNode *node=head->next, *pNode=head->next, *ppNode=head;
        bool isHeadDup = false;
        // head is duplicate
        if(ppNode->val==pNode->val) {
            while(pNode!=NULL&&ppNode->val==pNode->val) {
                ppNode->next = pNode->next;
                delete pNode;
                pNode = pNode->next;
            }
            isHeadDup = true;
        }
        // remain two points
        if(pNode==NULL) {
            if(!isHeadDup) return head;
            else {
                delete head;
                return NULL;
            }
        }
        node = pNode->next;
        while(node!=NULL) {
            if(pNode->val==node->val) { // duplicate
                while(node!=NULL&&pNode->val==node->val) { // delete duplicate
                    pNode->next=node->next;
                    delete node;
                    node = pNode->next;
                }
                ppNode->next = pNode->next;
                delete pNode;
                pNode = ppNode->next;
                if(node!=NULL) node = node->next;
            }
            else {
                node = node->next;
                ppNode = ppNode->next;
                pNode = pNode->next;
            }
        }
        // delete head
        if(isHeadDup) {
            node = head;
            head = head->next;
            delete node;
            return head;
        }
        return head;
    }
};

// leetcode 19
/*
Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, *low=head, *preNode=head;
        while(n) {
            fast = fast->next;
            n--;
        }
        while(fast!=NULL) {
            preNode = low;
            low = low->next;
            fast = fast->next;
        }
        if(low==head) {
            head = head->next;
            delete low;
        }
        else {
            preNode->next = low->next;
            delete low;
        }
        return head;
    }
};
