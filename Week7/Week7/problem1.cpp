#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	short T;

	cin >> T;

	while (T--)
	{
		string N; // C++ string : mutable -> less important of concatenation issue. (Java - immutable) 
		string reverse;

		cin >> N;

		reverse = N;

		char temp;
		for (int i = 0; i < N.length() / 2; i++)
		{
			temp = reverse[i];
			reverse[i] = reverse[N.length() - 1 - i];
			reverse[N.length() - 1 - i] = temp;
		}

		int input = stoi(N);
		int reverseInput = stoi(reverse);

		int sum = input + reverseInput;

		N = to_string(sum);

		bool isSymmetric = true;
		for (int i = 0; i < N.length() / 2; i++)
		{
			if (N[i] != N[N.length() - 1 - i])
			{
				isSymmetric = false;
				break;
			}
		}

		if (isSymmetric)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}