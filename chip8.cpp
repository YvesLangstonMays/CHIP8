#include <fstream>
#include "chip8.h"
#include <stdio.h>
using namespace std;

// Chip 8 memory is reserved from 0x000 to 0x1FF, ROM instructions must start at 0x200
const unsigned int START_ADDRESS = 0x200;

void Chip8::LoadROM(char const *filename)
{
    // opens binary and goes to end of file. This avoids using seekg later.
    ifstream file(filename, ios::binary | ios::ate);

    if (file.is_open())
    {
        streampos size = file.tellg();
        char *buffer = new char[size];
    }
}