#pragma once

#include <string>

// Node of a tree, stores a word. Default is public. 
struct Node
{
    // Word stored in this node of the tree
    std::string word = "";
	//stores the counter of words, set to one by default. 
    int counter = 1; 
    // The left branch of the tree
    std::shared_ptr<Node> left = nullptr;
    // The right branch of the tree
    std::shared_ptr<Node> right = nullptr;
};
