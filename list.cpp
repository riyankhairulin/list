#include <iostream>
#include <string.h>
using namespace std;
struct Node{
    int a;
    Node* next;
};

//void addNode(Node** root, Node* node){
//    while( (*root)->next != NULL) ){
//	Node curr_node;
//	memcpy
//	
//    }
//}

void printTrees(Node** root){
    Node* pNode = *root;
    while(pNode->next != NULL){
	cout << "i: " << pNode->a << endl;
	pNode = pNode->next;
    }
}

void retare(Node** root){
    Node* oldRoot = *root;
    Node* pMain = *root;
    Node* pTemp = NULL;
    do{
	pTemp = pMain->next;
	Node* p = pTemp->next;
	pTemp->next = pMain;
	pMain = p;
    }while(pMain->next != NULL);
    oldRoot->next = NULL;
    (*root) = pMain;
}

int main(){
    Node* p_root = new Node;
    Node* main_root = p_root;
    //p_root->node = NULL;
    for(int a = 0; a < 3; a++){
	p_root->a = a;
	if(a < 3){
		Node* p_next_node = new Node;
		p_root->next = p_next_node;
		p_root = p_next_node;
	}else{
	    p_root->next = NULL;
	}
    }
    printTrees(&main_root);
    retare(&main_root);
    printTrees(&main_root);


    return 0;
}