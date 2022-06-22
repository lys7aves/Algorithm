#include <iostream>

using namespace std;

int main()
{
	freopen("output.txt","w",stdout);
	
	cout << "?111";
	for(int i=4; i<50000-4; i++) cout << "?";
	cout << "?000";
	
	return 0;
}
