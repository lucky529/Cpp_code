class Solution {
public:
	/*int countsum(string s,int start,int end)//计数二进制字符
	{
	int arr[2] = {0};
	for(int i = start;i < end;i++)
	{
	if(s[i] == '0') arr[0]++;
	if(s[i] == '1') arr[1]++;
	}
	if(arr[0] < arr[1]) return arr[0];
	return arr[1];
	}*/
	int countBinarySubstrings(string s) {
		/*int j = 0;
		int sum = 0;
		int cur = 0;
		for(int i = 0;i < s.size();)
		{
		while(s[i] == s[j] && i < s.size())
		{
		i++;
		}
		cur = i;
		while(s[i] == s[cur] && i < s.size())
		{
		i++;
		}
		sum += countsum(s,j,i);
		if(i == s.size()) break;
		i = j = cur;
		}
		return sum;*/
		int last = 0, cur = 1, res = 0;
		for (int i = 1; i < s.size(); i++)
		{
			if (s[i - 1] == s[i])
				cur++;
			else
			{

				last = cur;
				cur = 1;
			}
			if (last >= cur)
				res++;
		}
		return res;
	}
};

class Solution {
public:
	bool checkRecord(string s) {//学生出勤记录
		int Acount = 0;
		for (int i = 0; i < s.size(); i++)//统计A字符的数量
		{
			if (s[i] == 'A')
				Acount++;
			if (Acount > 1)
				return false;
		}

		for (int i = 1; i < s.size() - 1; i++)//判断A是否3个以上连续
		{
			if (s[i] == s[i - 1] && s[i] == s[i + 1] && s[i] == 'L')
			{
				return false;
			}
		}
		return true;
	}
};

class Solution {
public:
	int repeatedStringMatch(string A, string B) {//叠加字符串计数
		string C = "";
		int sizeA = A.size();
		int sizeB = B.size();
		for (int i = 0; i < sizeB / sizeA + 1; i++) {
			C += A;
			if (findStr(C, B)) {
				return i + 1;
			}
		}

		return -1;
	}
	bool findStr(string str1, string str2) {
		size_t fi = str1.find(str2, 0);
		if (fi != str1.npos)
		{

			return true;

		}
		return false;
	}
};