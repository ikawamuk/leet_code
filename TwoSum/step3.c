#include <stdlib.h>
#include <stdbool.h>

struct MapNode
{
	int		idx;
	int		data;
	bool	occupied;
};

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize)
{
	*returnSize = 2;
	int	*answer = malloc(*returnSize * sizeof(int));
	struct MapNode	hash_map[40000] = {0};

	for (int i = 0; i < numsSize; i++)
	{
		int	complement = target - nums[i];
		unsigned int	h = abs(complement) % 39989;
		while (hash_map[h].occupied)
		{
			if (hash_map[h].data == complement)
			{
				answer[0] = hash_map[h].idx;
				answer[1] = i;
				return (answer);
			}
			h = (h + 1) % 39989;
		}
		unsigned int	h_new = abs(nums[i]) % 39989;
		while (hash_map[h_new].occupied)
			h_new = (h_new + 1) % 39989;
		hash_map[h_new].idx = i;
		hash_map[h_new].data = nums[i];
		hash_map[h_new].occupied = true;
	}
	free(answer);
	*returnSize = 0;
	return (NULL);
}
