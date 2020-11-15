#include <stack>
#include <vector>
#include "my_queue.h"
using namespace std;
class store
{
private:

public:
	queue q[3];
	int totaltime;
	int S[3] = {2, 2, 3};
	int eachtime[3][3];
	double totalmoney;
	double money[3];
	store(){
		totaltime = 0;
		totalmoney = 0;
		for (int i = 0; i < 3; ++i) {
			for (int j = 0; j < S[i]; ++j) {
				eachtime[i][j] = 0;
			}
		}
		for (int i = 0; i < 3; ++i) {
			money[i] = 0;
		}
	}

	void inline lapses(){
		++totaltime;
	}

	int available(elemtype c, const int T){
		int type = c.select - 1;
		int index = 0;
		for (int i = 0; i < S[type]; ++i) {
			eachtime[type][i] = max(totaltime + c.durtime, eachtime[type][i]);
		}
		for (int i = 0; i < S[type]; ++i) {
			if (eachtime[type][i] < eachtime[type][index]) {		
				index = i;
			}
		}
		if (eachtime[type][index] + c.durtime <= T) {
			eachtime[type][index] += c.durtime;
			return 1;
		}
		return 0;
	}

	void gotostore(elemtype c){
		q[c.select - 1].push_back(c);
		cout << "-------------------------------------" << endl;
		cout << "At: " << totaltime << " IN: " << c.id << endl;
		cout << "durtime " << c.durtime << " select " << c.select << endl;
		cout << "-------------------------------------" << endl;
	}

	void gooutstore(elemtype c){
		double m = c.durtime * (4 - c.select) * 0.4;
		money[c.select - 1] += m;
		totalmoney += m;
	}

	void cut(){
		int sit[3] = {2, 2, 3};
		for (int i = 0; i < 3; ++i) {
			stack<elemtype> s;
			while (!q[i].empty() && sit[i]--) {
				elemtype cus = q[i].pop();
				s.push(cus);
			}
			while (!s.empty()) {
				elemtype cus = s.top();
				s.pop();
				if (check(cus)) {
					cout << "*************************************" << endl;
					cout << " At: " << totaltime << " OUT: " << cus.id << endl;
					cout << "*************************************" << endl;
					continue;
				}
				--cus.remaintime;
				q[i].push_front(cus);
			}
		}
	}

	int check(elemtype c){
		if (0 >= c.remaintime) {
			gooutstore(c);
			return 1;
		}
		return 0;
	}

	void business(){
		cout << "Turnover:" << totalmoney << endl;
		for (int i = 0; i < 3; ++i) {
			cout << i + 1 << ": " << money[i] << endl;
		}
	}

	~store(){

	}
	
};