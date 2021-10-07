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
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
    {

        ListNode *head, *n = new ListNode();
        head = n;
        while (l1 != NULL && l2 != NULL) {
            if (l1->val <= l2->val) {
                n->next = l1;
                l1 = l1->next;
            }
            else {
                n->next = l2;
                l2 = l2->next;
            }
            n = n->next;
        }
        if (l1 == NULL)
            n->next = l2;
        else
            n->next = l1;
        head = head->next;
        return head;
    }
};