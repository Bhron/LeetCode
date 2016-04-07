class LRUCache{
public:
    LRUCache(int capacity) {
        dummy = new ListNode(0, 0);
        tail = dummy;
        this->capacity = capacity;
        size = 0;
    }

    int get(int key) {
        if (hash.find(key) == hash.end()) {
            return -1;
        }

        ListNode* prev = hash[key];
        int val = prev->next->val;
        move_to_tail(prev);

        return val;
    }

    void set(int key, int value) {
        if (hash.find(key) != hash.end()) {
            ListNode* prev= hash[key];
            prev->next->val = value;
            move_to_tail(prev);
        } else {
            ListNode* new_node = new ListNode(key, value);

            tail->next = new_node;
            hash[key] = tail;
            tail = new_node;

            size++;

            if (size > capacity) {
                ListNode* head = dummy->next;

                dummy->next = head->next;
                if (dummy->next != NULL) {
                    hash[dummy->next->key] = dummy;
                }

                hash.erase(head->key);
                delete head;

                size--;
            }
        }
    }
private:
    class ListNode {
    public:
        int key;
        int val;
        ListNode* next;

        ListNode(int key, int val) {
            this->key = key;
            this->val = val;
            this->next = NULL;
        }
    };

    ListNode* dummy;
    ListNode* tail;

    int capacity, size;

    unordered_map<int, ListNode*> hash;

    void move_to_tail(ListNode* prev) {
        if (prev->next == tail) {
            return;
        }

        ListNode* node = prev->next;

        prev->next = node->next;
        if (node->next != NULL) {
            hash[node->next->key] = prev;
        }

        node->next = NULL;

        tail->next = node;
        hash[node->key] = tail;
        tail = node;
    }
};
