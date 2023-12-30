#include<iostream>

using namespace std;

int main()
{
	int n;
	int a[101],b[101];


		cin >> n;


	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}

	for (int i = 0; i < n; i++)
	{
		cin >> b[i];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i+1; j < n; j++)
		{
			if (a[i] > a[j])
			{
				int temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (b[i] < b[j])
			{
				int temp = b[i];
				b[i] = b[j];
				b[j] = temp;
			}
		}
	}
	int sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += a[i] * b[i];
	}

	cout << sum << endl;
	return 0;
	
}
