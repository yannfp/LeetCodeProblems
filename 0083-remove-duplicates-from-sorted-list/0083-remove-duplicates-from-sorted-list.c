/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* deleteDuplicates(struct ListNode* head)
{
    if (!head)
        return NULL;

    struct ListNode *node = head->next;

    struct ListNode *prev = head;

    while (node != NULL)
    {
        // Found a duplicate
        if (prev->val == node->val)
        {
            prev->next = node->next;

            node = node->next;
        }
        else
        {
            prev = node;
            node = node->next;
        }
    }

    return head;
}