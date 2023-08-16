// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <regex>
#include <sstream>
#include <unordered_map>
#include <set>
#include <algorithm>

using namespace std;

enum class LANG;
enum class PART;
enum class CAREER;
enum class FOOD;
struct Info;
void print(vector<int> result);
Info parse(string& query_string);
vector<int> solution(vector<string> info, vector<string> query);

int main(int argc, char* argv[])
{
    print(solution({"java backend junior pizza 150",
                    "python frontend senior chicken 210",
                    "python frontend senior chicken 150",
                    "cpp backend senior pizza 260",
                    "java backend junior chicken 80",
                    "python backend senior chicken 50"}, 
        
                   {"java and backend and junior and pizza 100",
                    "python and frontend and senior and chicken 200",
                    "cpp and - and senior and pizza 250",
                    "- and backend and senior and - 150",
                    "- and - and - and chicken 100",
                    "- and - and - and - 150"}));

    return 0;
}

enum class LANG   { CPP, JAVA, PYTHON, ANY };
enum class PART   { BACKEND, FRONTEND, ANY };
enum class CAREER { JUNIOR, SENIOR, ANY };
enum class FOOD   { CHICKEN, PIZZA, ANY };

struct Info
{
    LANG lang;
    PART part;
    CAREER career;
    FOOD food;
    int score;
};

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

Info parse(string& query_string)
{
    Info info;
    istringstream iss(regex_replace(query_string, regex("and"), ""));

    string s;
    int score;

    iss >> s;
    info.lang = (s[0] == 'j') ? LANG::JAVA : (s[0] == 'c') ? LANG::CPP : (s[0] == 'p') ? LANG::PYTHON : LANG::ANY;
    iss >> s;
    info.part = (s[0] == 'b') ? PART::BACKEND : (s[0] == 'f') ? PART::FRONTEND : PART::ANY;
    iss >> s;
    info.career = (s[0] == 'j') ? CAREER::JUNIOR : (s[0] == 's') ? CAREER::SENIOR : CAREER::ANY;
    iss >> s;
    info.food = (s[0] == 'c') ? FOOD::CHICKEN : (s[0] == 'p') ? FOOD::PIZZA : FOOD::ANY;
    iss >> score;
    info.score = score;

    return info;
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    unordered_map<LANG, unordered_map<PART, unordered_map<CAREER, unordered_map<FOOD, vector<int>>>>> db;

    for (string& s : info)
    {
        Info in = parse(s);
        
        db[in.lang][in.part][in.career][in.food].emplace_back(in.score);
    }

    for (string& s : query)
    {
        Info q = parse(s);
        multiset<int> scores;

        vector<LANG> iLang = {q.lang};
        if (q.lang == LANG::ANY) iLang = {LANG::JAVA, LANG::CPP, LANG::PYTHON, LANG::ANY};

        vector<PART> iPart = {q.part};
        if (q.part == PART::ANY) iPart = {PART::BACKEND, PART::FRONTEND, PART::ANY};

        vector<CAREER> iCareer = {q.career};
        if (q.career == CAREER::ANY) iCareer = {CAREER::JUNIOR, CAREER::SENIOR, CAREER::ANY};

        vector<FOOD> iFood = {q.food};
        if (q.food == FOOD::ANY) iFood = {FOOD::CHICKEN, FOOD::PIZZA, FOOD::ANY};

        for (LANG L : iLang) for (PART P : iPart) for (CAREER C : iCareer) for (FOOD F : iFood)
            for (int score : db[L][P][C][F])
                scores.emplace(score);

        vector<int> vScores(scores.begin(), scores.end());

        int nRow = vScores.end() - lower_bound(vScores.begin(), vScores.end(), q.score);
        answer.emplace_back(nRow);
    }

    return answer;
}
