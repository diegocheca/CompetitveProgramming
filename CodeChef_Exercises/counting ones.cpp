#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cstring>
#include <list>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int test,a,b;
int main(int argc, char *argv[]) {
	cin >> test;
	while ( test-- )
	{
		int ans = 0;
		cin >> a >> b;
		for (int i=a; i<=b; i++) ans += __builtin_popcount( i );
		cout << ans << endl;
	}
	return 0;
}

