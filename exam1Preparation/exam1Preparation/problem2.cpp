#include <iostream>
using namespace std;

#define INITIAL 999999

int main()
{
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int p, n;

		cin >> p >> n;

		int coin[500];
		int change[10000];

		for (int j = 0; j < 10000; j++)
			change[j] = INITIAL;

		int charge = 10000 - p;

		for (int j = 0; j < n; j++)
		{
			cin >> coin[j];
			change[coin[j]] = 1;
		}

		if (charge < coin[0])
		{
			cout << "0" << endl;
			continue;
		}

		for (int j = coin[0] + 1; j <= charge; j++)
		{
			for (int k = 0; k < n; k++)
			{
				int curCoin = coin[k];
				if (j > curCoin)
				{
					if (change[j - curCoin] != INITIAL &&
						change[j] > change[j - curCoin] + 1)
					{
						change[j] = change[j - curCoin] + 1;
					}
				}
			}
		}

		if (change[charge] == INITIAL)
		{
			cout << "0" << endl;
		}
		else
		{
			cout << change[charge] << endl;
		}

	}

	system("pause");
}