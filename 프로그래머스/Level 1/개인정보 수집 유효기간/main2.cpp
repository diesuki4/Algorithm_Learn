#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <sstream>

using namespace std;

void print(vector<int> result);
char parse_term_type(string term);
unsigned parse_term_month(string term);
string parse_privacy_date(string privacy);
char parse_privacy_type(string privacy);
unsigned parse_date_year(string date);
unsigned parse_date_month(string date);
unsigned parse_date_day(string date);
unsigned date_to_days(string date);
vector<int> solution(string today, vector<string> terms, vector<string> privacies);

int main(int argc, char* argv[])
{
    print(solution("2022.05.19", {"A 6", "B 12", "C 3"}, {"2021.05.02 A", "2021.07.01 B", "2022.02.19 C", "2022.02.20 C"}));
    print(solution("2020.01.01", {"Z 3", "D 5"}, {"2019.01.01 D", "2019.11.15 Z", "2019.08.02 D", "2019.07.01 D", "2018.12.28 Z"}));

    return 0;
}

void print(vector<int> result)
{
    for (int e : result)
        cout << e << " ";

    cout << endl;
}

char parse_term_type(string term) { return term[0]; }
unsigned parse_term_month(string term) { return stoi(term.substr(2)); }
string parse_privacy_date(string privacy) { return privacy.substr(0, 10); }
char parse_privacy_type(string privacy) { return privacy[11]; }
unsigned parse_date_year(string date) { return stoi(date.substr(0, 4)); }
unsigned parse_date_month(string date) { return stoi(date.substr(5, 2)); }
unsigned parse_date_day(string date) { return stoi(date.substr(8, 2)); }
unsigned date_to_days(string date)
{
    unsigned year = parse_date_year(date);
    unsigned month = parse_date_month(date);
    unsigned day = parse_date_day(date);

    return year * 12 * 28 + month * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies)
{
    vector<int> answer;
    size_t size = privacies.size();
    unordered_map<char, unsigned> umap;

    for (string term : terms)
        umap[parse_term_type(term)] = parse_term_month(term);

    for (int i = 0; i < size; ++i)
    {
        string& privacy = privacies[i];
        string pvcy_date = parse_privacy_date(privacy);
        char pvcy_type = parse_privacy_type(privacy);

        if (date_to_days(pvcy_date) + umap[pvcy_type] * 28 <= date_to_days(today))
            answer.emplace_back(i + 1);
    }

    return answer;
}
