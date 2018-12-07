#include<iostream>
using namespace std;

struct data
{
	int tuso;
	int mauso;
};
typedef struct data DATA;

struct node
{
	DATA *data;
	node *pNext;
};
typedef struct node NODE;

int main()
{
	NODE *pHead;
	pHead = new NODE;
	pHead->data = new DATA;
	cout << "\n\n\t\tNhap data thứ nhất" << endl;
	cout << "tu so" << endl;
	cin >> pHead->data->tuso;
	cout << "mau so" << endl;
	cin >> pHead->data->mauso;

	// gắn thêm phần tử thứ 2

	NODE * trav = pHead;

	NODE *pTail = pHead;
	for (int i = 0; i < 2; i++)
	{
		pTail->pNext = new NODE;

		pTail->pNext->pNext = NULL;
		pTail->pNext->data = new DATA;
		cin >> pTail->pNext->data->tuso;
		cin >> pTail->pNext->data->mauso;
		pTail = pTail->pNext;
	}

	while (trav != NULL)
	{
		cout << trav->data->tuso << "/" << trav->data->mauso << endl;
		trav = trav->pNext;
	}

	NODE *min;
	NODE *next;
	min = pHead;
	while (min->pNext != NULL)
	{
		next = min->pNext;
		while (next != NULL)
		{
			float Min = (float)min->data->tuso / min->data->mauso;
			float Next = (float)next->data->tuso / next->data->mauso;

			if (Min > Next)
			{
				DATA *tam = min->data;
				min->data = next->data;
				next->data = tam;
			}
			next = next->pNext;
		}
		min = min->pNext;
	}

	cout << "\n\n\t\t Danh sach sau khi sap xep";
	trav = pHead;
	while (trav != NULL)
	{
		cout << trav->data->tuso << "/" << trav->data->mauso << endl;
		trav = trav->pNext;
	}

	system("pause");
	return 0;
}