/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        hash.clear();

        RandomListNode* new_head = copy_next(head);
        copy_random(head);

        return new_head;
    }
private:
    unordered_map<RandomListNode*, RandomListNode*> hash;

    RandomListNode* copy_next(RandomListNode* head) {
        RandomListNode dummy(0);
        RandomListNode* node = &dummy;

        while (head != NULL) {
            RandomListNode* new_node = new RandomListNode(head->label);
            hash[head] = new_node;
            node->next = new_node;
            node = node->next;
            head = head->next;
        }

        hash[NULL] = NULL;

        return dummy.next;
    }

    void copy_random(RandomListNode* head) {
        while (head != NULL) {
            RandomListNode* new_node = hash[head];
            new_node->random = hash[head->random];
            head = head->next;
        }
    }
};
