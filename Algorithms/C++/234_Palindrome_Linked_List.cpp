/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL) {
            return true;
        }

        ListNode* mid = find_middle(head);
        ListNode* node = reverse(mid->next);
        mid->next = NULL;

        while (node != NULL && head->val == node->val) {
            head = head->next;
            node = node->next;
        }
        return node == NULL;
    }
private:
    ListNode* get_middle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;

        while (fast != NULL && fast->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;

        while (head != NULL) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }
};
