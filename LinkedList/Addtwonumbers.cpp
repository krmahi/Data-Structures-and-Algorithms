/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

// time | space
// O(n) | O(n)*

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode *temp1 = l1;
        ListNode *temp2 = l2;
        ListNode *dnode = new ListNode(-1);
        ListNode *curr = dnode;
        int sum, carry = 0;
        while (temp1 != NULL || temp2 != NULL)
        {
            sum = carry;
            if (temp1)
                sum = sum + temp1->val;
            if (temp2)
                sum = sum + temp2->val;
            ListNode *newnode = new ListNode(sum % 10);
            carry = sum / 10;
            curr->next = newnode;
            curr = curr->next;
            if (temp1)
                temp1 = temp1->next;
            if (temp2)
                temp2 = temp2->next;
        }
        // for last carry
        if (carry)
        {
            ListNode *newnode = new ListNode(carry);
            curr->next = newnode;
        }
        return dnode->next;
    }
};