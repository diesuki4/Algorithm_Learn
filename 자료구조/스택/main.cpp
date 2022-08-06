#include <iostream>

class Stack
{
private :
	size_t size;
	int top;
	int *elems;

public :
	Stack(size_t size = 10) : size(size), top(-1)
	{
		elems = new int[size];
	}

	bool isEmpty() { return top == -1; }
	bool isFull() { return top == size - 1; }

	bool push(int e)
	{
		if (isFull())
			return false;
		else
			elems[++top] = e;

		return true;
	}

	bool peek(int &e)
	{
		if (isEmpty())
			return false;
		else
			e = elems[top];

		return true;
	}

	bool pop(int &e)
	{
		bool result = peek(e);

		if (result)
			--top;

		return result;
	}

	int search(int e)
	{
		for (int i = 0; i <= top; ++i)
			if (elems[i] == e)
				return i;
				
		return -1;
	}

	void print()
	{
		std::cout << "Size : " << size << std::endl;
		std::cout << "Elements : ";

		for (int i = 0; i <= top; ++i)
			std::cout << elems[i] << " ";
		
		std::cout << std::endl;
	}

	~Stack()
	{
		delete elems;

		std::cout << "Destructor executed." << std::endl;
	}
};

char select_operation(Stack *pStack);
void print_result(bool result, int num);

int main(int argc, char* argv[])
{
	Stack *pStack = new Stack(5);
	char op = '\0';

	while ((op = select_operation(pStack)) != 'q')
	{
		int num;
		bool result;

		switch (op)
		{
		case 'i' :
			std::cout << "Push element : ";
			std::cin >> num;
			result = pStack->push(num);
			print_result(result, num);
			break;
		case 'r' :
			std::cout << "Pop element : ";
			result = pStack->pop(num);
			print_result(result, num);
			break;
		case 'p' :
			std::cout << "Peek element : ";
			result = pStack->peek(num);
			print_result(result, num);
			break;
		case 's' :
			std::cout << "Search element : ";
			std::cin >> num;
			num = pStack->search(num);
			print_result((num != -1), num);
			break;
		}
	}

	delete pStack;

	return 0;
}

char select_operation(Stack *pStack)
{
	system("cls");

	pStack->print();

	std::cout << std::endl << "Operation : ";

	return getchar();
}

void print_result(bool result, int num)
{
	std::string s = result ? "Success" : "Fail";

	if (result)
		std::cout << "[" << num << "] ";

	std::cout << s << std::endl;

	system("pause");
}
