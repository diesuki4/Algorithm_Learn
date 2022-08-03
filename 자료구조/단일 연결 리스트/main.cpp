#include <iostream>
#include <cstdio>

typedef struct Node
{
	Node *next;
	int data;
} node;

class SLL
{
private :
	node *head;

public :
	SLL() : head(new node)
	{
		head->next = NULL;
	}

	void insert(int data)
	{
		node *p;

		for (p = head; p->next != NULL; p = p->next);

		node *newNode = new node;
		newNode->data = data;
		
		newNode->next = p->next;
		p->next = newNode;
	}

	void remove(int element)
	{
		node *prev = head;
		node *p = head->next;

		while (p != NULL && p->data != element)
		{
			prev = p;
			p = p->next;
		}

		if (p != NULL)
		{
			prev->next = p->next;
			delete p;
		}
	}

	void print()
	{
		std::cout << "Elements : ";

		for (node *p = head->next; p != NULL; p = p->next)
			std::cout << p->data << " ";
		
		std::cout << std::endl;
	}

	~SLL()
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

char select_operation(SLL *pSLL);

int main(int argc, char* argv[])
{
	SLL *pSLL = new SLL();
	char op = '\0';

	while ((op = select_operation(pSLL)) != 'q')
	{
		int num;

		switch (op)
		{
		case 'i' :
			std::cout << "Insert element : ";
			std::cin >> num;
			pSLL->insert(num);
			break;
		case 'r' :
			std::cout << "Remove element : ";
			std::cin >> num;
			pSLL->remove(num);
			break;
		}
	}

	delete pSLL;

	return 0;
}

char select_operation(SLL *pSLL)
{
	system("cls");

	pSLL->print();

	std::cout << std::endl << "Operation : ";

	return getchar();
}
