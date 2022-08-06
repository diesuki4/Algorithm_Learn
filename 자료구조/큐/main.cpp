#include <iostream>

class Queue
{
private :
	size_t size;
	int front;
	int rear;
	int *elems;

public :
	Queue(size_t size = 10) : size(size + 1), front(0), rear(0)
	{
		elems = new int[size];
	}

	bool isEmpty() { return front == rear; }
	bool isFull() { return front == clamp(rear + 1); }

	int clamp(int index)
	{
		return index % size;
	}

	bool enqueue(int e)
	{
		if (isFull())
			return false;
		else
			elems[rear] = e;

		rear = clamp(rear + 1);

		return true;
	}

	bool peek(int &e)
	{
		if (isEmpty())
			return false;
		else
			e = elems[front];

		return true;
	}

	bool dequeue(int &e)
	{
		bool result = peek(e);

		if (result)
			front = clamp(front + 1);

		return result;
	}

	int search(int e)
	{
		for (int i = front; i != rear; i = clamp(i + 1))
			if (elems[i] == e)
				return i;
				
		return -1;
	}

	void print()
	{
		std::cout << "Size : " << size - 1 << std::endl;
		std::cout << "Front : " << front << ", Rear : " << rear << std::endl;
		std::cout << "Elements : ";

		for (int i = front; i != rear; i = clamp(i + 1))
			std::cout << elems[i] << " ";
		
		std::cout << std::endl;
	}

	~Queue()
	{
		delete elems;

		std::cout << "Destructor executed." << std::endl;
	}
};

char select_operation(Queue *pQueue);
void print_result(bool result, int num);

int main(int argc, char* argv[])
{
	Queue *pQueue = new Queue(5);
	char op = '\0';

	while ((op = select_operation(pQueue)) != 'q')
	{
		int num;
		bool result;

		switch (op)
		{
		case 'i' :
			std::cout << "Enqueue element : ";
			std::cin >> num;
			result = pQueue->enqueue(num);
			print_result(result, num);
			break;
		case 'r' :
			std::cout << "Dequeue element : ";
			result = pQueue->dequeue(num);
			print_result(result, num);
			break;
		case 'p' :
			std::cout << "Peek element : ";
			result = pQueue->peek(num);
			print_result(result, num);
			break;
		case 's' :
			std::cout << "Search element : ";
			std::cin >> num;
			num = pQueue->search(num);
			print_result((num != -1), num);
			break;
		}
	}

	delete pQueue;

	return 0;
}

char select_operation(Queue *pQueue)
{
	system("cls");

	pQueue->print();

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
