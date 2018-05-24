// leetcode 46, multiply two strings
/*

Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.

Example 1:

Input: num1 = "2", num2 = "3"
Output: "6"
Example 2:

Input: num1 = "123", num2 = "456"
Output: "56088"
Note:

The length of both num1 and num2 is < 110.
Both num1 and num2 contain only digits 0-9.
Both num1 and num2 do not contain any leading zero, except the number 0 itself.
You must not use any built-in BigInteger library or convert the inputs to integer directly.
*/
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0"||num2=="0") return "0";
        int n1=num1.size(), n2=num2.size();
        vector<int> res(n1+n2-1, 0);
        string str="";
        int lastC = 0;
        char s;
        for(int i=n1-1; i>=0; i--) { // O(m+n)
            for(int j=n2-1; j>=0; j--) {
                res[i+j] += (num1[i]-'0')*(num2[j]-'0');
            }
        }
        for(int i=res.size()-1; i>=0; i--) {
            s = (lastC + res[i])%10 + '0';
            str = s + str;
            lastC = (lastC+res[i])/10;
        }
        if(lastC)  {
            s = lastC+'0';
            str = s + str;
        }
        return str;
    }
};

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
