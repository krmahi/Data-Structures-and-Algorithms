
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

// two pointer
// Time | space
// O(n) | O(1)

class solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;

        while (temp != NULL)
        {
            ListNode *front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};

// recursive method
// TIme | Space
// O(n) | O(n) [recursive stack space]

class solution
{
public:
    ListNode *ReverseList(ListNode *head)
    {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *newhead = ReverseList(head);
        ListNode *front = head->next;
        front->next = head;
        head->next = NULL;
        return newhead;
    }
};
