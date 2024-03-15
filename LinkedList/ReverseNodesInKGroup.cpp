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
// O(nk + k) | O(1)
class Solution
{
public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *temp = head;
        ListNode *prevnode = NULL;
        while (temp != NULL)
        {
            ListNode *kthelem = getkthelem(temp, k);
            if (kthelem == NULL)
            {
                if (prevnode)
                    prevnode->next = temp;
                break;
            }
            ListNode *nextnode = kthelem->next;
            kthelem->next = NULL;
            ListNode *newhead = reverse(temp);

            if (temp == head)
                head = kthelem;
            else
            {
                prevnode->next = kthelem;
            }
            prevnode = temp;
            temp = nextnode;
        }
        return head;
    }

private:
    ListNode *getkthelem(ListNode *head, int k)
    {
        k -= 1;
        while (head != NULL && k > 0)
        {
            k--;
            head = head->next;
        }
        return head;
    }
    ListNode *reverse(ListNode *head)
    {
        ListNode *temp = head;
        ListNode *prev = NULL;
        ListNode *front = NULL;
        while (temp != NULL)
        {
            front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }
        return prev;
    }
};