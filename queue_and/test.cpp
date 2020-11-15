#include <iostream>
#include <time.h>
#include "store.h"
using namespace std;

int main(int argc, char const *argv[])
{
	/**
	store tests;
	cout << "1" << endl;
	queue q;
	elemtype cus;
	int op = 1, idx = 0;
	srand(time(NULL));
	while (op) {
		cin >> op;
		init_customer(cus,idx);
		if (op == 1) {
			q.push_back(cus);
		}
		else if (op == 2) {
			q.push_front(cus);
		}
		else if (op == 3) {
			q.pop();
		}
		else if (op == 4) {
			q.top().id = 99;
		}
		cout << q.empty() << ":" << "length = " << q.size() << endl;
		q.traverse();
		++idx;
	}
	q.traverse();
	/**/
	return 0;
}