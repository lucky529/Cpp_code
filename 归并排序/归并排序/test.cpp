void _MergeSort(int* a, int* tmp, int start, int end)//归并排序
{
	if (start >= end) return;
	int mid = start + ((end - start) >> 1);
	_MergeSort(a, tmp, start, mid);
	_MergeSort(a, tmp, mid + 1, end);

	int start1 = start; int end1 = mid;
	int start2 = mid + 1; int end2 = end;

	int index = 0;
	while (start1 <= end1 && start2 <= end2)
	{
		if (a[start1] < a[start2])
		{
			tmp[index++] = a[start1++];
		}
		else
		{
			tmp[index++] = a[start2++];
		}
	}
	while (start1 <= end1)
	{
		tmp[index++] = a[start1++];
	}
	while (start2 <= end2)
	{
		tmp[index++] = a[start2++];
	}
	for (int i = 0; i < index; i++)
	{
		a[start + i] = tmp[i];
	}
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, tmp, 0, n - 1);//传直接可以访问的下标
	free(tmp);
}

//或许我们可以使用归并排序对链表进行排序
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
	ListNode* sortList(ListNode* head) {
		if (head == nullptr || head->next == nullptr) return head;
		ListNode* fast = head->next;//寻找中间节点并拆成两条链表
		ListNode* slow = head;
		while (fast != nullptr && fast->next != nullptr)
		{
			slow = slow->next;
			fast = fast->next->next;
		}
		ListNode* left = head;
		ListNode* right = slow->next;
		slow->next = nullptr;

		ListNode* newleft = sortList(left);//分治的一直将链表拆成一个节点
		ListNode* newright = sortList(right);

		ListNode* newhead;//将链表合成一个新的排序链表
		ListNode* tail;
		if (newleft->val < newright->val)
		{
			newhead = newleft;
			newleft = newleft->next;
		}
		else
		{
			newhead = newright;
			newright = newright->next;
		}
		tail = newhead;
		tail->next = nullptr;

		while (newleft && newright)
		{
			if (newleft->val < newright->val)
			{
				tail->next = newleft;
				newleft = newleft->next;
				tail = tail->next;
				tail->next = nullptr;
			}
			else
			{
				tail->next = newright;
				newright = newright->next;
				tail = tail->next;
				tail->next = nullptr;
			}
		}
		if (newleft)
		{
			tail->next = newleft;
		}
		if (newright)
		{
			tail->next = newright;
		}
		return newhead;
	}
};