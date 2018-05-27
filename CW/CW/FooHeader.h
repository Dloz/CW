#pragma once
#include "stdafx.h"
#include <stdio.h>
#include <cstdlib>
#include "Node.h"
void deleteTree(Node*);
void doubleTree(Node*);
bool isBST(Node*, Node*, Node*);
bool isSumTree(Node*);
Node* newNode(int);
void printInorder(Node*);
void printPostorder(Node*);
void printPreorder(Node*);
int size(Node*);
int sum(Node*);