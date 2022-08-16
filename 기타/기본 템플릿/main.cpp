#include <iostream>

// 0 : 표준 입출력
// 1 : 파일 입출력
#define FILE_IO 0
#if FILE_IO
#include <fstream>
#define stdin "input.txt"
#define stdout "output.txt"
#endif

using namespace std;

int main(int argc, char* argv[])
{
#if FILE_IO
	ifstream cin(stdin);
	ofstream cout(stdout);
#endif

	// TODO

}
