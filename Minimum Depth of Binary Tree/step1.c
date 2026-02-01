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

int minDepth(struct TreeNode* root)
{
	if (!root)
		return (0);
	int	left_depth = minDepth(root->left);
	int	right_depth = minDepth(root->right);
	return (left_depth < right_depth ? left_depth + 1 : right_depth + 1);
}
