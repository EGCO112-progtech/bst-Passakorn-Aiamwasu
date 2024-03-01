// An integer binary search tree

struct TreeNode
{
   struct TreeNode *leftPtr;  // pointer to left subtree
   int data;                  // node value
   struct TreeNode *rightPtr; // pointer to right subtree
};                            // end structure treeNode

typedef struct TreeNode *TreeNodePtr; // synonym for TreeNode*

typedef struct
{
   int size;
   TreeNodePtr root;
} BST;

// prototypes

void insertNode(BST *, int);
void insertNode_R(TreeNodePtr *, int);

void insertNode_R(TreeNodePtr * t,int value){
  if((*t)==NULL){
   (*t)=(TreeNodePtr)malloc(sizeof(struct TreeNode));
    if(t)
      {
         (*t)->leftPtr=NULL;
         (*t)->rightPtr=NULL;
         (*t)->data=value;
      }
      else printf("%d not inserted. No memory available.\n",value);
  }
  else
  {
     if((*t)->data>=value) insertNode_R(&(*t)->leftPtr,value);
     else insertNode_R(&(*t)->rightPtr,value);
   }
}

void insertNode(BST *b, int value)
{
   TreeNodePtr t = b->root, new_node;
   int inserted = 0;
   new_node = (TreeNodePtr)malloc(sizeof(struct TreeNode));
   if (new_node)
   {
      new_node->leftPtr = NULL;
      new_node->rightPtr = NULL;
      new_node->data = value;
   }
   /*First Node*/
   if (!b->root)
      b->root = new_node;
   else
   {
      while (!inserted)
      {
         if (t->data >= value)
         {
            if (!t->leftPtr)
            {
               t->leftPtr = new_node; // insert
               inserted = 1;
            }
            else
               t = t->leftPtr; // move
         }
         else
         {
            if (!t->rightPtr)
            {
               t->rightPtr = new_node; // insert
               inserted = 1;
            }
            else
               t = t->rightPtr; // move
         }
      } // end while
   }    // end else;
   b->size++;

} // end function

void inOrder(TreeNodePtr treePtr)
{
   // if tree is not empty, then traverse
   if (treePtr != NULL)
   {
      inOrder(treePtr->leftPtr); // Recursion to the left
      printf("%3d", treePtr->data); // print the value
      inOrder(treePtr->rightPtr); // Recursion to the right
   }                              // end if
} // end

void preOrder(TreeNodePtr treePtr)
{
   if (treePtr != NULL)
   {
      printf("%3d", treePtr->data); // print the value
      preOrder(treePtr->leftPtr); // Recursion to the left
      preOrder(treePtr->rightPtr); // Recursion to the right
   }  
}

void postOrder(TreeNodePtr treePtr)
{
   if (treePtr != NULL)
   {
      postOrder(treePtr->leftPtr); // Recursion to the left
      postOrder(treePtr->rightPtr); // Recursion to the right
      printf("%3d", treePtr->data); // print the value
   }  
}

void tree(TreeNodePtr treePtr, int x)
{
   if (treePtr != NULL)
   {
      tree(treePtr->rightPtr,x+1); // Recursion to the right
      for(int n=0;n<x*4;n++) printf("   ");
      printf("%3d\n", treePtr->data); // print the value
      tree(treePtr->leftPtr,x+1); // Recursion to the left
   }  
}