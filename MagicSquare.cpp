#include <iostream>

using namespace std;

bool magic_square (int* matrix, int size)
{
	int sum = 0,
		sum1 = 0,
		sum2 = 0,
		sum3 = 0,
		sum4 = 0,
		flag = 1;

	for (int i = 0; i < size; i++)
	{
		sum += matrix [i]; 
	}

	for(int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			sum1 += matrix [i * size + j];
			sum2 += matrix [j * size + i];
			if(i == j)
			{
				sum3 += matrix [i * size + j];
			}
			if(i + j + 1 == size)
			{
				sum4 += matrix [i * size + j];
		}
		}
		if(sum != sum1)
			{
				flag = 0;
				break;
			}
		sum1 = 0;
		sum2 = 0;
	}
	if(sum != sum3 || sum != sum4)
	{
		flag = 0;
	}

	return flag;
}
void Print (bool isMagic)
{
	if(isMagic == 1)
		cout << "True" << endl;
	else
		cout << "False" << endl;
}
				

int main()
{
	const int MaxSize = 3;
	int matrix[MaxSize][MaxSize] = 
	{
		{4,9,2},
		{3,5,7},
		{8,1,6}
	};
	bool isMagic = magic_square(& matrix[0][0], MaxSize);
	Print(isMagic);
	system ("pause");
	return 0;
	
}