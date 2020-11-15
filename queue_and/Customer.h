#include <iostream>
using namespace std;
/**
	Durtime = 15 + R % 50
	Intertime = 2 + R % 10
	Select = 1 + R % 3
	money = durtime * (4 - select) * 0.4;
*/
struct Customer
{
	int durtime, remaintime;
	int intertime;
	int select;
	int id;
};

typedef Customer elemtype;
void init_customer(elemtype &c, int x){
	int R = rand();
	c.durtime = 15 + R % 50;
	c.intertime = 2 + R % 10;
	c.select = 1 + R % 3;
	c.id = x;
	c.remaintime = c.durtime;
}