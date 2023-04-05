#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

void print(vector<int> result);
vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo);

int main(int argc, char* argv[])
{
    print(solution({"may", "kein", "kain", "radi"}, {5, 10, 1, 3}, {{"may", "kein", "kain", "radi"}, {"may", "kein", "brin", "deny"}, {"kon", "kain", "may", "coni"}}));
    print(solution({"kali", "mari", "don"}, {11, 1, 55}, {{"kali", "mari", "don"}, {"pony", "tom", "teddy"}, {"con", "mona", "don"}}));
    print(solution({"may", "kein", "kain", "radi"}, {5, 10, 1, 3}, {{"may"}, {"kein", "deny", "may"}, {"kon", "coni"}}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo)
{
    vector<int> answer(photo.size());
    size_t size = name.size();
    unordered_map<string, int> umap;

    for (int i = 0; i < size; ++i)
        umap[name[i]] = yearning[i];

    auto func  = [&umap](int sum, string& s){ return sum + umap[s]; };
    auto func2 = [&func](vector<string>& v) { return accumulate(v.begin(), v.end(), 0, func); };
    transform(photo.begin(), photo.end(), answer.begin(), func2);

    return answer;
}
