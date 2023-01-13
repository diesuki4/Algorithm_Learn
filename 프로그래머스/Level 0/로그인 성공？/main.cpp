#include <iostream>
#include <vector>

using namespace std;

string solution(vector<string> id_pw, vector<vector<string>> db);

int main(int argc, char* argv[])
{
    cout << solution({"meosseugi", "1234"}, {{"rardss", "123"}, {"yyoom", "1234"}, {"meosseugi", "1234"}}) << endl;
    cout << solution({"programmer01", "15789"}, {{"programmer02", "111111"}, {"programmer00", "134"}, {"programmer01", "1145"}}) << endl;
    cout << solution({"rabbit04", "98761"}, {{"jaja11", "98761"}, {"krong0313", "29440"}, {"rabbit00", "111333"}}) << endl;
}

string solution(vector<string> id_pw, vector<vector<string>> db)
{
    for (vector<string> row : db)
        if (row[0] == id_pw[0])
            return (row[1] == id_pw[1]) ? "login" : "wrong pw";

    return "fail";
}
