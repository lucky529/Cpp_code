#include<iostream>
#include<string>
using namespace std;

//string Max = "2147483647";
//string Min = "2147483648";
//int aoti(string s)
//{
//	if (s.size() == 0) return 0;
//	int flag = 0;
//	if (s[0] == ' ')
//	{
//		int cur = 0;
//		while (s[cur] == ' ')
//			cur++;
//		s = s.substr(cur);
//	}
//	if (s[0] != '-' && s[0] != '+'&& !(s[0] >= '0' && s[0] <= '9'))
//		return 0;
//	if (s[0] == '-')
//	{
//		flag = 1;
//		s = s.substr(1);
//	}
//	if (s[0] == '0')
//	{
//		int cur = 0;
//		while (s[cur] == '0')
//			cur++;
//		s = s.substr(cur);
//	}
//	if (s[0] == '+')
//	{
//		s = s.substr(1);
//	}
//	int cur = 0;
//	while (s[cur] >= '0' && s[cur] <= '9')
//		cur++;
//	s = s.substr(0, cur);
//	if (s.size() >= 10 && flag == 0)
//	{
//		if (s.size() > 10)return 2147483647;
//		if (s.size() == 10 && s > Max)
//			return 2147483647;			
//	}
//	if (s.size() >= 10 && flag == 1)
//	{
//		if (s.size() > 10)return 2147483647+1;
//		if (s.size() == 10 && s > Min)
//			return 2147483647+1;
//	}
//	int ret = 0;
//	reverse(s.begin(), s.end());
//	while (0 < s.size())
//	{
//		ret = ret * 10 + ((int)(s[s.size()-1] - '0'))%10;
//		s.pop_back();
//	}
//	return flag == 1 ? -ret : ret;
//}
string intToRoman(int num)
{
	/*int flag = 10;
	int pos = 0;
	string ret = "";
	pos = num%flag;
	if (pos != 0)
	{
		string tmp = "";
		if (pos <= 3)
		{
			for (int i = 0; i < pos; i++)
				tmp += 'I';
		}
		else if (pos == 4) tmp += "IV";
		else if (pos == 9) tmp += "IX";
		else
		{
			tmp = "V"; pos = pos % (flag / 2);
			for (int i = 0; i < pos; i++)
				tmp += 'I';
		}
		ret = tmp; num/= 10;
	}
	else
	{
		string tmp = "";
		if (pos <= 3)
		{
			for (int i = 0; i < pos; i++)
				tmp += 'X';
		}
		else if (pos == 4) tmp += "XL";
		else if (pos == 9) tmp += "XC";
		else
		{
			tmp = "L"; pos = pos % (flag / 2);
			for (int i = 0; i < pos; i++)
				tmp += 'X';
		}
		ret.insert(0, tmp); num /= 10;
	}
	pos = num%flag;
	if (pos != 0)
	{
		string tmp = "";
		if (pos <= 3)
		{
			for (int i = 0; i < pos; i++)
				tmp += 'X';
		}
		else if (pos == 4) tmp += "XL";
		else if (pos == 9) tmp += "XC";
		else
		{
			tmp = "L"; pos = pos % (flag / 2);
			for (int i = 0; i < pos; i++)
				tmp += 'X';
		}
		ret.insert(0, tmp); num /= 10;
	}
	else
	{
		string tmp = "";
		if (pos <= 3)
		{
			for (int i = 0; i < pos; i++)
				tmp += 'C';
		}
		else if (pos == 4) tmp += "CD";
		else if (pos == 9) tmp += "CM";
		else
		{
			tmp = "L"; pos = pos % (flag / 2);
			for (int i = 0; i < pos; i++)
				tmp += 'C';
		}
		ret.insert(0, tmp); num /= 10;
	}
	pos = num%flag;
	if (pos != 0)
	{
		string tmp = "";
		if (pos <= 3)
		{
			for (int i = 0; i < pos; i++)
				tmp += 'C';
		}
		else if (pos == 4) tmp += "CD";
		else if (pos == 9) tmp += "CM";
		else
		{
			tmp = "L"; pos = pos % (flag / 2);
			for (int i = 0; i < pos; i++)
				tmp += 'C';
		}
		ret.insert(0, tmp); num /= 10;
	}
	else
	{
		string tmp = "";
		for (int i = 0; i < pos; i++)
			tmp += 'M';
		ret.insert(0, tmp);
	}
	pos = num%flag;
	if (pos != 0)
	{
		string tmp = "";
		for (int i = 0; i < pos; i++)
			tmp += 'M';
		ret.insert(0, tmp);
	}
	return ret;*/
	int values[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string reps[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };

	string res;
	for (int i = 0; i<13; i++){
		while (num >= values[i]){
			num -= values[i];
			res += reps[i];
		}
	}
	return res;
}
int main()
{	
	cout << intToRoman(20) << endl;
	system("pause");
	return 0;
}