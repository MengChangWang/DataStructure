#include"BinaryTree.h"
int main()
{
	BinaryTree bin_tree{ 1,5,82,83,80,4,6,8,3,48,65,879,546,784,8654,8749,617,874,627,489 ,75};
	bin_tree.print();
	cout << bin_tree.treeHeight();
	bin_tree.remove(82);
	bin_tree.print();
	return 0;
}
