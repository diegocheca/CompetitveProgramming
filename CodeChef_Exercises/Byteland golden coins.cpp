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

int total=0, numero,a,b,c;
//double a,b,c;
int recursion(int cuenta)
{
	if(cuenta==2)
		return 2;
	else 
		if(cuenta==1)
			return 1;
		else
			if(cuenta==0)
				return 0;
			else
				{
					a= cuenta/2;
					b= cuenta/3;
					c= cuenta/4;
					if(cuenta>= a+b+c)
					{
						c=cuenta;
						return c;
					}
						
					else	return total+= recursion(a)+recursion(b)+recursion(c);
				}
				
	
}

//1 + ((x - 1) / y);


int main(int argc, char *argv[]) {
	cin>>numero;
	recursion(numero);
	cout<<total;
	cin>>a;
	return 0;
}

