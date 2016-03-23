/*==========================================
UVa11349 - Symmetric Matrix
============================================
Completion Date: 105/02/11	by Geneyozakura
==========================================*/
#include <iostream>
#include <string>
using namespace std;
int main()
{
int iCase;					//儲存測資個數
int iMatrix[100][100];		//儲存陣列
char cN;					//儲存題意要求的"N"字母
char cEqual;				//儲存題意要求的"="符號
int iDimension;				//儲存數入陣列的長寬大小
int i;						//迴圈變數
int j;						//迴圈變數
int iNumber;				//儲存測資編號
bool bSymmetric;			//判斷是否為Symmetric

//輸入測資個數
cin >> iCase;
for (iNumber=1; iNumber<=iCase; iNumber++)
	{
	//初始化
	bSymmetric = true;

	//依題意輸入
	cin >> cN >> cEqual >> iDimension;

	//輸入陣列 並判斷是否為正整數
	for (i=0; i<iDimension; i++)
		for (j=0; j<iDimension; j++)
			{
			cin >> iMatrix[i][j];
			if (iMatrix[i][j] < 0)
				bSymmetric = false;
			}

	//判斷陣列的四個角位置的值是否相等
	if (iMatrix[0][0] != iMatrix[iDimension-1][iDimension-1])
		bSymmetric = false;

	if (iMatrix[0][iDimension-1] != iMatrix[iDimension-1][0])
		bSymmetric = false;

	//判斷剩餘數字在相對應位置的值是否相等
	for (i=0; i<iDimension; i++)
		for (j=1; j<iDimension-1; j++)
			if (iMatrix[i][j] != iMatrix[iDimension-1-i][j])
				bSymmetric = false;

	for (i=1; i<iDimension-1; i++)
		for (j=0; j<iDimension; j++)
			if (iMatrix[i][j] != iMatrix[i][iDimension-1-j])
				bSymmetric = false;

	//輸出
	if (bSymmetric)
		cout << "Test #" << iNumber << ": Symmetric." << endl;
	else
		cout << "Test #" << iNumber << ": Non-symmetric." << endl;
	}

return 0;
}