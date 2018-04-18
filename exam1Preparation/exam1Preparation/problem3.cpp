#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string prev, post;

		cin >> prev >> post;

		if (prev.length() > post.length())
		{
			cout << "NO" << endl;

			goto NEXT;
		}

		for (int j = 0; j < prev.length(); j++)
		{
			if (post.find(prev[j]) == post.npos)
			{
				cout << "NO" << endl;
				goto NEXT;
			}
		}

		for (int j = 0; j < post.length(); j++)
		{
			if (prev.find(post[j]) == prev.npos)
			{
				cout << "NO" << endl;
				goto NEXT;
			}
		}

		cout << "YES" << endl;
	NEXT:
		continue;
	}

	//system("pause");
}