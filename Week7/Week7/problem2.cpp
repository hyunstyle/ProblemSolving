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
		short K, C; // ���� �� K, ���ھ� ���� C

		cin >> K >> C;

		int away, home = 0;

		for (short i = 0; i < C; i++)
		{
			cin >> away >> home;

			if (away > home)
			{
				if (K < away)
					cout << "0" << endl;//" , " << i << " ��°, " << away << " " << home << endl;
				else
				{
					int gap = away - home - 1;

					int maxRemainRounds = K - away + 1;

					if (gap > maxRemainRounds)
						cout << "0" << endl;//" , " << i << " ��°, " << away << " " << home << ", gap:" << gap << ", rem:" << maxRemainRounds << endl;
					else
						cout << "1" << endl;//" , " << i << " ��°, " << away << " " << home << ", gap:" << gap << ", rem:" << maxRemainRounds << endl;
				}
				
			}
			else if (away < home)
			{
				if (K < home)
					cout << "0" << endl;//" , " << i << " ��°, " << away << " " << home << endl;
				else
				{
					int gap = home - away - 1;

					int maxRemainRounds = K - home;

					if (gap > maxRemainRounds)
						cout << "0" << endl;//" , " << i << " ��°, " << away << " " << home << ", gap:" << gap << ", rem:" << maxRemainRounds << endl;
					else
						cout << "1" << endl;//" , " << i << " ��°, " << away << " " << home << ", gap:" << gap << ", rem:" << maxRemainRounds << endl;
				}
			}
			else // �������
			{
				if (K < away)
					cout << "0" << endl;//" , " << i << " ��°, " << away << " " << home << endl;
				else
					cout << "1" << endl;//" , " << i << " ��°, " << away << " " << home << endl;
			}


			
		}
	}

	//system("pause");
}