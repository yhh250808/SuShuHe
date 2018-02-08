#include<iostream>
using namespace std;
const int num = 9592;
const int N = 100000 + 10;
bool prime[N +489];
int hs[num + 10];
void getPrimeTable()
{
	for (int i = 3; i <= 333; i += 2)
	{
		if (prime[i] == 0)
		for (int j = i*i; j < N; j += 2 * i)
			prime[j] = 1;
	}
	int total = 1;
	hs[0] = 2;
	for (int i = 3; i < N; ++i)
	{
		if (i % 2 != 0 && prime[i] == 0)
		{

			hs[total++] = i;
		}
	}
}

int main()
{
	getPrimeTable();
	int n, count;
		count = 0;
		cin >> n;
		for (int i = 0; i < num; i++){
			if (n < hs[i])break;
			int sub = n - hs[i];
			for (int j = i + 1; j < num; j++){
				if (sub < hs[j])break;
				if (sub == hs[j])count++; 
			}
		}
		cout << count ;
	return 0;
}
