/*
Given a linked list, determine if it has a cycle in it.

Follow up:
Can you solve it without using extra space?
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
    bool hasCycle(ListNode *head) {
        if(head==NULL) return false;
        // set two runners
        ListNode *slow = head;
        ListNode *fast = head;

        // fast runner move 2 steps at one time while slow runner move 1 step,
        // if traverse to a null, there must be no loop
        while (fast != NULL && fast->next != NULL) {
	    slow = slow->next;
	    fast = fast->next->next;
	    if (slow == fast) {
		    return true;
	    }
    }
        return false;
    }
};

// 过河拆桥法，十分精妙

class Solution {
public:
    bool hasCycle(ListNode *head) {
    	ListNode *p = head,*pre = head;
    	while(p != NULL && p->next != NULL){
    		if (p->next == head) return true;
    		p = p->next;
    		pre->next = head;
    		pre = p;
    	}
        return false;
    }
 };
