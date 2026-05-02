# CHIP 8

Cowgod's Chip-8 Reference http://devernay.free.fr/hacks/chip8/C8TECH10.HTM

## Notable Differences In Instruction Behavior

### Cowgod


#### 8xy6
If the least significant bit of Vx is 1, VF is set to 1, otherwise 0. Then Vx isdivided by 2.
SHR Vx {, Vy} :  Set Vx = Vx SHR 1 

#### 8xye
If the most significant bit of Vx is 1, then VF is set 1, otherwise 0. Then Vx is multipled by 2.
SHL Vx {, Vy} Set Vx = Vx SHL 1

#### Fx55
Stores registers V0 through Vx in memory at location I.
The interpreter copies the values of register V0 through Vx into memory starting at the address in I. 
LD [I], Vx

#### Fx65
Read registers V0 through Vx from memory starting at location I.
The interpreter reads values from memory starting at location I into registers V0 through Vx.

### Random Guy On Reddit
Mistakes in cowgod relating to shift instructions nad memory loads/store.

8xyE and 9xy0 should shift y left or right by 1 bit and then write a result to x, but many implementations incorrectly shift x in place and ignore y. This is unnoticeable in smaller programs since they don't use these instructions often or have x and y as the same register.

Fx55/65 should load and store groups of registers via I, the memory index register, and increment I by the number of bytes loaded or stored. The increment features is often forgotten but smaller programs may only read/write to a fixed buffer so the bug goes unnoticed.

 


