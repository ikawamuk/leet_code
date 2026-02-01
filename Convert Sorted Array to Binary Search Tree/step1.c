/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode
{
	int	val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

#include <stdlib.h>

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	if (!nums || numsSize == 0)
		return (NULL);
	struct TreeNode	*node = malloc(sizeof(struct TreeNode));
	int	mid = numsSize / 2;
	node->val = nums[mid];
	node->left = sortedArrayToBST(nums, mid);
	node->right = sortedArrayToBST(nums + mid + 1, numsSize - mid - 1);
	return (node);
}
