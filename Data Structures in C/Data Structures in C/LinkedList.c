#include <stdio.h>
#include <stdlib.h>

typedef struct linked_list{
	int id;
	char *swag;
	struct linked_list *next;
}List;

typedef List ** L;

typedef struct BST{
	int id;
	struct BST* left;
	struct BST* right;
}BTree;

typedef BTree* Tree;
typedef BTree ** T;

void addToList(L head, int id, char string[]){
	List* tempHead = *head;
	List* prev = NULL;
	List* tempVar = (List*)malloc(sizeof(List));
	tempVar->id = id;
	tempVar->swag = string;

	while (tempHead->next != NULL && id < tempHead->id){
		prev = tempHead;
		tempHead = tempHead->next;
	}

	tempVar->next = tempHead;

	if (prev == NULL){
		*head = tempVar;
	}
	else{
		prev->next = tempVar;
	}
}

void printList(List *head){
	List * temp = head;
	while (temp->next != NULL){
		printf("ID: %d\n", temp->id);
		temp = temp->next;
	}
	printf("crashed");
}

void addToTree(T trunk, int id){
	Tree temp = *trunk;
	Tree newNode = NULL;
	
	if (temp == NULL){
		newNode = (Tree)malloc(sizeof(BTree));
		newNode->id = id;
		newNode->left = NULL;
		newNode->right = NULL;
		*trunk = newNode;
	}
}

void inOrder(Tree trunk){
	inOrder(trunk->left);
	printf("ID: %d", trunk->id);
	inOrder(trunk->right);
}

int main(int argc, char ** argv){
	List *head = (List*)malloc(sizeof(List));

	addToList(&head, 5, "Swag");
	addToList(&head, 2, "Swag");
	addToList(&head, 7, "Swag");
	printList(head);
	system("pause");
	Tree trunk = (Tree)malloc(sizeof(BTree));
	addToTree(&trunk, 2);
	inOrder(trunk);
}