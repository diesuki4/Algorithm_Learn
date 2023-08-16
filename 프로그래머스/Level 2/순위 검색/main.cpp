// 이 풀이는 시간 초과가 발생한다.
#include <iostream>
#include <vector>
#include <regex>
#include <sstream>
#include <numeric>
#include <algorithm>

using namespace std;

enum class LANG;
enum class PART;
enum class CAREER;
enum class FOOD;
struct Info;
void print(vector<int> result);
Info parse(string& query_string);
int filter(vector<Info>& db, Info query);
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

int filter(vector<Info>& db, Info query)
{
    vector<int> input(db.size()), result;

    iota(input.begin(), input.end(), 0);
    if (query.lang == LANG::ANY)
        result = input;
    else
        copy_if(input.begin(), input.end(), back_inserter(result), [&](int i) { return (db[i].lang == query.lang); });

    input.clear();
    if (query.part == PART::ANY)
        input = result;
    else
        copy_if(result.begin(), result.end(), back_inserter(input), [&](int i) { return (db[i].part == query.part); });

    result.clear();
    if (query.career == CAREER::ANY)
        result = input;
    else
        copy_if(input.begin(), input.end(), back_inserter(result), [&](int i) { return (db[i].career == query.career); });

    input.clear();
    if (query.food == FOOD::ANY)
        input = result;
    else
        copy_if(result.begin(), result.end(), back_inserter(input), [&](int i) { return (db[i].food == query.food); });

    result.clear();
    copy_if(input.begin(), input.end(), back_inserter(result), [&](int i) { return (db[i].score >= query.score); });

    return result.size();
}

vector<int> solution(vector<string> info, vector<string> query)
{
    vector<int> answer;
    vector<Info> db;

    for (string& in : info)
        db.emplace_back(parse(in));

    for (string& q : query)
        answer.emplace_back(filter(db, parse(q)));

    return answer;
}
