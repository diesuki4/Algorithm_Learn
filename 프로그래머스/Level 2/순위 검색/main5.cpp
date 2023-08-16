#include <iostream>
#include <vector>
#include <regex>
#include <sstream>
#include <unordered_map>
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

enum class LANG
{
    CPP     = 0b1000000000000,
    JAVA    = 0b0100000000000,
    PYTHON  = 0b0010000000000,
    ANY     = 0b0001000000000
};

enum class PART
{
    BACKEND     = 0b0000100000000,
    FRONTEND    = 0b0000010000000,
    ANY         = 0b0000001000000
};

enum class CAREER
{
    JUNIOR  = 0b0000000100000,
    SENIOR  = 0b0000000010000,
    ANY     = 0b0000000001000
};

enum class FOOD
{
    CHICKEN = 0b0000000000100,
    PIZZA   = 0b0000000000010,
    ANY     = 0b0000000000001
};

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
    unordered_map<int, vector<int>> db;

    for (string& s : info)
    {
        Info in = parse(s);

        vector<LANG> iLang = {LANG::ANY};
        if (in.lang != LANG::ANY) iLang.emplace_back(in.lang);

        vector<PART> iPart = {PART::ANY};
        if (in.part != PART::ANY) iPart.emplace_back(in.part);

        vector<CAREER> iCareer = {CAREER::ANY};
        if (in.career != CAREER::ANY) iCareer.emplace_back(in.career);

        vector<FOOD> iFood = {FOOD::ANY};
        if (in.food != FOOD::ANY) iFood.emplace_back(in.food);

        for (LANG L : iLang) for (PART P : iPart) for (CAREER C : iCareer) for (FOOD F : iFood)
            db[int(L) | int(P) | int(C) | int(F)].emplace_back(in.score);
    }

    for (auto& pr : db)
        sort(pr.second.begin(), pr.second.end());

    for (string& s : query)
    {
        Info q = parse(s);
        vector<int>& scores = db[int(q.lang) | int(q.part) | int(q.career) | int(q.food)];

        int nRow = scores.end() - lower_bound(scores.begin(), scores.end(), q.score);
        answer.emplace_back(nRow);
    }

    return answer;
}
