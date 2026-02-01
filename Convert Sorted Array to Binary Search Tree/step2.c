
struct TreeNode
{
	int	val;
	struct TreeNode	*left;
	struct TreeNode	*right;
};

#include <stdlib.h>

static struct TreeNode* binary_serch(int *nums, int left, int right);

struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
	return (binary_serch(nums, 0, numsSize - 1));
}

static struct TreeNode* binary_serch(int *nums, int left, int right)
{
	if (left > right)
		return (NULL);
	struct TreeNode	*node = malloc(sizeof(struct TreeNode));
	int	mid = left + (right - left) / 2;
	node->val = nums[mid];
	node->left = binary_serch(nums, left, mid - 1);
	node->right = binary_serch(nums, mid + 1, right);
	return (node);
}
