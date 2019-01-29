//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {//数组中出现一半的数字（使用范围数组数字范围大小的辅助空间）
//		int max = numbers[0];
//		int min = numbers[0];
//		int part = 0;
//		for (int i = 0; i < numbers.size(); i++)
//		{
//			if (numbers[i] > max)
//			{
//				max = numbers[i];
//			}
//			if (numbers[i] < min)
//			{
//				min = numbers[i];
//			}
//		}
//		part = max - min + 1;
//		int* countarr = new int[part];
//		memset(countarr, 0, sizeof(int)*part);
//		for (int i = 0; i< numbers.size(); i++)
//		{
//			countarr[numbers[i] - min]++;
//		}
//		for (int i = 0; i < part; i++)
//		{
//			if (countarr[i] >(numbers.size() / 2))
//			{
//				return i + min;
//			}
//		}
//		return 0;
//	}
//};
//
//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {//不使用辅助空间且遍历一遍（方法最优）
//		int size = numbers.size();
//		if (size == 0) return 0;
//		int count = 0, num = numbers[0];
//		for (int i = 0; i < size; i++)
//		{
//			if (num == numbers[i])
//			{
//				count++;
//			}
//			else
//			{
//				count--;
//			}
//
//			if (count < 0)
//			{
//				num = numbers[i];
//			}
//		}
//		count = 0;
//		for (int i = 0; i < size; i++)
//		{
//			if (num == numbers[i])
//			{
//				count++;
//			}
//		}
//		if (count >(size / 2))
//		{
//			return num;
//		}
//
//		return 0;
//	}
//};
//
//class Solution {
//public:
//	int FindGreatestSumOfSubArray(vector<int> array) {//最大子序列和动态规划法
//		int ret = array[0];
//		int sum = 0;
//		for (auto num : array)//某数是否可以入列判断入列前sum是否为为正
//		{
//			if (sum > 0)
//			{
//				sum += num;
//			}
//			else//如果入列前序列已经为负数，那么最大序列可能从从数字开始
//			{
//				sum = num;
//			}
//			ret = ret > sum ? ret : sum;//ret一直保留目前最大的子序列
//		}
//		return ret;
//	}
//};