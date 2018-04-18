#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);

	int T;

	cin >> T;

	string prev, post;
	for (int i = 0; i < T; i++)
	{
		cin >> prev >> post;

		if (prev.length() > post.length())
		{
			cout << "NO" << endl;
			continue;
		}

		for (int j = 0; j < prev.length(); j++)
		{
			if (post.find(prev[j]) == post.npos)
			{
				goto NEXT;
			}
		}

		for (int j = 0; j < post.length(); j++)
		{
			if (prev.find(post[j]) == prev.npos)
			{
				goto NEXT;
			}
		}

		cout << "YES" << endl;
		continue;

	NEXT:
		cout << "NO" << endl;
	}

	system("pause");
}