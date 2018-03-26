#include <iostream>
using namespace std;

int main()
{
	std::ios::sync_with_stdio(false);

	int T, N, M;
	int price[101][101];
	int eachPrice;

	cin >> T >> N >> M;

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			cin >> eachPrice;
			price[N][M] = eachPrice;
		}
	}



	system("pause");
	return 0;
}