/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {//ɾ���������ظ��Ľڵ�2����ʹ���ƽڵ㣩
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* cur = head;
		ListNode* next = cur->next;
		ListNode* prev = nullptr;
		while (next)
		{
			if (cur->val == next->val)
			{
				next = next->next;//����next��λ��
				while (next && next->val == cur->val)
				{
					next = next->next;
				}
				while (cur != next)
				{
					cur = cur->next;
				}

				//�ж��Ƿ�ɾ������ͷ�ڵ�
				if (prev == nullptr)
				{
					head = next;
				}
				else
				{
					prev->next = next;
				}

				if (next)
				{
					next = next->next;
				}
			}
			else
			{
				prev = cur;
				cur = next;
				next = next->next;
			}
		}
		return head;
	}
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* deleteDuplicates(ListNode* head) {//ɾ���ظ�������ڵ㣬ʹ���ƽڵ�
		ListNode* dum = new ListNode(-1);
		dum->next = head;
		ListNode* ret = dum;
		while (dum->next)
		{
			int val = dum->next->val;
			ListNode* cur = dum->next;
			if (cur->next && cur->next->val == val)
			{
				while (cur->next && cur->next->val == val)
				{
					cur = cur->next;
				}
				dum->next = cur->next;
			}
			else
			{
				dum = dum->next;
			}
		}
		return ret->next;
	}
};

/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/
class Solution {
public:
	ListNode* oddEvenList(ListNode* head) {//��ż����
		ListNode* evenlist = new ListNode(-1);
		ListNode* oddlist = new ListNode(-1);
		ListNode* elh = evenlist;
		ListNode* olh = oddlist;
		int flag = 1;
		while (head)
		{
			if (flag == 1)
			{
				ListNode* tmp = head;
				head = head->next;
				olh->next = tmp;
				olh = olh->next;

				flag = (-1)*flag;
			}
			if (flag == -1)
			{
				if (head == NULL) break;
				ListNode* tmp = head;
				head = head->next;
				elh->next = tmp;
				elh = elh->next;

				flag = (-1)*flag;
			}
		}
		olh->next = evenlist->next;
		elh->next = nullptr;
		return oddlist->next;
	}
};