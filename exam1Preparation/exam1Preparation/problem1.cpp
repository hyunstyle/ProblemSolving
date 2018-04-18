#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int p, n;

		cin >> p >> n;

		int coin[15];
		int charge = 10000 - p;

		if (charge == 0)
		{
			cout << "0" << endl;
			continue;
		}

		for (int j = 0; j < n; j++)
		{
			cin >> coin[j];
		} // coin[n-1] 

		int count = 0;
		int coinCounter = n - 1;

		//cout << "charge:" << charge << endl;

		

		if ((charge % coin[0]) != 0)
			cout << "0" << endl;
		else
		{
			while (true)
			{
				if (coinCounter < 0 || charge == 0)
					break;

				if (charge >= coin[coinCounter])
				{
					count += (charge / coin[coinCounter]);
					charge = (charge % coin[coinCounter]);
					coinCounter--;
				}
				else
				{
					coinCounter--;
				}
				//charge = charge
			}

			cout << count << endl;
		}

	}

	//system("pause");
}