/*==========================================
UVa10101 - Bangla Numbers
============================================
Completion Date: 105/02/05   by Geneyozakura
==========================================*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
long long int lliInput;		//儲存輸入的數字
long long int lliTemp;		//儲存暫存的輸入數字
int iDigit;					//儲存輸入數字的位數
int iNumber;				//儲存測資編號
bool bZero;					//判斷是否需要輸出尾數0

//測資編號初始化
iNumber = 0;
while (cin >> lliInput)
    {
    //初始化
    iDigit = 0;
    bZero = true;

    //計算位數
    lliTemp = lliInput;
    while (lliTemp)
    	{
    	lliTemp /= 10;
    	iDigit++;
    	}

    //輸出測資編號
	lliTemp = lliInput;
    cout << setw(4) << ++iNumber << ".";
    
    //若位數達15位數 (測資輸入之最高位數)
    //則直接輸出該位數的值
    if (iDigit == 15)
		{
		cout << " " << lliInput/100000000000000 << " kuti";
		lliInput %= 100000000000000;
		}

	//以中間7個位數為一組 輸出其相對應的單位
	if (iDigit > 7)
		{
		lliTemp = lliInput / 10000000;
		
		if (lliTemp/100000 != 0)
			cout << " " << lliTemp/100000 << " lakh";
		lliTemp %= 100000;
		
		if (lliTemp/1000 != 0)
			cout << " " << lliTemp/1000 << " hajar";
		lliTemp %= 1000;
		
		if (lliTemp/100 != 0)
		cout << " " << lliTemp/100 << " shata";
		lliTemp %= 100;
		
		if (lliTemp != 0)
			cout << " " << lliTemp;

		cout << " kuti";
		lliInput %= 10000000;
		
		//若後面七位數均為0 則輸出到此為止
		if (lliInput%10000000 == 0)
			bZero = false;
		}

	//以後面七個位數為一組 輸出相對應的單位
	if (lliInput/100000 != 0)
		cout << " " << lliInput/100000 << " lakh";
	lliInput %= 100000;
	
	if (lliInput/1000 != 0)
		cout << " " << lliInput/1000 << " hajar";
	lliInput %= 1000;
	
	if (lliInput/100 != 0)
		cout << " " << lliInput/100 << " shata";
	lliInput %= 100;
	
	//在中間七位數有值的前提下
	//若後面七位數的值皆為0 則不輸出此尾數
	if (bZero)
		cout << " " << lliInput;
		
	cout << endl;	
	}
return 0;
}
