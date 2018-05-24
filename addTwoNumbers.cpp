// leetcode 2. linked list, carefully consider conditions
/*

You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head=l1, *preNode=l1;
        int lastC = 0;
        while(l1!=NULL&&l2!=NULL) { // 
            l1->val += l2->val+lastC;
            lastC = (l1->val)/10;
            l1->val %= 10;
            preNode = l1;
            l2 = l2->next;
            l1 = l1->next;
        }
        if(l1!=NULL) {
            while(lastC&&l1!=NULL) {
                l1->val += lastC;
                lastC = (l1->val)/10;
                l1->val %= 10;
                preNode = l1;
                l1 = l1->next;
            }
            if(lastC) { // carry 1
                ListNode *node = new ListNode(1);
                preNode->next = node;
            }
        }
        else if(l2!=NULL) {
            if(preNode==NULL) {
                head = l2;
                preNode = l2;
            }
            else preNode->next = l2;
            while(lastC&&l2!=NULL) {
                l2->val += lastC;
                lastC = (l2->val)/10;
                l2->val %= 10;
                preNode = l2;
                l2 = l2->next;
            }
            if(lastC) { // carry 1
                ListNode *node = new ListNode(1);
                preNode->next = node;
            }
        }
        else {
            if(lastC) {
                ListNode *node = new ListNode(1);
                preNode->next = node;
            }
        }
        return head;
    }
};

// leetcode 67.
/*
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"
*/
class Solution {
public:
    string addBinary(string a, string b) {
        int N1=a.size()-1, N2=b.size()-1;
        int op1=0, op2=0, c=0;
        string res;
        char s;
        int i=0;
        while(N1-i>=0||N2-i>=0) {
            op1 = N1-i<0? 0:(a[N1-i]-'0');
            op2 = N2-i<0? 0:(b[N2-i]-'0');
            s = op1 + op2 + c + '0';  
            c = (s - '0')/2;
            s = (s-'0')%2 + '0';
            res = s + res;
            i++;
        }
        if(c) res = "1" + res;
        return res;
    }
};
