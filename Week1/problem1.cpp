#include <iostream>
using namespace std;

int main() {
	
	std::ios::sync_with_stdio(false);
	int T, p, n; // p <= 10000, 2byte

	cin >> T;

	for (int i = 0; i < T; i++) 
	{
		cin >> p >> n;
		int change = 10000 - p;
		int *coin = new int[n];
		int eachCoin;
		for (int i = 0; i < n; i++) 
		{
			cin >> eachCoin;
			coin[i] = eachCoin;
		}

		//cout << "change : " << change << ", coin[0] : " << coin[0] << endl;
		//cout << static_cast<float>(change / coin[0]) << " " << ((static_cast<float>(change)) / coin[0]) << endl;

		if (static_cast<float>(change / coin[0]) == ((static_cast<float>(change)) / coin[0])) 
		{
			int count = 0;
			int maxCoinIndex = n - 1;
			while (true) 
			{
				count += change / coin[maxCoinIndex];
				change = change % coin[maxCoinIndex];

				//cout << count << " " << change << endl;

				if (change == 0) break;
				else 
				{
					maxCoinIndex -= 1;
					while (true) 
					{
						if (change >= coin[maxCoinIndex]) break;
						else maxCoinIndex -= 1;
					}
				}
				
			}

			printf("%d\n", count);
			delete[] coin;
		}
		else {

			printf("%d\n", 0);
			delete[] coin;
			continue;
		}
	}

	cin.get();
	cin.ignore();

	printf("\n");

	//system("pause");
	return 0;
}