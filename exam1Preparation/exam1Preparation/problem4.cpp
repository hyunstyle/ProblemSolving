#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T, N, M;

	cin >> T;

	int price[101][101];
	int each;

	for (int i = 0; i < T; i++)
	{

		cin >> N >> M;

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < M; k++)
			{
				cin >> each;
				price[k][j] = each;
			}
		}

		//int totalPrice = 0;

		int copyArray[101];
		for (int j = 1; j < M; j++)
		{
			//int* prev = price[j-1];
			copy(price[j - 1], price[j - 1] + N, copyArray);
			sort(copyArray, copyArray + N);

			for (int k = 0; k < N; k++)
			{
				if (price[j-1][k] == copyArray[0])
					price[j][k] += copyArray[1];
				else
					price[j][k] += copyArray[0];
			}
		}

		sort(price[M - 1], price[M - 1] + N);

		cout << price[M-1][0] << endl;
	}

	//system("pause");
}