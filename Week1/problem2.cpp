#include <iostream>
using namespace std;

#define CLIENT_PAYMENT 10000

int main()
{
	std::ios::sync_with_stdio(false);
	int T, p, n;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> p >> n;
		int change = CLIENT_PAYMENT - p;
		int *coin = new int[n];
		int eachCoin;
		for (int j = 0; j < n; j++)
		{
			cin >> eachCoin;
			coin[j] = eachCoin;
		}

		int *count = new int[CLIENT_PAYMENT]; // DP. 각 배열의 인덱스는 해당 인덱스 거스름돈의 최소 동전 개수
		count[0] = 0;
		for (int j = 1; j < CLIENT_PAYMENT; j++)
			count[j] = CLIENT_PAYMENT;        // 거스름돈의 동전 개수는 10000보다 클 수 없기에 10000으로 초기화 ( 1 <= change <= 9999 ) & ( coin size >= 1(INTEGER) )


		for (int j = 0; j <= change; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (j >= coin[k])
				{
					if (count[j - coin[k]] != CLIENT_PAYMENT && count[j] > count[j - coin[k]] + 1) // 초기값이 아니고, 현재 동전의 값을 뺀 것의 count들 중 최소값 도출, 최소값에서 + 1 
						count[j] = count[j - coin[k]] + 1;
				}
			}
		}
		
		printf("%d\n", (count[change] != CLIENT_PAYMENT) ? count[change] : 0); // 초기값이 유지되어 있으면 거슬러 주는 것이 불가능하다는 뜻. 3항 연산자 사용
		
		delete[] coin;
		delete[] count; // 메모리 해제

	}

	cin.get();
	cin.ignore();

	printf("\n");

	return 0;
}