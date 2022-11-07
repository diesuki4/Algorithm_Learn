#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> ingredient);
int cook(stack<int>& stck);

int main(int argc, char* argv[])
{
	cout << solution({2, 1, 1, 2, 3, 1, 2, 3, 1}) << endl;
	cout << solution({1, 3, 2, 1, 2, 1, 3, 1, 2}) << endl;

	return 0;
}

int solution(vector<int> ingredient)
{
	int answer = 0;
	stack<int> stck;

	// 재료를 앞에서부터 1개씩 순회
	for (int e : ingredient)
	{
		// 스택 위에 재료를 쌓는다
		stck.push(e);

		// 스택에 쌓인 재료가 4개 이상이면
		if (4 <= stck.size())
			// 조리
			answer += cook(stck);
	}

	return answer;
}

int cook(stack<int>& stck)
{
	// 위에서부터 1개씩 재료를 꺼낸다
	int ingredient4 = stck.top(); stck.pop();
	int ingredient3 = stck.top(); stck.pop();
	int ingredient2 = stck.top(); stck.pop();
	int ingredient1 = stck.top(); stck.pop();

	// 재료의 순서가 빵 -> 야채 -> 고기 -> 빵 순이면
	if (ingredient1 == 1 && ingredient2 == 2 && ingredient3 == 3 && ingredient4 == 1)
	{
		// 햄버거 1개를 만들어 반환
		return 1;
	}
	// 햄버거를 만들 수 없으면
	else
	{
		// 스택에 재료를 기존 순서대로 다시 쌓고
		stck.push(ingredient1);
		stck.push(ingredient2);
		stck.push(ingredient3);
		stck.push(ingredient4);

		// 0개 반환
		return 0;
	}
}
