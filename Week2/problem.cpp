#include <iostream>
#include <string>

int main()
{
	std::ios::sync_with_stdio(false);

	int T;
	std::string preString;
	std::string postString;

	std::cin >> T;

	bool isYes;
	for (int i = 0; i < T; i++)
	{
		isYes = true;
		std::string alreadyAppearedString = "";

		std::cin >> preString >> postString;

		if ((int)postString.length() < (int)preString.length())
		{
			printf("NO\n");
			continue;
		}

		for (int j = 0; j < (int)preString.length(); j++)
		{
			if (postString.find(preString[j]) == postString.npos)
			{
				isYes = false;
				break;
			}
		}


		if (isYes)
		{
			for (int j = 0; j < (int)postString.length(); j++)
			{
				char c = postString[j];

				if (alreadyAppearedString.find(c) != alreadyAppearedString.npos)
					continue;

				if (preString.find(c) == preString.npos)
				{
					isYes = false;
					break;
				}
				else
					alreadyAppearedString += c;
			}
		}

		if (isYes)
			printf("YES\n");
		else
			printf("NO\n");

	}

	std::cin.get();
	std::cin.ignore();

	printf("\n");

	//system("pause");
	return 0;
}