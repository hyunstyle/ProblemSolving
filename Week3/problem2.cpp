#include <iostream>
#include <set>
using namespace std;

void document(int a, int b, int x);
void under(int a, int b);
int kinds(int a, int b);

struct Employee 
{
	Employee* parent;
	int selfIndex;
	int documentNumber;
};

struct Employee* root;
struct Employee* employee;

int main()
{
	std::ios::sync_with_stdio(false);

	int N, K;

	cin >> N >> K;

	employee = new Employee[N+1];

	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
		{
			employee[1].parent = NULL;
			employee[1].documentNumber = -1;
			root = &employee[1];
			root->selfIndex = 1;			
		}
		else
		{
			employee[i].parent = root;
			employee[i].selfIndex = i;
			employee[i].documentNumber = 1;
		}
		
	} // 초기 상태 만들기

	int a, b, c;
	for (int i = 0; i < K; i++)
	{
		int r;
		cin >> r;

		//int a, b, c;

		if (r == 1) // document
		{
			cin >> a >> b >> c;

			document(a, b, c);
		}
		else if (r == 2) // under
		{
			cin >> a >> b;

			under(a, b);
		}
		else if (r == 3) // kinds
		{
			cin >> a >> b;

			int kind = kinds(a, b);
			cout << kind << endl;
		}	
	}

	//employee[7].documentNumber = 23;

	//employee[5].documentNumber = 15;

	/*under(9, 7);

	document(1, 3, 3);

	under(8, 5);

	under(3, 5);

	document(8, 6, 2);

	cout << "3 docu: " << employee[3].documentNumber << endl;
	cout << "5 docu: " << employee[5].documentNumber << endl;
	cout << "6 docu: " << employee[6].documentNumber << endl;
	cout << "8 docu: " << employee[8].documentNumber << endl;*/

	//cout << "9 's parent: " << employee[9].parent->parent->documentNumber << endl;

	//cout << "9 docu: " << employee[5].parent->parent->documentNumber << endl;

	return 0;
}

void document(int a, int b, int x)
{
	if (a == b)
		return;

	int aDepthCounter = 0, bDepthCounter = 0;
	Employee* aTemp = &employee[a];
	Employee* bTemp = &employee[b];
	while (true)
	{
		if (aTemp->parent == NULL)
		{
			//cout << "a depth " << aDepthCounter << endl;
			break;
		}
		else
		{
			aDepthCounter++;
			aTemp = aTemp->parent;
		}
		
	}

	while (true)
	{
		if (bTemp->parent == NULL)
		{
			//cout << "b depth " << bDepthCounter << endl;
			break;
		}
		else
		{
			bDepthCounter++;
			bTemp = bTemp->parent;
		}
	}

	if (aDepthCounter == 0 && bDepthCounter == 0)
		return;
	else
	{
		aTemp = &employee[a];
		bTemp = &employee[b];

		if (aDepthCounter == 0 && bDepthCounter != 0)
		{
			while (true)
			{
				if (bTemp == root)
					return;
				else
				{
					bTemp->documentNumber = x;
					bTemp = bTemp->parent;
				}
			}
		}
		else if (aDepthCounter != 0 && bDepthCounter == 0)
		{
			while (true)
			{
				if (aTemp == root)
					return;
				else
				{
					aTemp->documentNumber = x;
					aTemp = aTemp->parent;
				}
			}
		}
		else // 둘다 Depth 0이 아닐 때
		{
			if (aDepthCounter == bDepthCounter) // 같은 Depth
			{
				while (true)
				{
					aTemp->documentNumber = x;
					bTemp->documentNumber = x;

					if (aTemp->parent == bTemp->parent)
						return;
					else
					{
						aTemp = aTemp->parent;
						bTemp = bTemp->parent;
					}
				}
			}
			else // 다른 Depth
			{
				if (aDepthCounter > bDepthCounter) // a가 더 깊을 때
				{
					while (true)
					{
						aTemp->documentNumber = x;
						if (aTemp->parent == bTemp)
							return;
						else
						{
							if (aTemp->parent == root)
								break;
							else
								aTemp = aTemp->parent;
							
						}
					}

					while (true) // a가 root까지 올라간 경우 실행
					{
						bTemp->documentNumber = x;
						if (bTemp->parent == root)
							return;
						else
							bTemp = bTemp->parent;
					}
				}
				else // b가 더 깊을 때
				{
					while (true)
					{
						bTemp->documentNumber = x;
						if (bTemp->parent == aTemp)
							return;
						else
						{
							if (bTemp->parent == root)
								break;
							else
								bTemp = bTemp->parent;

						}
					}

					while (true) // b가 root까지 올라간 경우 실행
					{
						aTemp->documentNumber = x;
						if (aTemp->parent == root)
							return;
						else
							aTemp = aTemp->parent;
					}
				}
			}
		}
	}


}


void under(int a, int b)
{
	employee[a].parent = &employee[b];

	//cout << a << " 's parent docu: " << employee[a].parent->documentNumber << endl;
}

int kinds(int a, int b)
{
	if (a == b)
		return 0;


	set<int> s;
	int aDepthCounter = 0, bDepthCounter = 0;
	Employee* aTemp = &employee[a];
	Employee* bTemp = &employee[b];
	while (true)
	{
		if (aTemp->parent == NULL)
		{
			//cout << "a depth " << aDepthCounter << endl;
			break;
		}
		else
		{
			aDepthCounter++;
			aTemp = aTemp->parent;
		}

	}

	while (true)
	{
		if (bTemp->parent == NULL)
		{
			//cout << "b depth " << bDepthCounter << endl;
			break;
		}
		else
		{
			bDepthCounter++;
			bTemp = bTemp->parent;
		}
	}

	//if (aDepthCounter == 0 && bDepthCounter == 0)
	//	return;
	//else
	//{

	aTemp = &employee[a];
	bTemp = &employee[b];

	if (aDepthCounter == 0 && bDepthCounter != 0)
	{
		while (true)
		{
			if (bTemp == root)
				return s.size();
			else
			{
				s.insert(bTemp->documentNumber); 
				bTemp = bTemp->parent;
			}
		}
	}
	else if (aDepthCounter != 0 && bDepthCounter == 0)
	{
		while (true)
		{
			if (aTemp == root)
				return s.size();
			else
			{
				s.insert(aTemp->documentNumber);
				aTemp = aTemp->parent;
			}
		}
	}
	else // 둘다 Depth 0이 아닐 때
	{
		if (aDepthCounter == bDepthCounter) // 같은 Depth
		{
			while (true)
			{
				s.insert(aTemp->documentNumber);
				s.insert(bTemp->documentNumber);

				if (aTemp->parent == bTemp->parent)
					return s.size();
				else
				{
					aTemp = aTemp->parent;
					bTemp = bTemp->parent;
				}
			}
		}
		else // 다른 Depth
		{
			if (aDepthCounter > bDepthCounter) // a가 더 깊을 때
			{
				while (true)
				{
					s.insert(aTemp->documentNumber);
					if (aTemp->parent == bTemp)
						return s.size();
					else
					{
						if (aTemp->parent == root)
							break;
						else
							aTemp = aTemp->parent;

					}
				}

				while (true) // a가 root까지 올라간 경우 실행
				{
					s.insert(bTemp->documentNumber);
					if (bTemp->parent == root)
						return s.size();
					else
						bTemp = bTemp->parent;
				}
			}
			else // b가 더 깊을 때
			{
				while (true)
				{
					s.insert(bTemp->documentNumber);
					if (bTemp->parent == aTemp)
						return s.size();
					else
					{
						if (bTemp->parent == root)
							break;
						else
							bTemp = bTemp->parent;

					}
				}

				while (true) // b가 root까지 올라간 경우 실행
				{
					s.insert(aTemp->documentNumber);
					if (aTemp->parent == root)
						return s.size();
					else
						aTemp = aTemp->parent;
				}
			}
		}
	}
	//}
}