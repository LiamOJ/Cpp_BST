/*
Author: Liam O'Neill Jablonski, 40405608
Date of Last Change: 03/04/2019
Program Purpose: 
The library creates a BinarySearchTree with basic features such as insert, search, string order building and counting. 
The test file (word_counter.cpp) then uses this library to count the instances of words in two supplied test files. 
*/
#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include "BinarySearchTree.h"

using namespace std;

int main(int argc, char **argv)
{
	//variables local to main
	string input_file_name;
	string line; //this will be the input a line at a time
	BinarySearchTree *tree = new BinarySearchTree;
	
	//pull file name from CLI, convert to string & open file
	input_file_name.assign(argv[1]);
	ifstream input_file(input_file_name);
	
	
	//Reads file in line by line
	while(getline(input_file, line))
	{
		//Local variables
		string edited_line;
		string tokenised_word;
		
		for(int loop = 0; loop < line.length(); ++loop) //iterate char by char
			if(!ispunct(line[loop])) //exclude punctuation
				edited_line.push_back(line[loop]); //this will be the line without punctuation
				
		stringstream line_stream(edited_line); //Made string into stream, to use getline based on space token. 
		
		while(getline(line_stream, tokenised_word, ' ')) //Tokenise
			tree->counter_input(tokenised_word);
		
	}
	
	string str;
	str = tree->counter_print();
	cout << str << endl;
	
	delete tree;
	tree = nullptr;
	input_file.close(); //I've read that this is unnecessary, but thought it best to do it anyway. 
	
	return 0;
}