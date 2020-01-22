BSTlib:
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj

words_sentences:
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c word_counter.cpp
	link /OUT:word_counter.exe word_counter.obj BST.lib
	word_counter sentences_test.txt

words_words:
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c word_counter.cpp
	link /OUT:word_counter.exe word_counter.obj BST.lib
	word_counter single_words_test.txt

Test:
	cl /c BinarySearchTree.cpp
	lib /OUT:BST.lib BinarySearchTree.obj
	cl /c test.cpp
	link /OUT:BST.exe test.obj BST.lib
	BST

clean:
	del *.obj
	del *.exe
	del *.lib