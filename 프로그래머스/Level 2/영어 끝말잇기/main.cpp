#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

void print(vector<int> result);
vector<int> solution(int n, vector<string> words);

int main(int argc, char* argv[])
{
    print(solution(3, {"tank", "kick", "know", "wheel",
                       "land", "dream", "mother", "robot", "tank"}));

    print(solution(5, {"hello", "observe", "effect", "take", "either",
                       "recognize", "encourage", "ensure", "establish",
                       "hang", "gather", "refer", "reference", "estimate", "executive"}));
    
    print(solution(2, {"hello", "one", "even", "never", "now", "world", "draw"}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(int n, vector<string> words)
{
    size_t size = words.size();
    char lastChar = words.front().front();
    unordered_set<string> uset;

    for (int i = 0; i < size; ++i)
    {
        string& s = words[i];

        if (uset.insert(s).second == false || s.front() != lastChar)
            return vector<int>{i % n + 1, i / n + 1};

        lastChar = s.back();
    }

    return vector<int>{0, 0};
}
