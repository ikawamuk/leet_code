#include <stdlib.h>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
};



int maxDepth(struct TreeNode* root)
{
	return (get_depth(root, 0));
}

int	get_depth(struct TreeNode* node, int depth)
{
	if (!node)
		return (depth);
	int	left_depth = get_depth(node->left, depth + 1);
	int	right_depth = get_depth(node->right, depth + 1);
	return (left_depth < right_depth ? right_depth : left_depth);
}
