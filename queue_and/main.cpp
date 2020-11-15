#include "store.h"
#include <time.h>
using namespace std;
#define T 480
#define debug(a) cout << #a << " = " << a << endl
#define DEBUG
#ifdef DEBUG
	double debugsum = 0;
#endif

int main(int argc, char const *argv[])
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout << "test" << endl;
	store barber;
	Customer customer;
	int nextoccur = 0, idx = 0;
	srand(time(0));
	for (int t = 0; t <= T; ++t) {
		if (nextoccur == t) {
			init_customer(customer, idx);
			nextoccur += customer.intertime;
			if (!barber.available(customer, T)) {
				continue;
			}
			++idx;
			barber.gotostore(customer);	
			debugsum += customer.durtime * (4 - customer.select) * 0.4;
		}
		barber.cut();
		barber.lapses();
	}
	#ifdef DEBUG
		debug(debugsum);
	#endif
	barber.business();
	return 0;
}