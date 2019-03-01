ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	static int sum = 0;
	ListNode* newlist = new ListNode(0);
	ListNode* a = l1;
	ListNode* b = l2;
	ListNode* ret = newlist;
	while (a && b)
	{
		int tmp = a->val + b->val;
		sum += tmp;

		ListNode* nextnode = new ListNode(sum % 10);
		nextnode->next = NULL;

		newlist->next = nextnode;
		newlist = nextnode;

		sum /= 10;

		a = a->next;
		b = b->next;
	}
	while (a)
	{
		newlist->next = a;
	}
	while (b)
	{
		newlist->next = b;
	}
	if (sum != 0)
	{
		while (newlist->next)
		{
			newlist = newlist->next;
		}
		ListNode* nextnode = new ListNode(sum);
		newlist->next = nextnode;
		nextnode->next = NULL;
	}
	return ret->next;
}