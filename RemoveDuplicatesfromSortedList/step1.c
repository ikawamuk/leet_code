/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode {
	int val;
	struct ListNode *next;
};



struct ListNode* deleteDuplicates(struct ListNode* head)
{
	struct ListNode	*cur = head;
	struct ListNode	*next;

	if (!head)
		return (head);
	while (cur->next)
	{
		next = cur->next;
		if (cur->val == next->val)
		{
			cur->next = next->next;
			continue ;
		}
		cur = next;
	}
	return (head);
}