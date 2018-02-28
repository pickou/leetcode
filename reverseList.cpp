// reserve list

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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode *node = head->next;
        ListNode *nextNode, *preNode;
        head->next=NULL;
        // one node
        if(node==NULL) return head;
        preNode=head;
        nextNode=node->next;
        // two nodes
        if(nextNode==NULL) {
            node->next = preNode;
            return node;
        }
        while(node->next!=NULL) {
            nextNode = node->next;
            node->next = preNode;
            preNode = node;
            node = nextNode;
        }
        node->next = preNode;
        return node;
    }
};
