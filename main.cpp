/*
 * Creator: Edward Bierens
 * Date Due: 2 April 2024 
 * Language: C++
 *
 * Description: This program will demonstrate how a Page Table functions, that being
 * converting a logical address into a physical address. The sample program for memory
 * management has proven to be helpful as to how this assignment is supposed to work, however
 * many changes were needed as can be seen...
*/

#include <iostream>
#include <sstream>

#define MAX_PAGES   	128    // Maximum amount of pages
#define MAX_FRAMES  	64	  // Maximum amount of frame
#define SIZE_OFF    	0x100 // Size of the block offset
#define SIZE_FRAME_OFF  0x100 // Size of the frame offset

// Making a page table class
struct PageTable {
		
		int page_table[MAX_PAGES]; // Table for all page numbers 
		
		// Constructor will map every page and memory to 0
		// A memory address of 0 will mean that it is not allocated
		PageTable() { 
			for (unsigned int i = 0; i < MAX_PAGES; i++) page_table[i] = -1;
		}

		// A circular map (including an offset)
		void circularMap(int offset) {
			for (unsigned int i = 0; i < MAX_PAGES; i++) page_table[i] = (i+offset) % MAX_FRAMES; 
		}
		
			
};

int main(int argc, char** argv) {
	
	srand(0); // Set a random seed 
	
	//Create and map the page table
	PageTable pt;
	pt.circularMap(0);
	
	// Use given addresses 
	unsigned int addr[20] = {0x3A7F, 0xABCD, 0x5678};

	// use random addresses for rest
	for (int i = 3; i < 20; i++) addr[i] = rand() % (MAX_PAGES * SIZE_OFF);
	
	// These addresses will be used to test
	for (unsigned int i = 0; i < 20; i++) {
		
		unsigned int page_num = addr[i] / SIZE_OFF; // Page number is the most significant bits above offset mark
		unsigned int off = addr[i] % SIZE_OFF;	   // Extract the block offset from the least significant bits

		// Ensure that the values stay in the page table by wrapping around with modulo.
		// Not the ideal way of doing it but this counts as	a way to prevent page faults for someone still learning...
		if (page_num >= MAX_PAGES) {
			std::cout << "WARNING: INVALID PAGE! Wrapping around to beginning...\n"; 
			page_num = page_num % MAX_PAGES;                                         
		} 								 	                                      

		// get the frame number 
		unsigned int frame = pt.page_table[page_num];
		
		// print out the results for memory address
		std::cout << "Logical Address: " << "0x" << std::hex << std::uppercase << addr[i]; 
		std::cout << " => Page Number: " << "0x" << std::hex << std::uppercase << frame;
		std::cout << ", Block Offset: " << "0x" << std::hex << std::uppercase << off;
		std::cout << "\n\n";
		
	}
	
}
