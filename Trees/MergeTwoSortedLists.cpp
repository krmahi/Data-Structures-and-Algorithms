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
// O(n+m) | O(1) || O(n)

class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        //    ListNode* t1 = list1;
        //    ListNode* t2 = list2;
        if (list1 == NULL && list2 == NULL)
            return NULL;
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode *DummyNode = new ListNode(-1);
        ListNode *temp = DummyNode;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val <= list2->val)
            {
                temp->next = list1;
                list1 = list1->next;
            }
            else
            {
                temp->next = list2;
                list2 = list2->next;
            }
            temp = temp->next;
        }
        if (list1)
            temp->next = list1;
        else
            temp->next = list2;

        return DummyNode->next;
    }
};