#include <iostream>
#include <vector>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> keymap, vector<string> targets);

int main(int argc, char* argv[])
{
    print(solution({"ABACD", "BCEFD"}, {"ABCD", "AABB"}));
    print(solution({"AA"}, {"B"}));
    print(solution({"AGZ", "BSSS"}, {"ASA", "BGZ"}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<string> keymap, vector<string> targets)
{
    size_t size = targets.size();
    vector<int> answer(size, 0);

    for (int i = 0; i < size; ++i)
    {
        for (char c : targets[i])
        {
            int pos = -1;

            for (string key : keymap)
            {
                int p = key.find(c);

                pos = (p == -1) ? pos : (pos == -1) ? p : min(p, pos);
            }

            if (pos == -1)
            {
                answer[i] = -1;
                break;
            }

            answer[i] += pos + 1;
        }
    }

    return answer;
}
