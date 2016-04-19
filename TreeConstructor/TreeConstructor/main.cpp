//
//  main.cpp
//  TreeConstructor
//
//  Created by zsy on 16/4/17.
//  Copyright © 2016年 zsy. All rights reserved.
//

#include <iostream>

using namespace std;

struct node{
    int value;
    node* left;
    node* right;
    node(int val):value(val),left(NULL),right(NULL){}
};

node* constructTree(int* preArray, int* midArray, const int& arraySize,int& preIdx, int midFrontIndx, int midEndIndx){
    if (midFrontIndx > midEndIndx || preIdx >= arraySize) {
        return NULL;
    }
    node* head = new node(preArray[preIdx]);
    int index = 0;
    while (midArray[index] != preArray[preIdx]) {
        ++index;
    }
    preIdx = preIdx+1;
    head->left = constructTree(preArray,midArray,arraySize,preIdx,midFrontIndx,index-1);
    head->right = constructTree(preArray,midArray,arraySize,preIdx,index+1,midEndIndx);
    
    return head;
}

void postTraversal(node* root){
    if (root == NULL) {
        return;
    }
    postTraversal(root->left);
    postTraversal(root->right);
    cout << root->value << ",";
}

void preTraversal(node* root){
    if (root == NULL) {
        return;
    }
    cout << root->value << ",";
    preTraversal(root->left);
    preTraversal(root->right);
}

void midTraversal(node* root){
    if (root == NULL) {
        return;
    }
    midTraversal(root->left);
    cout << root->value << ",";
    midTraversal(root->right);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    int preArray[] = {1,2,4,7,3,5,6,8};
    int midArray[] = {4,7,2,1,5,3,8,6};
    int preIdx = 0;
    
    node* root = constructTree(preArray,midArray,8,preIdx,0,7);
//    preTraversal(root);
    midTraversal(root);
//    postTraversal(root);
    
    return 0;
}
