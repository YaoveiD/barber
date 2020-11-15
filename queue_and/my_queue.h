#include <stdlib.h>
#include "Customer.h"
using namespace std;

typedef struct node
{
	elemtype data;
	node* next;
}node;
class queue
{
private:
	node *front, *rear;
	int len;
public:
	queue(){
		front = rear = new node;
		front->next = nullptr;
		len = 0;
	}

	void push_back(elemtype x){
		node* p = new node;
		p->data = x;
		p->next = nullptr;
		rear->next = p;
		rear = p;
		++len;
	}

	void push_front(elemtype x){
		node* p = new node;
		p->data = x;
		p->next = front->next;
		front->next = p;
		++len;
		if (len == 1) {
			rear = p;
			//error'2 solution
		}
	}

	elemtype& top(){
		//return ref
		return front->next->data;
	}

	elemtype pop(){
		node* p = front->next;
		elemtype r = p->data;
		front->next = p->next;
		delete p;
		--len;
		if (len == 0) {
			rear = front;
			//error1's solution
		}
		return r;
	}

	int size(){
		return len;
	}

	bool empty(){
		return front->next == nullptr;
	}

	void traverse(){
		node* p = front->next;
		cout << "queue:  ";
		while (p) {
			cout << p->data.id << " " << p->data.remaintime << " ; ";
			p = p->next;
		}
		cout << endl;
	}

	~queue(){
		while (front) {
			rear = front->next;
			delete front;
			front = rear;
		}
	}
};
