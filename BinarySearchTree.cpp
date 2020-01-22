#include "BinarySearchTree.h"

//Helper method prototypes
void BinarySearchTree_Helper(const std::shared_ptr<Node> &rhs, std::shared_ptr<Node> &root);
void insert_helper(std::shared_ptr<Node> &root, std::string word);
std::string inorder_helper(std::shared_ptr<Node> root);
bool exists_helper(std::string word, std::shared_ptr<Node> root);
std::string preorder_helper(std::shared_ptr<Node> root);
std::string postorder_helper(std::shared_ptr<Node> root);
void operator_helper(const std::shared_ptr<Node> &rhs, std::shared_ptr<Node> &root);
void operator_inserter(std::shared_ptr<Node> &root, std::string word);
void counter_input_helper(std::shared_ptr<Node> &root, std::string word);
std::string counter_print_helper(std::shared_ptr<Node> root);

// **Constructors **
BinarySearchTree::BinarySearchTree()
{
	//do nothing
}

BinarySearchTree::BinarySearchTree(std::string word)
{
	root = std::make_shared<Node>();
	root->word = word;
}

BinarySearchTree::BinarySearchTree(const BinarySearchTree &rhs)
{
	//new tree
	root = std::shared_ptr<Node>(nullptr);
	
	//Pass in the private variable of the class instance the current function has
	BinarySearchTree_Helper(rhs.root, root);
}

BinarySearchTree::BinarySearchTree(const std::vector<std::string> &words)
{
	root = std::shared_ptr<Node>(nullptr); //using make_shared resulted in an empty space being the first word. 
	
	for(int loop = 0; loop < words.size(); ++loop)
		insert_helper(root, words[loop]);
}
//destructor
BinarySearchTree::~BinarySearchTree()
{
	//do nothing - smart pointers. 
}

// **Methods**
void BinarySearchTree::insert(std::string word)
{
	insert_helper(root, word);
}

bool BinarySearchTree::exists(std::string word) const
{
	return exists_helper(word, root);
}

std::string BinarySearchTree::inorder() const
{	
	std::string word;
	
	word = inorder_helper(root);
	
	if(word.length() > 1)
		word.pop_back(); //remove last space
	
	return word;
}

std::string BinarySearchTree::preorder() const
{
	std::string word;
	
	word = preorder_helper(root);
	
	if(word.length() > 1)
		word.pop_back(); //remove last space
	
	return word;
}

std::string BinarySearchTree::postorder() const
{
	std::string word;
	
	word = postorder_helper(root);
	
	if(word.length() > 1)
		word.pop_back(); //remove last space
	
	return word;
}
    
// **Operator overloads**
BinarySearchTree& BinarySearchTree::operator+(std::string word)
{
	insert_helper(this->root,word);
	
	return *this;
}

BinarySearchTree& BinarySearchTree::operator=(const BinarySearchTree &rhs)
{
	if(this == &rhs)
		return *this; //protect against self assignment

	if(this != &rhs)
		this->root = nullptr; //clear left side
	
	BinarySearchTree_Helper(rhs.root, this->root); //replace left side with RHS content
	return *this;
}

//Helper Methods

/*
Method Name: Counter Print Helper
Method Purpose: private function recursively build string + counter (inorder) which is passed back to main program
Method Paramaters:
shared_ptr<Node> root: the instance variable root pointer
*/
std::string BinarySearchTree::counter_print_helper(std::shared_ptr<Node> root) const
{	
	if(root == nullptr)
		return std::string("");
	else
	{
		std::string str = std::to_string(root->counter); //Has to be past the if statement to protect against empty nodes being used. Convert integer with to_string to return. 
		
		return counter_print_helper(root->left) + root->word + std::string(": ") + str + std::string("\n") + counter_print_helper(root->right); 
	}
}

/*
Method Name: counter_print
Method Purpose: public function, allows main function to call string with word + counter.
Method Paramaters:
N/A.
*/
std::string BinarySearchTree::counter_print() const
{	
	std::string word;
	
	word = counter_print_helper(root);
	
	if(word.length() > 1)
		word.pop_back();
	
	return word;
}

/*
Method Name: Counter Input Helper 
Method Purpose: private function to add users word to tree and increment counter
Method Paramaters:
shared_ptr<Node> &root - reference to root instance
word - the word, from main application, to be added and counted. 

*/
void BinarySearchTree::counter_input_helper(std::shared_ptr<Node> &root, std::string word)
{	
	if(root == nullptr)
	{
		root = std::make_shared<Node>();
		root->word = word;
		root->left = nullptr;
		root->right = nullptr;
	} else if (word < root->word)
		counter_input_helper(root->left, word);
	else if (word > root->word)
		counter_input_helper(root->right, word);
	else
		if(exists_helper(word, root))
			root->counter += 1;
			//incrementer HAS to go here.
}

/*
Method Name: Counter Input
Method Purpose: Public function, allows user from to add word to tree to be counted.  
Method Paramaters:
word - the word from user in main application to be added to tree. 

*/
void BinarySearchTree::counter_input(const std::string word)
{
	counter_input_helper(root, word);
}

/*
Method Name: BinarySearchTree Helper
Method Purpose: Private function, recursively inserts word into tree. Used both for constructor and assignment operator
Method Paramaters:
shared_ptr<Node> &root - reference to left hand side root/tree (the one to be changed)
shared_ptr<Node> &rhs - reference to right hand side root/tree (one to be copied)
*/
void BinarySearchTree::BinarySearchTree_Helper(const std::shared_ptr<Node> &rhs, std::shared_ptr<Node> &root)
{	
	if(rhs != nullptr)
	{
		insert_helper(root, rhs->word);
		BinarySearchTree_Helper(rhs->left, root);
		BinarySearchTree_Helper(rhs->right, root);
	}
}


/*
Method Name: Insert Helper
Method Purpose: Private function, recursively inserts word into tree. Does not alter counter. 
Method Paramaters:
shared_ptr<Node> &root - reference to root instance
word - the word to be added
*/
void BinarySearchTree::insert_helper(std::shared_ptr<Node> &root, std::string word)
{	
	if(root == nullptr)
	{
		root = std::make_shared<Node>();
		root->word = word;
		root->left = nullptr;
		root->right = nullptr;
	} else if (word < root->word)
		insert_helper(root->left, word);
	else if (word > root->word)
		insert_helper(root->right, word);
	else 
		return;
}


/*
Method Name: Exists Helper
Method Purpose: private function, recursively searches tree for word and returns true if in tree
Method Paramaters:
word - the word to be searched for
shared_ptr<Node> root - the tree to be searched
*/
bool BinarySearchTree::exists_helper(std::string word, std::shared_ptr<Node> root) const
{
	while(root != nullptr)
	{
		if(word == root->word)
			return true;
		else if (word < root->word)
			root = root->left;
		else
			root = root->right;
	}
	
	return false;
}


/*
Method Name: Post Order Helper
Method Purpose: Private function, recursively creates and returns string of tree contents in post order
Method Paramaters:
shared_ptr<Node> root - the tree to be used.
*/
std::string BinarySearchTree::postorder_helper(std::shared_ptr<Node> root) const 
{
	//left, right, word. Like an onion. 
	if(root == nullptr)
		return std::string("");
	else
		return postorder_helper(root->left) + postorder_helper(root->right) + root->word + std::string(" ");
}


/*
Method Name: In Order Helper
Method Purpose: Private function, recursively creates and returns string of tree contents in in order
Method Paramaters:
shared_ptr<Node> root - the tree to be used.
*/
std::string BinarySearchTree::inorder_helper(std::shared_ptr<Node> root) const
{
	
	if(root == nullptr)
		return std::string("");
	else
		return inorder_helper(root->left) + root->word + std::string(" ") + inorder_helper(root->right); 
}


/*
Method Name: Pre Order Helper
Method Purpose: Private function, recursively creates and returns string of tree contents in pre order
Method Paramaters:
shared_ptr<Node> root - the tree to be used.
*/
std::string BinarySearchTree::preorder_helper(std::shared_ptr<Node> root) const 
{
	//print, left, right
	if(root == nullptr)
		return std::string("");
	else
		return root->word + std::string(" ") + preorder_helper(root->left) + preorder_helper(root->right);
}