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
    ListNode* plusOne(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* reversedHead = reverse(head);
        addOne(reversedHead);

        return reverse(reversedHead);
    }
private:
    ListNode* reverse(ListNode* head) {
        if (head == NULL) {
            return NULL;
        }

        ListNode* prev = NULL;
        while (head != NULL) {
            ListNode* tmp = head->next;
            head->next = prev;
            prev = head;
            head = tmp;
        }

        return prev;
    }

    void addOne(ListNode* head) {
        if (head == NULL) {
            return;
        }

        int carry = 1;
        ListNode* prev = NULL;
        while (head != NULL) {
            head->val += carry;

            carry = head->val / 10;
            head->val %= 10;

            prev = head;
            head = head->next;
        }

        if (carry != 0) {
            ListNode* newNode = new ListNode(carry);
            prev->next = newNode;
        }
    }
};
