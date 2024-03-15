
// time | space
// O(1), [worst => in case of Hashmap's worst case] = O(N) | O(n)

class Node
{
public:
    int k;
    int value;
    Node *next;
    Node *prev;

    Node(int key, int value1)
    {
        k = key;
        value = value1;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache
{
public:
    LRUCache(int capacity)
    {
        cap = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    int get(int key)
    {
        if (m_cache.count(key))
        {
            remove(m_cache[key]);
            insert(m_cache[key]);
            return m_cache[key]->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if (m_cache.count(key))
        {
            remove(m_cache[key]);
            delete m_cache[key];
        }

        m_cache[key] = new Node(key, value);
        insert(m_cache[key]);

        if (m_cache.size() > cap)
        {
            Node *lru = tail->prev;
            m_cache.erase(lru->k);
            remove(lru);
            delete lru;
        }
    }

private:
    int cap;
    unordered_map<int, Node *> m_cache;
    Node *head;
    Node *tail;

    void remove(Node *node)
    {
        Node *next = node->next;
        Node *prev = node->prev;
        prev->next = next;
        next->prev = prev;
    }

    void insert(Node *node)
    {
        Node *temp = head->next;
        head->next = node;
        node->next = temp;
        node->prev = head;
        temp->prev = node;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */