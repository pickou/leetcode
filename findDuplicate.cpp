// leetcode 287

/*
Given an array nums containing n + 1 integers where each integer is between 1 and n (inclusive), prove that at least one duplicate number must exist. Assume that there is only one duplicate number, find the duplicate one.

Example 1:

Input: [1,3,4,2,2]
Output: 2
Example 2:

Input: [3,1,3,4,2]
Output: 3
Note:

You must not modify the array (assume the array is read only).
You must use only constant, O(1) extra space.
Your runtime complexity should be less than O(n2).
There is only one duplicate number in the array, but it could be repeated more than once.
*/

// solution 1. sort and tranverse, O(nlogn). Easy to understand!

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i]==nums[i+1])
                return nums[i];
        }
    }
};

// solution 2. use `linked cycle` list https://leetcode.com/problems/linked-list-cycle-ii/
// use two pointer fast and slow, O(n)
// what I wonder is the way to find to entry. 
// From the meeting point and the head to travel one step per time, and the fist meeting point is the entry?

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()<2) return -1; 
        int slow = nums[0];
        int fast = nums[nums[0]];
        while(fast!=slow) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(fast!=slow) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return slow;
    }
};

/* find the entry of a linked cycle list */
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast=head, *slow=head;
        while(fast!=NULL&&fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;
            if(fast==slow) break;
        }
        if(fast==NULL||fast->next==NULL) return NULL;
        fast = head;
        while(fast!=slow) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
