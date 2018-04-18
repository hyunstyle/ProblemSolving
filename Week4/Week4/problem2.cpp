#include <iostream>
#include <string.h>
using namespace std;


short aWays[10000];
short bWays[10000];

int aPieces[500];
int bPieces[500];

int main()
{
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		memset(aWays, 0, 10000 * sizeof(short));
		memset(bWays, 0, 10000 * sizeof(short));

		unsigned short S;

		cin >> S;

		short N, M;

		cin >> N >> M;

		for (int j = 0; j < N; j++)
		{
			cin >> aPieces[j];
			aWays[aPieces[j]] += 1; // ���� ������ 1��¥�� aWays 
		}

		for (int j = 0; j < M; j++)
		{
			cin >> bPieces[j];
			bWays[bPieces[j]] += 1; // ���� ������ 1��¥�� bWays
		}

		for (int j = 2; j <= S; j++) // aWays�� bWays ä��� ( ���� ������ 2��¥������ )
		{
			for (int k = 0; k < N; k++) // a
			{
				//cout << "aPieces[" << k << "] = " << aPieces[k] << endl;
				int sum = aPieces[k];
				int counter = N-1;
				int index = k + 1;
				while(counter--)
				{
					sum += aPieces[index % N];
					//cout << "j: " << j << " sum: " << sum << endl;
					if (sum < j) // ���� �� ���� �ε����� �̾�ٿ��� j�� ���� �� ����
					{
						index++;
						continue;
					}
					else if (sum == j) // �� ��찡 �� ��� ���� �������� ������ j�� �����. �̶��� ���� +1 ��Ű�� ���� �����ͷ�
					{
						aWays[j] += 1;
						break;
					}
					else // �� Ŀ���� ���� ���������� ����� ���°�
						break;

				}

			}

			//cout << "--------------------------------\n";

			for (int k = 0; k < M; k++) // b
			{
				int sum = bPieces[k];
				int counter = M - 1;
				int index = k + 1;
				while (counter--)
				{
					sum += bPieces[index % M];
					//cout << "j: " << j << " sum: " << sum << endl;
					if (sum < j) // ���� �� ���� �ε����� �̾�ٿ��� j�� ���� �� ����
					{
						index++;
						continue;
					}
					else if (sum == j) // �� ��찡 �� ��� ���� �������� ������ j�� �����. �̶��� ���� +1 ��Ű�� ���� �����ͷ�
					{
						bWays[j] += 1;
						break;
					}
					else // �� Ŀ���� ���� ��������(j)�� ����� ���°�
						break;

				}

			}
		}

		//cout << "aWays[S]: " << aWays[S] << ", bWays[S]" << bWays[S] << endl;


		int aIndex = S - 1;
		int bIndex = 1;

		int indexCounter = S - 1;

		int result = 0;

		while (indexCounter--)
		{
			result += (aWays[aIndex] * bWays[bIndex]);
			//cout << "result: " << result << "at aIndex:" << aIndex << ", bIndex:" << bIndex << endl;
			aIndex--;
			bIndex++;
		}

		result = result + aWays[S] + bWays[S]; // S=7 �� ��� ������ �� ���� ������ A[7] + A[6]*B[1] + A[5]*B[2] + ... + A[1]B[6] + B[7]

		cout << result << endl;

	}

	//system("pause");
}