#include<bits/stdc++.h>
using namespace std;
using ll = long long;
/**
 * Definition for singly-linked list. **/
   struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        set<int> s(nums.begin(),nums.end());
        ListNode *curr, *prev;
        ListNode temp(0);
        prev = &temp;
        temp.next = curr = head;
        while(curr) {
            if(s.contains(curr->val))
                prev->next = curr->next;
            else {
                prev = prev->next;
            }
            curr = curr->next;
        }
        return temp.next;
    }
};