#include <iostream>
using namespace std;

bool pixel[256][256];

//bool pixel[65537];

int whitePixelCounter = 0, blackPixelCounter = 0;

void divider(int startWidth, int startHeight, int N);

int main()
{
	std::ios::sync_with_stdio(false);

	int T, N;
	cin >> T;

	for(int i = 0; i < T; i++)
	{
		cin >> N;

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
				cin >> pixel[j][k];
		}

		divider(0, 0, N);

		printf("%d %d\n", whitePixelCounter, blackPixelCounter);

		whitePixelCounter = 0;
		blackPixelCounter = 0;
	}

	//system("pause");
	return 0;
}

void divider(int startWidth, int startHeight, int N)
{
	if (N == 2)
	{
		bool leftTop, rightTop, leftBottom, rightBottom;

		leftTop = pixel[startWidth][startHeight];
		rightTop = pixel[startWidth][startHeight + 1];
		leftBottom = pixel[startWidth + 1][startHeight];
		rightBottom = pixel[startWidth + 1][startHeight + 1];

		if (leftTop && rightTop && leftBottom && rightBottom)
		{
			blackPixelCounter++;
		}
		else if (!leftTop && !rightTop && !leftBottom && !rightBottom)
		{
			whitePixelCounter++;
		}
		else
		{
			if (leftTop)
				blackPixelCounter++;
			else
				whitePixelCounter++;

			if (rightTop)
				blackPixelCounter++;
			else
				whitePixelCounter++;

			if (leftBottom)
				blackPixelCounter++;
			else
				whitePixelCounter++;

			if (rightBottom)
				blackPixelCounter++;
			else
				whitePixelCounter++;
		}

		return;
	}


	bool firstValue = pixel[startWidth][startHeight];
	for (int i = startWidth; i <startWidth + N; i++)
	{
		for (int j = startHeight; j < startHeight + N; j++)
		{
			if (firstValue != pixel[i][j])
			{
				divider(startWidth, startHeight, N / 2);
				divider(startWidth + N / 2, startHeight, N / 2);
				divider(startWidth, startHeight + N / 2, N / 2);
				divider(startWidth + N / 2, startHeight + N / 2, N / 2);

				return;
			}
		}
	}

	if (firstValue)
		blackPixelCounter++;
	else
		whitePixelCounter++;

	return;

}