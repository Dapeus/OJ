#include<iostream>
using namespace std;
 
typedef struct Queue {
	int data;
	Queue* next;
}Queue, *LinkQueue;
 
void initQueue(LinkQueue& q) {
	q = new Queue;
	q->next = q;
}
 
void push(LinkQueue& q, int e) {
	LinkQueue p = new Queue;
	p->data = e;
	p->next = q->next;
	q->next = p;
	q = p;
}
 
int pop(LinkQueue& q) {
	LinkQueue temp = q->next->next;
	if (temp == q) {
		initQueue(q);
		return temp->data;
	}
	q->next->next = temp->next;
	return temp->data;
}
 
int Isempty(LinkQueue& q) {
	if (q->next == q) {
		return 0;
	}
	else {
		return 1;
	}
}
 
int main()
{
	LinkQueue queue;
	int n, m;
	int x;
	while (1) {
		initQueue(queue);
		cin >> n >> m;
		if (m == 0 && n == 0) {
			break;
		}
		for (int i = 0; i < n; i++) {
			cin >> x;
			push(queue, x);
		}
		cout << pop(queue);
		for (int i = 1; i < m; i++) {
			cout << " " << pop(queue);
		}
		cout << " " << Isempty(queue) << endl;
	}
	return 0;
}