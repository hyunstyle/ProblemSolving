#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	int coin[15];
	for (int i = 0; i < T; i++)
	{
		int p, n;

		cin >> p >> n;

		int change = 10000 - p;

		for (int j = 0; j < n; j++)
		{
			cin >> coin[j];
		}

		int counter = 0;

		if ((change % coin[0]) != 0)
		{
			cout << "0" << endl;
			continue;
		}
		else
		{
			int coinIndex = n - 1;
			while (true)
			{
				if (change >= coin[coinIndex])
				{
					counter += change / coin[coinIndex];
					change = change % coin[coinIndex];
					coinIndex--;
				}
				else
				{
					if (change == 0)
					{
						break;
					}
					else
					{
						coinIndex--;
					}
				}
			}
		}

		cout << counter << endl;
	}
}