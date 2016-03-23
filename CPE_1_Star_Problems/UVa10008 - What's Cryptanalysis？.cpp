/*==========================================
UVa10008 - What's Cryptanalysis?
============================================
Completion Date: 105/01/31	by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
int iCase;				//儲存輸入的測資個數
string sInput;			//儲存輸入的測資字串
int iInputlength;		//儲存輸入測資字串的長度
int iLetterCount[26];	//儲存出現字母的個數
int iMax;				//儲存出現最多字母的個數
int i;					//迴圈變數
int j;					//迴圈變數
int k;					//迴圈變數

//初始化
for (i=0; i<26; i++)
	iLetterCount[i] = 0;
iMax = 0;

//輸入測資個數
cin >> iCase;
//輸入測資前必須先吃下換行符號
getline(cin, sInput);

for (i=0; i<iCase; i++)
	{
	//輸入測資字串
	getline(cin, sInput);
	//得出測資字串的長度
	iInputlength = sInput.length();

	//統計各字母出現的次數
	for (j=0; j<iInputlength; j++)
		for (k=65; k<=90; k++)
			if ( sInput[j]==k || sInput[j]==(k+32) )
				iLetterCount[k-65]++;
	}

//計算字母出現最多的次數
for (i=0; i<26; i++)
	for (j=0; j<26; j++)
		if (iLetterCount[i] > iMax)
			iMax = iLetterCount[i];

//輸出
while (1)
	{
	//從出現次數最多的字母開始輸出
	for (i=0; i<26; i++)
		if (iLetterCount[i] == iMax)
			cout << (char)(i+65) << " " << iLetterCount[i] << endl;
	iMax--;
	if (iMax == 0)
		break;
	}

return 0;
}