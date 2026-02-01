int searchInsert(int* nums, int numsSize, int target)
{
	if (numsSize == 1)
	{
		if (target <= *nums)
			return (0);
		return (1);
	}
	int	half = numsSize / 2;
	if (nums[half] == target)
		return (half);
	if (target < nums[half])
		return (searchInsert(nums, half, target));
	return ((numsSize % 2) + half + searchInsert(nums + half + (numsSize % 2), half, target));
}
