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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) {
            return NULL;
        }

        return helper(lists, 0, lists.size() - 1);
    }
private:
    ListNode* helper(vector<ListNode*>& lists, int start, int end) {
        if (start > end) {
            return NULL;
        } else if (start == end) {
            return lists[start];
        }

        int mid = start + (end - start) / 2;
        ListNode* left = helper(lists, start, mid);
        ListNode* right = helper(lists, mid + 1, end);

        return merge(left, right);
    }

    ListNode* merge(ListNode* headA, ListNode* headB) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while (headA != NULL && headB != NULL) {
            if (headA->val < headB->val) {
                node->next = headA;
                headA = headA->next;
            } else {
                node->next = headB;
                headB = headB->next;
            }
            node = node->next;
        }

        if (headA != NULL) {
            node->next = headA;
        }
        if (headB != NULL) {
            node->next = headB;
        }

        return dummy.next;
    }
};
