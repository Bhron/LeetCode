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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        ListNode* tailA = headA;
        while (tailA->next != NULL) {
            tailA = tailA->next;
        }

        tailA->next = headA;

        ListNode* fast = headB->next;
        ListNode* slow = headB;

        while (fast != slow) {
            if (fast == NULL || fast->next == NULL) {
                tailA->next = NULL;
                return NULL;
            }
            fast = fast->next->next;
            slow = slow->next;
        }

        while (headB != slow->next) {
            headB = headB->next;
            slow = slow->next;
        }
        tailA->next = NULL;

        return headB;
    }
};
