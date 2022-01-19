#include <stdio.h>
#include <stdlib.h>

typedef struct tree_ TREE;
typedef struct node_ST NODE;

struct node_ST{
    int value;
    NODE *left;
    NODE *right;
};

struct tree_{
    NODE* root;
    int depth;
};

TREE *createBinaryTree ();
NODE *insertNodeInTree(NODE *root, int value);
int findValueInTree(TREE *tree, int value);
int findValue(NODE *root, int value);
void insertValueInTree(TREE *tree, int value);
void shuffle(int *array, size_t n);

int main(void) {
  unsigned long n;
  scanf("%lu",&n);
  TREE *tree = createBinaryTree();
  int *vetAux = malloc(sizeof(int)*n);
  for(int i = 0; i < n; i++){
    scanf("%d",&vetAux[i]);
  }
  shuffle(vetAux,n);
  for(int i = 0; i < n; i++){
    insertValueInTree(tree, vetAux[i]);
  }
  unsigned long nFind;
  scanf("%lu",&nFind);
  int findValue;
  for(int i = 0; i < nFind; i++){
    scanf("%d",&findValue);
    printf("%d\n",findValueInTree(tree,findValue));
  }
  return 0;
}

TREE *createBinaryTree (){
    TREE *binaryTree;
    binaryTree = (TREE *) malloc(sizeof(TREE));

    if (binaryTree != NULL){
        binaryTree->root = NULL;
        binaryTree->depth = -1;
        return binaryTree;
    }
    return NULL;
}

void insertValueInTree(TREE *tree, int value){
    tree->root = insertNodeInTree(tree->root,value);
}

NODE * insertNodeInTree(NODE *root, int value){
    if(root == NULL){
        NODE *auxNode = (NODE*)malloc(sizeof(NODE));
        auxNode->value = value;
        auxNode->left = NULL;
        auxNode->right = NULL;
        return auxNode;
    }
    else{
        if(root->value < value){
            root->right = insertNodeInTree(root->right, value);
        } 
        if(root->value > value){
            root->left = insertNodeInTree(root->left, value);
        }
        return root;
    }
}

int findValueInTree(TREE *tree, int value){
    return findValue(tree->root,value);
}

int findValue(NODE *root, int value){
  if(root != NULL){
    if(root->value == value){
      return 1;
    }
    else if(root->value < value){
      return findValue(root->right, value);
    }
    else{
      return findValue(root->left, value);
    }
  }
  return 0;
}

void shuffle(int *array, size_t n)
{
    if (n > 1) 
    {
        size_t i;
        for (i = 0; i < n - 1; i++) 
        {
          size_t j = i + rand() / (RAND_MAX / (n - i) + 1);
          int t = array[j];
          array[j] = array[i];
          array[i] = t;
        }
    }
}

//clear && gcc main.c -o run && ./run < .in && ./run < .in > .out