#include <cstdint>

class Chip8
{
public:
    // 16 8bit registers
    uint8_t registers[16]{};

    // 4k bytes of memory - address space: 0x000-0x1FF
    uint8_t memory[4096]{};

    // 16bit INdex register stores address for use in operations. 16 bit b/c the max address is 0xFFF, too big for 8 bit registers
    uint16_t index{};

    // 16bt program counter, PC, holds the address of the next instruction to execute. An instruction is two bytes, but memory is address as a single byte.
    // when fetching instructions from memory, one byte from pc and one byte from PC+1 to concatenate into a signle value, then increment by 2
    uint16_t pc{};

    // 16 level stack to keep track of the order of execution when CPU calls to functions.The CALL instrction -> CPU begins to execute instructions.
    // When the program reaches anothe instruction RET, it has to go back to where it hit the CALL instruction
    // The stack holds the PC value when the CALL instruction was executed, and the RETURN statement pulls that address from the stack and puts it back into the PC so the CPU
    // will execute it on the next cycle
    uint16_t stack{};
    uint8_t sp{};
    uint8_t delayTimer{};
    uint8_t soundTimer{};
    uint8_t keypad[16]{};
    uint32_t video[64 * 32]{};
    uint16_t opcode;
};

int main()
{
    return 0;
}