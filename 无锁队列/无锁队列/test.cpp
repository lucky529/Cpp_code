//简单写一下无锁队列的伪代码，重在理解cas机制
EnQueue(x)
{
	q = new node();
	q->next = nullptr;
	q->val = x;

	do{
		p = tail;//获取当前队列尾部
	} while (CAS(p->next, nullptr, q));//如果当前尾部的下一个节点是nullptr则跟新成功
	CAS(tail, p, q);//将队列尾部跟新
}

DeQueue()
{
	do{
		p = head;
		if (p->next == nullptr)
			return EMPTY;
	} while (CAS(head, p, p->next));//判断头部是否为当前的头部，是则更新为p的next节点
	return p->next->val;//返回p->next的节点
}

SafeRead(q)//节点内存引用计数
{
loop:
	p = q->next;
	if (p == NULL){
		return p;
	}
	Fetch&Add(p->refcnt, 1);

	if (p == q->next){
		return p;
	}
	else{
		Release(p);
	}
	goto loop;
}