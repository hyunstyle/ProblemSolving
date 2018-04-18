#include <iostream>
using namespace std;

bool pixel[258][258];

void divider(int width, int height, int N);

int whitePixelCounter = 0;
int blackPixelCounter = 0;

int main()
{
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		int N;

		cin >> N;

		for (int j = 0; j < N; j++)
		{
			for (int k = 0; k < N; k++)
			{
				cin >> pixel[j][k];
			}
		}

		divider(0, 0, N);

		printf("%d %d\n", whitePixelCounter, blackPixelCounter);

		whitePixelCounter = 0;
		blackPixelCounter = 0;
	}
}

void divider(int width, int height, int N)
{
	if (N == 2)
	{
		bool leftTop, rightTop, leftBottom, rightBottom;

		leftTop = pixel[width][height];
		rightTop = pixel[width + 1][height];
		leftBottom = pixel[width][height + 1];
		rightBottom = pixel[width + 1][height + 1];

		if (leftTop && rightTop && leftBottom && rightBottom)
		{
			blackPixelCounter++;
			return;
		}
		else if (!leftTop && !rightTop && !leftBottom && !rightBottom)
		{
			whitePixelCounter++;
			return;
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

			return;
		}
	}

	bool startValue = pixel[width][height];
	for (int i = width; i < width + N; i++)
	{
		for (int j = height; j < height + N; j++)
		{
			if (pixel[i][j] != startValue)
			{
				divider(width, height, N / 2);
				divider(width + N / 2, height, N / 2);
				divider(width, height + N / 2, N / 2);
				divider(width + N / 2, height + N / 2, N / 2);

				return;
			}
		}
	}

	if (startValue)
		blackPixelCounter++;
	else
		whitePixelCounter++;

	return;
}