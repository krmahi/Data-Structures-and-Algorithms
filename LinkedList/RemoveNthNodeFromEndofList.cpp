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
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        int count, k;
        if (head == NULL || (head -> next == NULL && n == 1)
            return NULL;
    }
    int count = lengthlist(head);
    int k = (count - n) + 1;
    removenthelement(head, k, count);
    return head;

private:
    int lengthlist(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    void removenthelement(ListNode *&head, int k, int size)
    {
        ListNode *temp = head;
        ListNode *front = NULL;
        if (k == 1)
        {
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return;
        }

        int count = 1;
        while (temp != NULL)
        {
            if (count == k - 1)
            {
                front = temp->next;
                if (front == nullptr)
                    break;
                temp->next = front->next;
                front->next = nullptr;
                delete front;
                return;
            }
            temp = temp->next;
            count++;
        }
    }
};