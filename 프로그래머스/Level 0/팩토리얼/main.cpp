#include <iostream>
#include <algorithm>

using namespace std;

int solution(int n);

int main(int argc, char* argv[])
{
    cout << solution(3628800) << endl;
    cout << solution(7) << endl;
}

int solution(int n)
{
    const int arr[] = {1, 2, 6, 24, 120, 720, 5040, 40320, 362880, 3628800};
    size_t size = sizeof(arr) / sizeof(*arr);

    return upper_bound(arr, arr + size, n) - arr;
}
