/*=======================================
UVa10696 -  f91 
=========================================
Completion Date: 105/05/02
=======================================*/
#include <iostream>
using namespace std;

int f91 (int N)
{
if (N<=100)
	return f91( f91(N+11) );
else
	return N-10;
}

int main()
{
int iInputNumber;
int iResult;

while (cin >> iInputNumber)
	{
	if (iInputNumber == 0)
		return 0;
	iResult = f91(iInputNumber);
	cout << "f91(" << iInputNumber << ") = " << iResult << endl;
	}

return 0;
}