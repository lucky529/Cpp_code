//����򵥵�ʵ����һ��֧�ֲ�ѯ��Сд�ַ�����ַ������ֵ��������ǵ�ÿ���ڵ���һ��is_str������Ǵ˽ڵ��Ƿ���ĳ��
//�ַ������յ㣬��ÿ���ڵ��е�next��������һ��hash���飬ÿ���ڵ��ÿ����������ӳ��26����ĸ�е����е�һ����ĸ

#include<iostream>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;

const int MAXN = 26;
class Trie {
public:
	bool is_str; // ��ʶ��ǰ����Ƿ�Ϊһ���������ַ���
	Trie *next[MAXN]; // ��һ������ָ������
	Trie() {
		is_str = NULL;
		memset(next, 0, sizeof(next));
	}

	/** Inserts a word into the trie. */
	void insert(string word) {
		Trie *cur = this; // cur��ʼ��Ϊ�����ָ��
		for (char w : word){ // ����word�е�ÿһ���ַ�
			if (cur->next[w - 'a'] == NULL){ // ��һ����㲻���ڣ�����һ�����
				Trie *new_node = new Trie();
				cur->next[w - 'a'] = new_node;
			}
			cur = cur->next[w - 'a'];
		}
		cur->is_str = true; // ��ǰ����Ѿ���һ���������ַ�����
	}

	/** Returns if the word is in the trie. */
	bool search(string word) {
		Trie *cur = this;
		for (char w : word){
			if (cur != NULL)
				cur = cur->next[w - 'a']; // ����curָ���ָ��ʹ��ָ����һ�����
		}
		return (cur != NULL&&cur->is_str); // curָ�벻Ϊ����curָ��ָ��Ľ��Ϊһ���������ַ�������ɹ��ҵ��ַ���
	}

	/** Returns if there is any word in the trie that starts with the given prefix. */
	bool startsWith(string prefix) {
		Trie *cur = this;
		for (char w : prefix){
			if (cur != NULL)
				cur = cur->next[w - 'a'];
		}
		return (cur != NULL); // ���search(),����ֻ���ж�curָ���Ƿ�Ϊ�վ�����
	}
};

int main() {
	Trie* trie = new Trie();
	trie->insert("apple");
	cout << trie->search("apple");   // ���� true
	cout << trie->search("app");     // ���� false
	cout << trie->startsWith("app");
	trie->insert("app");
	cout << trie->search("app");     // ���� true
	return 0;
}