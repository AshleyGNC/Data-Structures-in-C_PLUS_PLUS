/*
 * FinalLab14.cpp
 *
 *  Created on: May 11, 2022
 *      Author: Ashley
 */

struct TreeNode{
	int data;
	TreeNode *left;
	TreeNode *right;

	TreeNode(int d){
		data = d;
		left = nullptr;
		right = nullptr;
	}
};

#include <iostream>
#include "Vector.h"
#include "strlib.h"
#include "simpio.h"

using namespace std;

bool isSymmetricHelper(TreeNode* t1, TreeNode* t2){
	if((t1 == nullptr) && (t2 == nullptr)) return true;
	if((t1 == nullptr) || (t2 == nullptr)) return false;

	return (t1->data == t2->data) && isSymmetricHelper(t1->left, t2->right)
			&& isSymmetricHelper(t1->right, t2->left);
}

bool isSymmetric(TreeNode* root) {
	return isSymmetricHelper(root, root);
}

//-------------------------------------------------------------------------

void dfs(TreeNode* node, Vector<string>& result, string so_far){
	if(node == nullptr) return;

	so_far += integerToString(node->data) + "->";

	if(node->left == nullptr && node->right == nullptr){
		result += so_far;
		return;
	}
	dfs(node->left, result, so_far);
	dfs(node->right, result, so_far);
}

Vector<string> binaryTreePaths(TreeNode* root) {
	Vector<string> path;
	dfs(root, path, "");
	return path;
}

//----------------------------------------------------------------------------
//post-Order traversal
void printPostorder(TreeNode* node) {
	if(node == nullptr)	return;

	printPostorder(node->left);
	printPostorder(node->right);

	cout << node->data << endl;

}
/*
 Given a tree and a sum, return true if there is a path from the root
 down to a leaf, such that adding up all the values along the path
 equals the given sum.
 Strategy: subtract the node value from the sum when recurring down,
 and check to see if the sum is 0 when you run out of tree.
*/
bool hasPathSum(TreeNode* node, int sum) {
	if(node == nullptr){
		return (sum==0);
	}else{
		int subSum = sum - node->data;
		return (hasPathSum(node->left, subSum) || hasPathSum(node->right, subSum));
	}
}

void mirror(TreeNode* node){
	if(node == nullptr) return;

	mirror(node->left);
	mirror(node->right);

	TreeNode* temp = node->left;
	node->left = node->right;
	node->right = temp;
	/*
	 * For doubling the tree elements instead of swap, STILL dfs!
		// duplicate this node to its left
	  oldLeft = node->left;
	  node->left = newNode(node->data);
	  node->left->left = oldLeft;
	*/
}

/*
int main__8() {
    /*           1
     *         /   \
     *        2     2
     *       / \   / \
     *      3   4 4   3
     */

    TreeNode* Tree1 = new TreeNode(1);
    Tree1->left = new TreeNode(2);
    Tree1->right = new TreeNode(2);
    Tree1->left->left =new TreeNode(3);
    Tree1->left->right =new TreeNode(4);
    Tree1->right->left =new TreeNode(4);
    Tree1->right->right =new TreeNode(3);

    /*           1
     *         /   \
     *        2     2
     *         \     \
     *          3     3
     */

    TreeNode* Tree2 = new TreeNode(1);
    Tree2->left = new TreeNode(2);
    Tree2->right = new TreeNode(2);
    Tree2->left->right =new TreeNode(3);
    Tree2->right->right =new TreeNode(3);

    if(isSymmetric(Tree1)) cout << "Tree1 is symmetric!" << endl;
    else cout << "Tree1 is not symmetric!" << endl;
    if(isSymmetric(Tree2)) cout << "Tree2 is symmetric!" << endl;
    else cout << "Tree2 is not symmetric!" << endl;


    cout << "all paths from root of Tree1 to leaf: "<< endl;
    cout << binaryTreePaths(Tree1) << endl;

    cout << "all paths from root of Tree2 to leaf: "<< endl;
    cout << binaryTreePaths(Tree2) << endl;

  //if(hasPathSum(Tree1, 6)) cout<< "true" << endl;
  //printPostorder(Tree1);
    mirror(Tree2);
    int x = getInteger();
	return 0;
}




