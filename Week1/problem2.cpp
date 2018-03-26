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

		int *count = new int[CLIENT_PAYMENT]; // DP. �� �迭�� �ε����� �ش� �ε��� �Ž������� �ּ� ���� ����
		count[0] = 0;
		for (int j = 1; j < CLIENT_PAYMENT; j++)
			count[j] = CLIENT_PAYMENT;        // �Ž������� ���� ������ 10000���� Ŭ �� ���⿡ 10000���� �ʱ�ȭ ( 1 <= change <= 9999 ) & ( coin size >= 1(INTEGER) )


		for (int j = 0; j <= change; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (j >= coin[k])
				{
					if (count[j - coin[k]] != CLIENT_PAYMENT && count[j] > count[j - coin[k]] + 1) // �ʱⰪ�� �ƴϰ�, ���� ������ ���� �� ���� count�� �� �ּҰ� ����, �ּҰ����� + 1 
						count[j] = count[j - coin[k]] + 1;
				}
			}
		}
		
		printf("%d\n", (count[change] != CLIENT_PAYMENT) ? count[change] : 0); // �ʱⰪ�� �����Ǿ� ������ �Ž��� �ִ� ���� �Ұ����ϴٴ� ��. 3�� ������ ���
		
		delete[] coin;
		delete[] count; // �޸� ����

	}

	cin.get();
	cin.ignore();

	printf("\n");

	return 0;
}