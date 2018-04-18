#include <iostream>
//#include <string>
//#include <unordered_set>
using namespace std;

#define MAX_HASHTABLE_ENTRY 4000000

//struct Node {
//	int value;
//	//Node* next;
//};
//
//struct Node* hashTable[10000];

int setA[MAX_HASHTABLE_ENTRY];

int main()
{
	std::ios::sync_with_stdio(false);

	int T, N;
	

	//static set<int> orderedSet;

	//multiset<int> setA;

	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		/*for (int j = 0; j < MAX_HASHTABLE_ENTRY; j++)
		{
			setA[j] = -1;
		}*/

		cin >> N;
		
		int A, B;

		for (int j = 0; j < N; j++)
		{
			cin >> A; 

			if (setA[A % MAX_HASHTABLE_ENTRY] == NULL)
			{
				setA[A % MAX_HASHTABLE_ENTRY] = A;
			}
			else
			{
				int pointer = A % MAX_HASHTABLE_ENTRY;
				while (true)
				{
					//cout << "pointer: " << pointer << endl;
					pointer = (pointer % MAX_HASHTABLE_ENTRY) + 1;
					if (setA[pointer] == NULL)
					{
						setA[pointer] = A;
						break;
					}
				}
			}

			//Node* n = new Node();

			//n->value = A; // 값 저장

			//cout << "address: " << &(n->value) << endl;

			//if (hashTable[A % 10000] == NULL)
			//{
			//	hashTable[A % 10000] = n;
			//}
			//else // 해시 값 중복. Seperate Chaining 방식으로 저장
			//{
			//	Node* tempNode = hashTable[A % 10000];
			//	while (true)
			//	{
			//		tempNode = tempNode->next;

			//		if (tempNode == NULL)
			//		{
			//			tempNode = n;
			//			break;
			//		}
			//	}
			//}
		}

		//cout << "insert end" << endl;

		//int findCount = 0;

		bool isSame = true;
		for (int j = 0; j < N; j++)
		{
			cin >> B;

			int firstPointer = B % MAX_HASHTABLE_ENTRY;
			int pointer = firstPointer;

			if (setA[pointer] == NULL)
			{
				if (isSame)
					isSame = false;
				printf("%d ", B); // 출력 스트링 추가
			}
			else
			{
				while (true)
				{
					if (setA[pointer] == B)
					{
						break;
					}
					else
					{
						pointer = (pointer % MAX_HASHTABLE_ENTRY) + 1;
						if (pointer == firstPointer)
						{
							if (isSame)
								isSame = false;
							printf("%d ", B); // 출력 스트링 추가
						}
					}
				}
			}
			//Node* bPoint = hashTable[B % 10000];

			//if (bPoint == NULL) // B가 해시 테이블에 없을 경우
			//{
			//	output_string.append(to_string(B)).append(" "); // 출력 스트링 추가
			//	/*cout << B << " missing" << endl;
			//	findCount++;*/
			//}
			//else // B가 해시 테이블에 있을 경우
			//{
			//	while (true)
			//	{
			//		if (bPoint->value == B) // B가 A에 존재
			//		{
			//			break;
			//		}
			//		else // Chain 순회
			//		{
			//			if (bPoint != NULL)
			//			{
			//				bPoint = bPoint->next;
			//			}
			//			else // 더이상 Chain이 없는데 못찾은경우, 출력 스트링 추가
			//			{
			//				output_string.append(to_string(B)).append(" "); // 출력 스트링 추가
			//				/*cout << B << " missing" << endl;
			//				findCount++;*/
			//				break;
			//			}
			//		}
			//	}
			//}
		}

		//cout << "findCount: " << findCount << ", output: " << output_string << endl;

		if (isSame)
		{
			cout << "0" << endl;
		}
		else
		{
			printf("\n");
		}
	}

	//system("pause");

	return 0;
}