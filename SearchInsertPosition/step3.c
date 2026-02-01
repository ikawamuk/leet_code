int searchInsert(int* nums, int numsSize, int target)
{
	int	left = 0;
	int	right = numsSize - 1;

	while (left < right)
	{
		int	mid = (left + right) / 2;
		if (target == nums[mid])
			return (mid);
		if (target < nums[mid])
			right = mid - 1;
		else if (target > nums[mid])
			left = mid + 1;
	}
	if (target <= nums[left])
		return (left);
	return (left + 1);
}
