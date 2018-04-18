#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	int coin[500];
	int count[10001];

	for (int i = 0; i < T; i++)
	{
		
		int p, n;

		cin >> p >> n;

		int change = 10000 - p;

		for (int j = 0; j < 10001; j++)
		{
			count[j] = 300000;
		}

		for (int j = 0; j < n; j++)
		{
			cin >> coin[j];
			count[coin[j]] = 1;
		}


		for (int j = coin[0] + 1; j <= change; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (j > coin[k])
				{
					if (count[j - coin[k]] != 300000 && count[j] > count[j - coin[k]] + 1)
					{
						count[j] = count[j - coin[k]] + 1;
					}
				}
			}
		}

		if (count[change] == 300000)
			cout << "0" << endl;
		else
			cout << count[change] << endl;

	}
}