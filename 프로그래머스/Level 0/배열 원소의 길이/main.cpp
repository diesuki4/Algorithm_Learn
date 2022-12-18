#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> strlist);

int main(int argc, char* argv[])
{
	print(solution({"We", "are", "the", "world!"}));
	print(solution({"I", "Love", "Programmers."}));

	return 0;
}

void print(vector<int> result)
{
	for (int num : result)
		cout << num << " ";
	cout << endl;
}

vector<int> solution(vector<string> strlist)
{
	size_t size = strlist.size();
	vector<int> answer(size);

	for (int i = 0; i < size; ++i)
		answer[i] = strlist[i].length();

    return answer;
}
