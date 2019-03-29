#include<algorithm>
#include<windows.h>
#include<iostream>
#include<vector>
#include<string>

using namespace std;
/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
* };
*/
class Solution {//失败的代码，等待改进
public:
	struct QueueNode
	{
		TreeNode* root;
		long index;
		long x;
		QueueNode(TreeNode* _root, int _index, int _x) :root(_root), index(_index), x(_x){}
	};
	class CmpNameLess//自定义
	{
	public:
		bool operator()(QueueNode& l, QueueNode& q)
		{
			return l.x < q.x;
		}
	};
	int flag = 0;
	vector<vector<int>> verticalTraversal(TreeNode* root) {
		vector<vector<int>> vv;
		vector<QueueNode*> v;
		queue<QueueNode*> q;
		q.push(new QueueNode(root, 0, 0));
		//int width = 0;
		int min = 0;
		int max = 0;

		while (!q.empty())
		{
			int num = q.size();

			for (int i = 0; i <num; i++)
			{
				QueueNode* node = q.front();
				min = q.front()->index < min ? q.front()->index : min;
				max = q.front()->index > max ? q.front()->index : max;
				flag = abs(min) > flag ? abs(min) : flag;
				q.pop();
				v.push_back(node);
				if (node->root->left) q.push(new QueueNode(node->root->left, node->index - 1, node->x + 1));
				if (node->root->right) q.push(new QueueNode(node->root->right, node->index + 1, node->x + 1));
			}
		}
		sort(v.begin(), v.end(), CmpNameLess);
		vv.resize(max - min + 1);
		for (int i = 0; i < v.size(); i++)
		{
			vv[v[i]->index + flag].push_back(v[i]->root->val);
		}
		return vv;
	}
};
int main()
{
	/*vector<QueueNode*> v;
	v.push_back(new QueueNode(nullptr, 0, 0));
	v.push_back(new QueueNode(nullptr, 0, 1));
	v.push_back(new QueueNode(nullptr, 0, 2));
	sort(v.begin(), v.end(), CmpNameLess);*/

	vector<string> v = { "a1 9 2 3 1", "g1 act car", "zo4 4 7" };
	vector<string> b = { "ab1 off key dog", "a8 act zoo" };
	v.assign(b.begin(), b.end());
	//swap(v[0], v[1]);
	reorderLogFiles(v);
	system("pause");
	return 0;
}