#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(string my_string, vector<int> indices);

int main(int argc, char* argv[])
{
    cout << solution("apporoograpemmemprs", {1, 16, 6, 15, 0, 10, 11, 3});

    return 0;
}

string solution(string my_string, vector<int> indices)
{
    size_t len = my_string.length(), size = indices.size();
    string answer(len - size, '\0');
    unordered_map<int, bool> umap;
    
    for (int index : indices)
        umap[index] = true;

    for (int i = 0, j = 0; j < answer.length(); ++i)
        if (umap[i] == false)
            answer[j++] = my_string[i];

    return answer;
}
