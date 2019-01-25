class Solution {
public:
	vector<vector<int>> generate(int numRows) {//用vector实现杨辉三角
		vector<vector<int>> vv(numRows, vector<int>());
		for (int i = 0; i < numRows; i++)
		{
			vv[i].resize(i + 1, 0);
			vv[i][0] = 1;
			vv[i][i] = 1;
		}
		for (int i = 0; i < vv.size(); i++)
		{
			for (int j = 0; j < vv[i].size(); j++)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
				}
			}
		}

		return vv;
	}
};