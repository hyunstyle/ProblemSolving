#include <iostream>
#include <set>
using namespace std;

void document(int a, int b, int x);
void under(int a, int b);
int kinds(int a, int b);

struct Employee {
	Employee* parent;
	int documentNumber;
	int selfIndex;
};

Employee* employee;
Employee* root;

int main()
{
	ios::sync_with_stdio(false);

	int N, K;

	cin >> N >> K;

	employee = new Employee[N+1];
	for (int i = 1; i <= N; i++)
	{
		if (i == 1)
		{
			employee[i].parent = NULL;
			employee[i].documentNumber = 0;
			employee[i].selfIndex = i;
			root = &employee[i];
		}
		else
		{
			employee[i].parent = &employee[1];
			employee[i].documentNumber = 1;
			employee[i].selfIndex = i;
		}
	}

	int r;
	for (int i = 0; i < K; i++)
	{
		cin >> r;
		int a, b, c;
		if (r == 1)
		{
			cin >> a >> b >> c;
			document(a, b, c);
		}
		else if (r == 2)
		{
			cin >> a >> b;
			under(a, b);
		}
		else if (r == 3)
		{
			cin >> a >> b;
			cout << kinds(a, b) << endl;
		}
	}

	/*under(9, 7);

	document(1, 3, 3);

	under(8, 5);

	under(3, 5);

	document(8, 6, 2);

	cout << "3 docu: " << employee[3].documentNumber << endl;
	cout << "5 docu: " << employee[5].documentNumber << endl;
	cout << "6 docu: " << employee[6].documentNumber << endl;
	cout << "8 docu: " << employee[8].documentNumber << endl;*/

	//system("pause");
}

void document(int a, int b, int x)
{
	if (a == b)
		return;

	Employee* aEmp = &employee[a];
	Employee* bEmp = &employee[b];

	int aEmpDepth = 0;
	int bEmpDepth = 0;

	while (true)
	{
		if (aEmp != root)
		{
			aEmp = aEmp->parent;
			aEmpDepth++;
		}
		else
			break;
	}

	while (true)
	{
		if (bEmp != root)
		{
			bEmp = bEmp->parent;
			bEmpDepth++;
		}
		else
			break;
	}

	aEmp = &employee[a];
	bEmp = &employee[b];

	if (aEmpDepth > bEmpDepth)
	{
		while (true)
		{
			if (aEmp != root && aEmp != bEmp)
			{
				aEmp->documentNumber = x;
				aEmp = aEmp->parent;
			}
			else
				break;
		}

		while (true)
		{
			if (bEmp != root && aEmp != bEmp)
			{
				bEmp->documentNumber = x;
				bEmp = bEmp->parent;
			}
			else
				break;
		}

		return;
	}
	else if (aEmpDepth < bEmpDepth)
	{
		while (true)
		{
			if (bEmp != root && bEmp != aEmp)
			{
				bEmp->documentNumber = x;
				bEmp = bEmp->parent;
			}
			else
				break;
		}

		while (true)
		{
			if (aEmp != root && aEmp != bEmp)
			{
				aEmp->documentNumber = x;
				aEmp = aEmp->parent;
			}
			else
				break;
		}

		return;
	}
	else
	{
		while (true)
		{
			if (aEmp != root && bEmp != root)
			{
				aEmp->documentNumber = x;
				bEmp->documentNumber = x;
				aEmp = aEmp->parent;
				bEmp = bEmp->parent;
			}
			else
				break;
		}

		return;
	}
}

void under(int a, int b)
{
	employee[a].parent = &employee[b];
}

int kinds(int a, int b)
{
	if (a == b)
		return 0;

	set<int> kindSet;

	Employee* aEmp = &employee[a];
	Employee* bEmp = &employee[b];

	int aEmpDepth = 0;
	int bEmpDepth = 0;

	while (true)
	{
		if (aEmp != root)
		{
			aEmp = aEmp->parent;
			aEmpDepth++;
		}
		else
			break;
	}

	while (true)
	{
		if (bEmp != root)
		{
			bEmp = bEmp->parent;
			bEmpDepth++;
		}
		else
			break;
	}

	aEmp = &employee[a];
	bEmp = &employee[b];

	if (aEmpDepth > bEmpDepth)
	{
		while (true)
		{
			if (aEmp != root && aEmp != bEmp)
			{
				kindSet.insert(aEmp->documentNumber);
				aEmp = aEmp->parent;
			}
			else
				break;
		}

		while (true)
		{
			if (bEmp != root && aEmp != bEmp)
			{
				kindSet.insert(bEmp->documentNumber);
				bEmp = bEmp->parent;
			}
			else
				break;
		}

		return kindSet.size();
	}
	else if (aEmpDepth < bEmpDepth)
	{
		while (true)
		{
			if (bEmp != root && bEmp != aEmp)
			{
				kindSet.insert(bEmp->documentNumber);
				bEmp = bEmp->parent;
			}
			else
				break;
		}

		while (true)
		{
			if (aEmp != root && aEmp != bEmp)
			{
				kindSet.insert(aEmp->documentNumber);
				aEmp = aEmp->parent;
			}
			else
				break;
		}

		return kindSet.size();
	}
	else
	{
		while (true)
		{
			if (aEmp != root && bEmp != root)
			{
				kindSet.insert(aEmp->documentNumber);
				kindSet.insert(bEmp->documentNumber);
				aEmp = aEmp->parent;
				bEmp = bEmp->parent;
			}
			else
				break;
		}

		return kindSet.size();
	}

}