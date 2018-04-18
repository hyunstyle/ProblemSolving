#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;

	cin >> T; 

	int price[101][101];
	
	/*int dim[3][3];

	dim[0] -- dim[0][0] dim[0][1] dim[0][2]
	dim[1]
	dim[2]

	dim[3] = t

		t[3];*/

	for (int i = 0; i < T; i++)
	{
		int N, M;

		cin >> N >> M;

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> price[k][j];
			}
		}

		int copyArray[101];

		for (int j = 1; j < M; j++)
		{
			copy(price[j-1], price[j-1] + N, copyArray);
			sort(copyArray, copyArray + N);

			for (int k = 0; k < N; k++)
			{
				if (price[j - 1][k] == copyArray[0])
				{
					price[j][k] += copyArray[1];
				}
				else
				{
					price[j][k] += copyArray[0];
				}
			}
		}

		sort(price[M-1], price[M-1] + N);

		cout << price[M-1][0] << endl;
	}

	system("pause");
}