#include <stdio.h>
#include <stdlib.h>

typedef char DataType;
typedef struct BNode{
	DataType data;
	struct BNode* left;
	struct BNode* right;
}BNode;

//ABD##E#H##CF##G##

BNode* creatBTree(DataType arr[], int* idx){
	if (arr[*idx] == '#'){
		(*idx)++;
		return NULL;
	}
	else{
		//������ǰ����Ϊ��������
		BNode* root = (BNode*)malloc(sizeof(BNode));
		root->data = arr[*idx];
		++(*idx);

		root->left = creatBTree(arr, idx);
		root->right = creatBTree(arr, idx);
		return root;
	}
}

void preOrder(BNode* root){
	//ǰ��   ��  ��  ��
	if (root){
		printf("%c ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}

}

void inOrder(BNode* root){
	//����   ��  ��  ��
	if(root){
		inOrder(root->left);
		printf("%c ", root->data);
		inOrder(root->right);
	}

}


void postOrder(BNode* root){
	//����   ��  ��  ��
	if (root){
		postOrder(root->left);
		postOrder(root->right);
		printf("%c ", root->data);
	}
}

//�ڵ����
int bTreeSize(BNode* root){
	if (root == NULL){
		return 0;
	}
	//������+������+1
	return bTreeSize(root->left) + bTreeSize(root->right) + 1;
}

void bTreeSize2(BNode* root, int* idx){
	if (root){
		++(*idx);
		bTreeSize2(root->left,idx);
		bTreeSize2(root->right,idx);
	}
}


int bTreeLeafSize(BNode* root){
	if (root == NULL){
		return 0;
	}
	//����������Ҷ�Ӻ�
	else if (root->left == NULL&&root->right == NULL){
		return 1;
	}
	return bTreeLeafSize(root->left) + bTreeLeafSize(root->right);

}


int bTreeKSize(BNode* root,int k){
	//����������k-1��Ľڵ��
	if (root == NULL){
		return 0;
	}
	if (k == 1){
		return 1;
	}
	return bTreeKSize(root->left, k - 1) + bTreeKSize(root->right, k - 1);
}

BNode* bTreeFind(BNode* root, DataType ch){
	if (root == NULL){
		return NULL;
	}
	if (root->data == ch){
		return root;
	}
	BNode* node = bTreeFind(root->left, ch);
	if (node){
		return node;
	}
	return bTreeFind(root->right, ch);
}

void bTreeDestroy(BNode** root){
	if (*root){
		bTreeDestroy(&((*root)->left));
		bTreeDestroy(&((*root)->left));
		free(*root);
		*root = NULL;
	}
}
void bTreeDestroy2(BNode* root){
	if (root){
		bTreeDestroy2(root->left);
		bTreeDestroy2(root->left);
		free(root);
		root = NULL;
	}
}
int main()
{
	BNode root;
	int count  = 0;
	bTreeSize2(&root, &count);
}


