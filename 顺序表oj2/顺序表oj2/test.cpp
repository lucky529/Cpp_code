//class Solution {
//public:
//	int MoreThanHalfNum_Solution(vector<int> numbers) {//�����г���һ������֣�ʹ�÷�Χ�������ַ�Χ��С�ĸ����ռ䣩
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
//	int MoreThanHalfNum_Solution(vector<int> numbers) {//��ʹ�ø����ռ��ұ���һ�飨�������ţ�
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
//	int FindGreatestSumOfSubArray(vector<int> array) {//��������кͶ�̬�滮��
//		int ret = array[0];
//		int sum = 0;
//		for (auto num : array)//ĳ���Ƿ���������ж�����ǰsum�Ƿ�ΪΪ��
//		{
//			if (sum > 0)
//			{
//				sum += num;
//			}
//			else//�������ǰ�����Ѿ�Ϊ��������ô������п��ܴӴ����ֿ�ʼ
//			{
//				sum = num;
//			}
//			ret = ret > sum ? ret : sum;//retһֱ����Ŀǰ����������
//		}
//		return ret;
//	}
//};