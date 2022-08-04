#include <iostream>

#define NUM_OF_DWARFS 9
#define SUM_OF_HEIGHTS 100
#define VALID_DWARF 1
#define INVALID_DWARF 0

int main(int argc, char* argv[])
{
	int diffHeights = -SUM_OF_HEIGHTS;
	int dwarfHeights[NUM_OF_DWARFS] = {0};
	int arrValid[SUM_OF_HEIGHTS] = {0};

	for(int i = 0; i < NUM_OF_DWARFS; ++i)
	{
		std::cin >> dwarfHeights[i];

		diffHeights += dwarfHeights[i];
		arrValid[dwarfHeights[i]] = VALID_DWARF;
	}

	for (int i = 0; i < NUM_OF_DWARFS - 1; ++i)
	{
		for (int j = i + 1; j < NUM_OF_DWARFS; ++j)
		{
			if (dwarfHeights[i] + dwarfHeights[j] == diffHeights)
			{
				arrValid[dwarfHeights[i]] = arrValid[dwarfHeights[j]] = INVALID_DWARF;
				i = j = NUM_OF_DWARFS;
			}
		}
	}

	for (int i = 0; i < SUM_OF_HEIGHTS; ++i)
		if (arrValid[i] == VALID_DWARF)
			std::cout << i << std::endl;

	return 0;
}
