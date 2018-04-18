#include <iostream>
#include <cstdio>
#include <cstring>
//#include <string>
using namespace std;

#define ARRAY_LENGTH (30000000/8)

char bitmaskingArray[ARRAY_LENGTH];

int main()
{
	ios::sync_with_stdio(false);
		
	int T;

	scanf("%d", &T);

	for (int i = 0; i < T; i++)
	{
		memset(bitmaskingArray, 0, ARRAY_LENGTH * sizeof(char));

		int N;
		scanf("%d", &N);

		int A, B;

		for (int k = 0; k < N; k++)
		{
			scanf("%d", &A);

			bitmaskingArray[A / 8] |= (1 << (A % 8)); // 3000만개의 0000000000000.. 에서 8개씩 몫으로 끊어서 나머지를 이용해 1 마스킹
		}

		bool isSame = true;
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &B);

			if (!(bitmaskingArray[B / 8] & (1 << (B % 8))))
			{
				if (isSame)
					isSame = false;

				printf("%d ", B);
			}
		}

		if (isSame)
			printf("0\n");
		else
			printf("\n");
	}

	return 0;
	//system("pause");
}