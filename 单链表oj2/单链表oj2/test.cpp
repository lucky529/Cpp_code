///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     ListNode *next;
//*     ListNode(int x) : val(x), next(NULL) {}
//* };
//*/
//class Solution {//重排链表
//public:
//	ListNode* middleNode(ListNode* head)//寻找链表的中间节点
//	{
//		struct ListNode* fast = head;
//		struct ListNode* slow = head;
//		while (fast&& fast->next)
//		{
//			slow = slow->next;
//			fast = fast->next->next;
//		}
//		return slow;
//	}
//
//	ListNode* reverseList(ListNode* head)//反转单链表
//	{
//		if (head == NULL || head->next == NULL) return head;
//		struct ListNode* newhead = NULL;
//		while (head != NULL)
//		{
//			struct ListNode* next = head->next;
//			head->next = newhead;
//			newhead = head;
//			head = next;
//		}
//		return newhead;
//	}
//
//	void reorderList(ListNode* head) {
//		if (head == nullptr || head->next == nullptr) return;
//		ListNode* midnode = middleNode(head);
//		ListNode* revenode = midnode->next;
//		midnode->next = nullptr;
//		revenode = reverseList(revenode);
//
//		ListNode* cur = head;//对后一段链表进行向前一个链表的插入
//		while (cur && revenode)
//		{
//			ListNode* next = revenode->next;
//			revenode->next = cur->next;
//			cur->next = revenode;
//
//			revenode = next;
//			cur = cur->next->next;
//		}
//	}
//};
//
//
///**
//* Definition for singly-linked list.
//* struct ListNode {
//*     int val;
//*     ListNode *next;
//*     ListNode(int x) : val(x), next(NULL) {}
//* };
//*/
//class Solution {
//public:
//	ListNode* reverseList(ListNode* head) {//两数相加2
//		if (head == nullptr || head->next == nullptr) return head;
//		ListNode* dum = new ListNode(-1);
//		dum->next = head;
//		ListNode* newhead = dum;
//
//		ListNode* q = dum, *t = head, *p = head->next;
//		while (t->next)
//		{
//			t->next = p->next;
//			p->next = q->next;
//			q->next = p;
//
//			p = t->next;
//		}
//		return newhead->next;
//	}
//	int Size(ListNode* l1)
//	{
//		int count = 0;
//		ListNode* cur = l1;
//		while (l1)
//		{
//			count++;
//			l1 = l1->next;
//		}
//		return count;
//	}
//	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
//		while (Size(l1) < Size(l2))
//		{
//			ListNode* tmp = new ListNode(0);
//			tmp->next = l1;
//			l1 = tmp;
//		}
//		while (Size(l2) < Size(l1))
//		{
//			ListNode* tmp = new ListNode(0);
//			tmp->next = l2;
//			l2 = tmp;
//		}
//		l1 = reverseList(l1);
//		l2 = reverseList(l2);
//
//		ListNode* newlist = nullptr;
//		int sum = 0;
//		while (l1 && l2)
//		{
//			int tmp = l1->val + l2->val;
//			sum = sum + tmp;
//			ListNode* tmpnode = new ListNode(sum % 10);
//			tmpnode->next = newlist;
//			newlist = tmpnode;
//			sum /= 10;
//
//			l1 = l1->next;
//			l2 = l2->next;
//		}
//		if (sum != 0)
//		{
//			ListNode* tmpnode = new ListNode(1);
//			tmpnode->next = newlist;
//			newlist = tmpnode;
//		}
//		return newlist;
//	}
//};
/**
* Definition for singly-linked list.
* struct ListNode {
*     int val;
*     ListNode *next;
*     ListNode(int x) : val(x), next(NULL) {}
* };
*/

//class Solution {//分隔链表
//public:
//	int GetListSize(ListNode* root)
//	{
//		if (root == nullptr) return 0;
//		ListNode* cur = root;
//		int size = 0;
//		while (cur)
//		{
//			size++;
//			cur = cur->next;
//		}
//		return size;
//	}
//	vector<ListNode*> splitListToParts(ListNode* root, int k) {
//		int size = GetListSize(root);
//		vector<ListNode*> ret(k, nullptr);
//		int tag = size%k;
//		ListNode* cur = root;
//		int index = 0;
//		while (cur)
//		{
//			int x = size / k;
//			ListNode* tmp = cur;
//			if (tag != 0)
//			{
//				tag--;
//				x += 1;
//			}
//
//			ListNode* tmpnode;
//			while (x--)
//			{
//				if (x == 0)
//				{
//					tmpnode = tmp;
//				}
//				tmp = tmp->next;
//			}
//			tmpnode->next = nullptr;
//			ret[index++] = cur;
//			cur = tmp;
//		}
//		return ret;
//	}
//};
