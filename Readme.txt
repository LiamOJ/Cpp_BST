Author: LiamOJ
Date of Last Change: 03/04/2019
Program name: Library: BinarySearchTree.lib & test file: word_counter.cpp

Program Purpose: 
The library creates a BinarySearchTree with basic features such as insert, search, string order building and counting. 
The test file then uses this library to count the instances of words in two other test files. 

Program use: 

To use, via makefile commands -
BSTlib - makes the BinarySearchTree library
words_sentences - build library, compiles, links and executes for sentences_test.txt
words_words - build library, compiles, links and executes for single_words_test.txt
Test - build library, compiles, links and executes for supplied test.cpp file
clean - deletes all .obj, .exe and .lib files in directory

Tool chain:
Microsoft C/C++ Compiler

Known Issues:
No single or multi word deletion from tree possible
Use of shared_ptr in BST lib incurs heavy overhead. Use of unique or weak pointers may have wiser. 
Case sensitivity of words may cause confusion 
Removal of punctuation (in word_counter) could lead to some confusion with hyphens in typical use
