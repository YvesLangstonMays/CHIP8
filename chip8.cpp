#include <fstream>
#include "chip8.h"
#include <stdio.h>
#include <chrono>
#include <cstdint>
#include <random>
#include <cstring>

using namespace std;

// Chip 8 memory is reserved from 0x000 to 0x1FF, ROM instructions must start at 0x200
const unsigned int START_ADDRESS = 0x200;

const unsigned int FONTSET_SIZE = 80;

const unsigned int FONTSET_START_ADDRESS = 0x50;

uint8_t fontset[FONTSET_SIZE] =
    {
        0xF0, 0x90, 0x90, 0x90, 0xF0, // 0
        0x20, 0x60, 0x20, 0x20, 0x70, // 1
        0xF0, 0x10, 0xF0, 0x80, 0xF0, // 2
        0xF0, 0x10, 0xF0, 0x10, 0xF0, // 3
        0x90, 0x90, 0xF0, 0x10, 0x10, // 4
        0xF0, 0x80, 0xF0, 0x10, 0xF0, // 5
        0xF0, 0x80, 0xF0, 0x90, 0xF0, // 6
        0xF0, 0x10, 0x20, 0x40, 0x40, // 7
        0xF0, 0x90, 0xF0, 0x90, 0xF0, // 8
        0xF0, 0x90, 0xF0, 0x10, 0xF0, // 9
        0xF0, 0x90, 0xF0, 0x90, 0x90, // A
        0xE0, 0x90, 0xE0, 0x90, 0xE0, // B
        0xF0, 0x80, 0x80, 0x80, 0xF0, // C
        0xE0, 0x90, 0x90, 0x90, 0xE0, // D
        0xF0, 0x80, 0xF0, 0x80, 0xF0, // E
        0xF0, 0x80, 0xF0, 0x80, 0x80  // F
};

Chip8::Chip8()
    // the instruction that puts a random number into a register needs to be emulated using random
    // takes a seed argument serving as a starting point
    // by using the time, th random number sequence generated is always different
    : randGen(std::chrono::system_clock::now().time_since_epoch().count())
{
    // set the pc to 0x200
    pc = START_ADDRESS;

    // load the fonts
    for (unsigned int i = 0; i < FONTSET_SIZE; ++i)
    {
        // set the location in memory to the item in the fontset
        memory[FONTSET_START_ADDRESS + i] = fontset[i];
    }

    // uniform -> every number in the range has equal chance, int dist -> produces whole numbers
    randByte = std::uniform_int_distribution<uint8_t>(0, 255U);
}