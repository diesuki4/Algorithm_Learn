#include <iostream>
#include <vector>
#include <algorithm>

#define NUM_OF_DWARFS 9
#define NUM_OF_REAL_DWARFS 7
#define SUM_OF_HEIGHTS 100

int main(int argc, char* argv[])
{
	int diffHeights = -SUM_OF_HEIGHTS;
	std::vector<int> dwarfHeights;
	std::vector<int> mask(NUM_OF_REAL_DWARFS, 0);
	std::vector<int>::iterator itMaskBegin, itMaskEnd;

	mask.push_back(1);
	mask.push_back(1);

	for (int i = 0; i < NUM_OF_DWARFS; ++i)
	{
		int height;
		std::cin >> height;

		diffHeights += height;
		dwarfHeights.push_back(height);
	}	

	std::sort(dwarfHeights.begin(), dwarfHeights.end());

	itMaskBegin = mask.begin();
	itMaskEnd = mask.end();

	do
	{
		std::vector<int>::iterator itFirstPos = std::find(itMaskBegin, itMaskEnd, 1);
		std::vector<int>::iterator itSecondPos = std::find(itFirstPos + 1, itMaskEnd, 1);

		int iFirstPos = std::distance(itMaskBegin, itFirstPos);
		int iSecondPos = std::distance(itMaskBegin, itSecondPos);

		if (dwarfHeights[iFirstPos] + dwarfHeights[iSecondPos] == diffHeights) 
		{
			std::vector<int>::iterator itStart = dwarfHeights.begin();

			dwarfHeights.erase(itStart + iFirstPos);
			dwarfHeights.erase(itStart + --iSecondPos);

			break;
		}
	}
	while (std::next_permutation(itMaskBegin, itMaskEnd));

	for (int height : dwarfHeights)
		std::cout << height << std::endl;

	return 0;
}
