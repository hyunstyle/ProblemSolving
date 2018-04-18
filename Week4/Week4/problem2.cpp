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
			aWays[aPieces[j]] += 1; // 원소 사이즈 1개짜리 aWays 
		}

		for (int j = 0; j < M; j++)
		{
			cin >> bPieces[j];
			bWays[bPieces[j]] += 1; // 원소 사이즈 1개짜리 bWays
		}

		for (int j = 2; j <= S; j++) // aWays와 bWays 채우기 ( 원소 사이즈 2개짜리부터 )
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
					if (sum < j) // 아직 그 다음 인덱스를 이어붙여서 j를 만들 수 있음
					{
						index++;
						continue;
					}
					else if (sum == j) // 이 경우가 될 경우 연속 조각들의 합으로 j를 만든것. 이때의 값을 +1 시키고 다음 포인터로
					{
						aWays[j] += 1;
						break;
					}
					else // 더 커지면 현재 조각개수는 만들수 없는것
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
					if (sum < j) // 아직 그 다음 인덱스를 이어붙여서 j를 만들 수 있음
					{
						index++;
						continue;
					}
					else if (sum == j) // 이 경우가 될 경우 연속 조각들의 합으로 j를 만든것. 이때의 값을 +1 시키고 다음 포인터로
					{
						bWays[j] += 1;
						break;
					}
					else // 더 커지면 현재 조각개수(j)는 만들수 없는것
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

		result = result + aWays[S] + bWays[S]; // S=7 일 경우 가능한 총 조각 조합은 A[7] + A[6]*B[1] + A[5]*B[2] + ... + A[1]B[6] + B[7]

		cout << result << endl;

	}

	//system("pause");
}