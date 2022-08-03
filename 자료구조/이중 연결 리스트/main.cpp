#include <iostream>
#include <cstdio>

typedef struct Node
{
	Node *next;
	Node *prev;
	int data;
} node;

class DLL
{
private :
	node *head;
	node *tail;

public :
	DLL() : head(new node), tail(new node)
	{
		head->next = tail;
		head->prev = NULL;

		tail->next = NULL;
		tail->prev = head;
	}

	void insert(int data)
	{
		node *p;

		node *newNode = new node;
		newNode->data = data;

		newNode->next = tail;
		newNode->prev = tail->prev;
		tail->prev->next = newNode;
		tail->prev = newNode;
	}

	void remove(int element)
	{
		node *p = tail->prev;

		while (p != head && p->data != element)
			p = p->prev;

		if (p != head)
		{
			p->prev->next = p->next;
			p->next->prev = p->prev;
			delete p;
		}
	}

	void print()
	{
		std::cout << "Elements : ";

		for (node *p = head->next; p != tail; p = p->next)
			std::cout << p->data << " ";
		
		std::cout << std::endl;
	}

	~DLL()
	{
		node *pNext = NULL;

		for (node *p = head; p != NULL; p = pNext)
		{
			pNext = p->next;
			delete p;
		}

		std::cout << "Destructor executed" << std::endl;
	}
};

char select_operation(DLL *pDLL);

int main(int argc, char* argv[])
{
	DLL *pDLL = new DLL();
	char op = '\0';

	while ((op = select_operation(pDLL)) != 'q')
	{
		int num;

		switch (op)
		{
		case 'i' :
			std::cout << "Insert element : ";
			std::cin >> num;
			pDLL->insert(num);
			break;
		case 'r' :
			std::cout << "Remove element : ";
			std::cin >> num;
			pDLL->remove(num);
			break;
		}
	}

	delete pDLL;

	return 0;
}

char select_operation(DLL *pDLL)
{
	system("cls");

	pDLL->print();

	std::cout << std::endl << "Operation : ";

	return getchar();
}
