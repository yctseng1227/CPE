/*=======================================
UVa10082 - WERTYU
=========================================
Completion Date: 105/04/26
=======================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
string sKeyboardButton = "`1234567890-=QWERTYUIOP[]ASDFGHJKL;'ZXCVBNM,./";
string sInput;
int i,j;

while (getline (cin, sInput) )
	{
	for (i=0; sInput[i]!='\0'; i++)
		if (sInput[i] == ' ')
			cout << " ";
		else
			cout << sKeyboardButton[ sKeyboardButton.find(sInput[i])-1 ];
	cout << endl;
	}
return 0;
}
