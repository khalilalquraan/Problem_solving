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
    bool t;
    ListNode* removeNthFromEnd(ListNode* head, int n)
    {

        t = true;
        int co = 0;
        deleteNode(head, n, co);
        if (t) {
            head = head->next;
        }
        return head;
    }
    void deleteNode(ListNode* head, int n, int& co)
    {
        if (head == NULL)
            return;

        deleteNode(head->next, n, co);
        co++;
        if (co == n + 1 && head->next != NULL) {
            t = false;
            //head->val = head->next->val;
            ListNode* tmp = head->next;
            head->next = tmp->next;
        }
        return;
    }
};