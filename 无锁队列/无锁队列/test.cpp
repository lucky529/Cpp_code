//��дһ���������е�α���룬�������cas����
EnQueue(x)
{
	q = new node();
	q->next = nullptr;
	q->val = x;

	do{
		p = tail;//��ȡ��ǰ����β��
	} while (CAS(p->next, nullptr, q));//�����ǰβ������һ���ڵ���nullptr����³ɹ�
	CAS(tail, p, q);//������β������
}

DeQueue()
{
	do{
		p = head;
		if (p->next == nullptr)
			return EMPTY;
	} while (CAS(head, p, p->next));//�ж�ͷ���Ƿ�Ϊ��ǰ��ͷ�����������Ϊp��next�ڵ�
	return p->next->val;//����p->next�Ľڵ�
}

SafeRead(q)//�ڵ��ڴ����ü���
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