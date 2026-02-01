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
	struct TreeNode* queue[20000];
	int head = 0;
	int	tail = 0;
	int	depth = 1;

	queue[tail++] = root;
	while (head < tail)
	{
		int level_size = tail - head;
		for (int i = 0; i < level_size; i++)
		{
			if (!queue[head]->left && !queue[head]->right)
				return (depth);
			if (queue[head]->left)
				queue[tail++] = queue[head]->left;
			if (queue[head]->right)
				queue[tail++] = queue[head]->right;
			head++;
		}
		depth++;
	}
	return (depth);
}
