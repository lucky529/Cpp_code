class Solution {
public:
	TreeNode* GetMin(TreeNode* root)//Ѱ������������С��Ҷ�ӽڵ�
	{
		if (root->left == nullptr)
		{
			return root;
		}
		return GetMin(root->left);
	}
	TreeNode* DeleMin(TreeNode* root)//ɾ�����������������С�Ľڵ㣬����������ĸ��ڵ�û������������ôֱ�ӷ���
		//
	{
		if (root->left == nullptr)
		{
			return root->right;
		}
		root->left = DeleMin(root->left);
		return root;
	}
	TreeNode* deleteNode(TreeNode* root, int key) {
		if (root == nullptr) return nullptr;
		if (key < root->val)
		{
			root->left = deleteNode(root->left, key);
			return root;
		}
		else if (key > root->val)
		{
			root->right = deleteNode(root->right, key);
			return root;
		}
		else
		{
			if (root->left == nullptr)
			{
				return root->right;
			}
			else if (root->right == nullptr)
			{
				return root->left;
			}
			else
			{
				TreeNode* newnode = GetMin(root->right);
				newnode->right = DeleMin(root->right);
				newnode->left = root->left;
				return newnode;
			}
		}
	}
};


class Solution {
public:
	vector<int> v;
	int GetElement(TreeNode* root)//��ʹ��map�����������Ԫ�غ�
	{
		if (!root) return 0;
		int left = GetElement(root->left);
		int right = GetElement(root->right);
		v.push_back(root->val + left + right);

		return root->val + left + right;
	}
	vector<int> findFrequentTreeSum(TreeNode* root) {
		if (!root) return v;
		GetElement(root);
		sort(v.begin(), v.end());
		vector<int> tmp;

		int cur = 0;
		int pre = 0;
		int max = 0;
		int count = 0;
		while (cur < v.size())
		{
			while (cur < v.size() && v[cur] == v[pre])
			{
				cur++;
				count++;
			}
			if (count == max)
			{
				count = 0;
				tmp.push_back(v[pre]);
			}
			if (count > max)
			{
				tmp.clear();
				tmp.push_back(v[pre]);
				max = count;
				count = 0;
			}
			count = 0;
			pre = cur;
		}
		return tmp;
	}
};