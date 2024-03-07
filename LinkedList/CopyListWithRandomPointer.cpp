/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// using hashmap
// time | space
// O(N) + O(N) => O(2N)  |  O(N) + O(N)* => O(2N)

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        Node *temp = head;
        unordered_map<Node *, Node *> mp;

        // inputting clones in map as values
        while (temp != NULL)
        {
            Node *newnode = new Node(temp->val);
            mp[temp] = newnode;
            temp = temp->next;
        }

        // linking the clones
        temp = head;
        while (temp != NULL)
        {
            Node *copynode = mp[temp];
            copynode->next = mp[temp->next];
            copynode->random = mp[temp->random];
            temp = temp->next;
        }
        return mp[head];
    }
};

// without using hashmap
// time | space
// O(N) + O(N) + O(N) => O(3N)  |  O(N)*

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {

        // linking in b/w the orignal list
        Node *temp = head;
        while (temp != NULL)
        {
            Node *newnode = new Node(temp->val);
            newnode->next = temp->next;
            temp->next = newnode;
            temp = temp->next->next;
        }

        // linking the randoms
        temp = head;
        while (temp != NULL)
        {
            Node *copynode = temp->next;
            if (temp->random == nullptr)
                copynode->random = nullptr;
            else
                copynode->random = temp->random->next;
            temp = temp->next->next;
        }

        // linking the next
        Node *dnode = new Node(-1);
        Node *res = dnode;
        temp = head;
        while (temp != NULL)
        {
            res->next = temp->next;
            temp->next = temp->next->next;
            temp = temp->next;
            res = res->next;
        }
        return dnode->next;
    }
};
