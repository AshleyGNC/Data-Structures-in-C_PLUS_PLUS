/*
 * treeFunctions.cpp
 *
 *  Created on: Apr 27, 2022
 *      Author: Ashley
 */

#include <iostream>
#include "TreeNode.h"

using namespace std;


int height(TreeNode *node) {
	if(node == nullptr){
		return 0;
	}else{
		if (height(node->left) >= height(node->right)){
			return 1 + height(node->left);
		}
		if (height(node->right) < height(node->left)){
			return 1 + height(node->right);
		}
	}
	return 0;
}

bool isBalanced(TreeNode* node){
	if(node == nullptr){
		return true;
	}else if(height(node->left) == height(node->right)){
		return true;
	}else if((height(node->left) - height(node->right)) == 1){
		return true;
	}else if((height(node->right) - height(node->left)) == 1){
		return true;
	}else{
		return false;
	}
	return isBalanced(node->left);
	return isBalanced(node->right);

}


int main(){
    /*            9
     *          /   \
     *        6       14
     *       / \     / \
     *     -3   7  11   19
     *     /
     *   -5
     */
    TreeNode* Tree1 = new TreeNode(9);
    Tree1->left = new TreeNode(6);
    Tree1->right = new TreeNode(14);
    Tree1->left->left =new TreeNode(-3);
    Tree1->left->right =new TreeNode(7);
    Tree1->right->left =new TreeNode(11);
    Tree1->right->right =new TreeNode(19);
    Tree1->left->left->left =new TreeNode(-5);


    /*         9
     *       /   \
     *     6       14
     *    /         \
     *  -3           19
     *  /             \
     * -5             11
     */
    TreeNode* Tree2 = new TreeNode(9);
    Tree2->left = new TreeNode(6);
    Tree2->right = new TreeNode(14);
    Tree2->left->left =new TreeNode(-3);
    Tree2->right->right =new TreeNode(19);
    Tree2->left->left->left =new TreeNode(-5);
    Tree2->right->right->right =new TreeNode(11);

    cout << "The height of Tree1 is " << height(Tree1) << endl;
    cout << "The height of Tree2 is " << height(Tree2) << endl;
    if(isBalanced(Tree1)) cout << "Tree1 is balanced!" << endl;
    else cout << "Tree1 is not balanced!" << endl;
    if(isBalanced(Tree2)) cout << "Tree2 is balanced!" << endl;
    else cout << "Tree2 is not balanced!" << endl;

	return 0;
}
