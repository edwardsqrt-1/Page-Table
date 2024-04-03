# Page-Table

This program will demonstrate how a Page Table functions. Essentially, it takes a logical address, and then proceeds to convert the address into a physical address for the memory. The layout of the program
is such that it will generate 20 memory addresses, 3 given and 17 randomized, and will output the page number and block offset for each one of them! The sample program for memory management has proven to be a 
big help for understanding the concept of how this worked, but it was clear it was not going to be enough to solve this problem

Note: I noticed that addresses 0x3A7F and 0x5678 do not yield the correct results, I believe this has something to do with the number of pages being too high, however I have found using smaller numbers only screws up the correct one which was 0xABCD

## How to Build

Simply go into your working directory and use the command `g++ main.cpp -o main` to build this program. Then run the generated executable in a terminal to see the output!
