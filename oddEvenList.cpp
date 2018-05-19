
// linked list, think more, think carefully, then write.
/*
Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example:
Given 1->2->3->4->5->NULL,
return 1->3->5->2->4->NULL.

Note:
The relative order inside both the even and odd groups should remain as it was in the input. 
The first node is considered odd, the second node even and so on ...

Credits:
Special thanks to @DjangoUnchained for adding this problem and creating all test cases.
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
    ListNode* oddEvenList(ListNode* head) {
        int cnt=1;
        if(head==NULL||head->next==NULL) return head;
        ListNode *ePre=head, *eStart=head->next, *eEnd=head->next, *node=head->next;
        while(node) {
            cnt++;
            if(cnt%2) {
            eEnd->next = node->next;
            ePre->next = node;
            node->next = eStart;
            ePre = node;
            node = eEnd->next;
            }
            else {
                eEnd = node;
                node = eEnd->next;
            }
        }
        return head;
    }
};
