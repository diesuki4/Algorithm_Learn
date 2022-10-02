#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int M, J;
	int front = 1;
	int distance = 0;

	cin >> M >> M >> J;

	while (J--)
	{
		int apple;
		int rear = front + M - 1;

		cin >> apple;

		if (apple < front)
		{
			distance += front - apple;
			front = apple;
		}
		else if (rear < apple)
		{
			distance += apple - rear;
			front = apple - M + 1;
		}
	}

	cout << distance;

	return 0;
}
