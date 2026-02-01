#include <stdlib.h>
#include <stdbool.h>
struct node
{
	int		idx;
	int		value;
	bool	occupied;
};

int	hash(unsigned int seed)
{
	return (seed % 40007);
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	*returnSize = 2;
	int				*answer = malloc(*returnSize * sizeof(int));
	struct node		hash_map[50000] = {0};

	for (int i = 0; i < numsSize; i++)
	{
		int	complement = target - nums[i];
		int	h = hash(complement);
		while (hash_map[h].occupied)
		{
			if (hash_map[h].value == complement)
			{
				answer[0] = hash_map[h].idx;
				answer[1] = i;
				return (answer);
			}
			h = hash(h + 1);
		}
		int	h_new = hash((unsigned int)nums[i]);
		while (hash_map[h_new].occupied == true)
			h_new = hash(h_new + 1);
		hash_map[h_new].idx = i;
		hash_map[h_new].value = nums[i];
		hash_map[h_new].occupied = true;
	}
	free(answer);
	return (NULL);
}
