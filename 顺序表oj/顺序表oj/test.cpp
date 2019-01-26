class Solution {
public:
	int singleNumber(vector<int>& nums) {//只出现一次的数字1
		int value = 0;
		for (size_t i = 0; i < nums.size(); ++i){
			value ^= nums[i];
		}
		return value;
	}
};

class Solution {
public:
	int singleNumber(vector<int>& nums) {//只出现一次的数字2
		int arr[32] = { 0 };
		int i = 0, ret = 0;
		while (i < 32)
		{
			for (int j = 0; j < nums.size(); j++)
			{
				if (((nums[j] >> i) & 1) == 1)
				{
					arr[i]++;
				}
			}
			ret |= ((arr[i] % 3) << i);
			i++;
		}

		return ret;
	}
};

class Solution {
public:
	vector<int> singleNumber(vector<int>& nums) {//只出现一次的数字3
		vector<int> ret;
		int sum = 0, pos = 0;
		for (int i = 0; i<nums.size(); i++)//寻找pos位
		{
			sum ^= nums[i];
		}
		for (int i = 0; i<32; i++)
		{
			if (((sum >> i) & 1) == 1)
			{
				pos = i;
				break;
			}
		}

		int arr1[nums.size()] = { 0 };
		int arr2[nums.size()] = { 0 };
		int index1 = 0, index2 = 0;

		for (int i = 0; i<nums.size(); i++)//将数字分组
		{
			if (((nums[i] >> pos) & 1) == 1)
			{
				arr1[index1++] = nums[i];
			}
			if (((nums[i] >> pos) & 1) == 0)
			{
				arr2[index2++] = nums[i];
			}
		}

		int num1 = 0; int num2 = 0;
		for (int i = 0; i < index1; i++)//分别对俩组数字进行异或
		{
			num1 ^= arr1[i];
		}
		for (int i = 0; i < index2; i++)
		{
			num2 ^= arr2[i];
		}

		ret.push_back(num1);
		ret.push_back(num2);

		return ret;
	}
};