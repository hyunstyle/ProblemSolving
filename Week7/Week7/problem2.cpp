#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	short T;

	cin >> T;

	while (T--)
	{
		short K, C; // 라운드 수 K, 스코어 개수 C

		cin >> K >> C;

		int away, home = 0;

		for (short i = 0; i < C; i++)
		{
			cin >> away >> home;

			if (away > home)
			{
				if (K < away)
					cout << "0" << endl;//" , " << i << " 번째, " << away << " " << home << endl;
				else
				{
					int gap = away - home - 1;

					int maxRemainRounds = K - away + 1;

					if (gap > maxRemainRounds)
						cout << "0" << endl;//" , " << i << " 번째, " << away << " " << home << ", gap:" << gap << ", rem:" << maxRemainRounds << endl;
					else
						cout << "1" << endl;//" , " << i << " 번째, " << away << " " << home << ", gap:" << gap << ", rem:" << maxRemainRounds << endl;
				}
				
			}
			else if (away < home)
			{
				if (K < home)
					cout << "0" << endl;//" , " << i << " 번째, " << away << " " << home << endl;
				else
				{
					int gap = home - away - 1;

					int maxRemainRounds = K - home;

					if (gap > maxRemainRounds)
						cout << "0" << endl;//" , " << i << " 번째, " << away << " " << home << ", gap:" << gap << ", rem:" << maxRemainRounds << endl;
					else
						cout << "1" << endl;//" , " << i << " 번째, " << away << " " << home << ", gap:" << gap << ", rem:" << maxRemainRounds << endl;
				}
			}
			else // 같은경우
			{
				if (K < away)
					cout << "0" << endl;//" , " << i << " 번째, " << away << " " << home << endl;
				else
					cout << "1" << endl;//" , " << i << " 번째, " << away << " " << home << endl;
			}


			
		}
	}

	//system("pause");
}