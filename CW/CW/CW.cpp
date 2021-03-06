// CW.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "FooHeader.h"
#include <iostream>
#include <cmath>

int main() {
	int k;
	std::cout << "input data for root - ";
	std::cin >> k;
	std::cout << std::endl;
	Node *root = newNode(k);
	std::cout << "Choose the function: ";
	std::cout <<
		"1. Create new node\n"
		"2.	Print\n"
		"3. delete tree\n"
		"4. double current tree\n"
		"5. check current tree is binary search tree\n"
		"6. check is the current tree of sums\n"
		"7. print size of current tree\n"

		;
	int choose;
	std::cin >> choose;
	switch (choose) {
	start:
	case 1:
		int data;
		std::cout << "Input data in new node - "; std::cin >> data;
		newNode(data);
		break;
	case 2:
		int method;
		std::cout << "Choose method of printing:\n"
			"1.In order\n"
			"2.Pre order\n"
			"3.Post order\n"
			"your choose - ";
		std::cin >> method;
		std::cout << std::endl;

		switch (method) {
		label:
		case 1:
			printInorder(root);
			break;
		case 2:
			printPreorder(root);
			break;
		case 3:
			printPostorder(root);
			break;
		default:
			std::cout << "You've choosed wrong method\n"; goto label; // 37 
		}
		break;
	case 3:
		deleteTree(root);
		break;
	case 4:
		doubleTree(root);
		std::cout << "Tree doubled\n";
		break;
	case 5:
		if (isBST(root, root->left, root->right))
			std::cout << "Current tree is an binary search tree\n";
		else
			std::cout << "Current tree not an binary search tree";
		break;
	case 6:
		std::cout << (bool)isSumTree(root) << std::endl;
		break;
	case 7:
		std::cout << "Size of current tree - " << size(root) << std::endl;
	default:
		std::cout << "You've choosed wrong function\n"; goto start; // 21
		break;
	}
	system("pause");
	return 0;
}
