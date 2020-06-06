#include <stdio.h>
#include <stdlib.h>

//============================================================
//============================================================
//============================================================
/*
 Creating a tree structure for the exercise
*/


/*
    definition of a node in a Binary tree
    It has a value, left and right pointer
*/

struct node {
    int key;
    struct node *left, *right;
};

/*
    creating a NEW node in a Binary tree
*/
struct node *newNode(int item) {
struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

/*
    Inserting a node in a Binary tree
    (recursively)
*/
struct node* insert(struct node* node, int key) {
    if (node == NULL) return newNode(key);
    if (key < node->key)
        node->left = insert(node->left, key);
    else
        node->right = insert(node->right, key);
    return node;
}
//============================================================
//============================================================
//============================================================




/*
    SUM of EVEN elements of a BINARY TREE
    using a recursive approach
*/
int sum_Numbers(struct node *root) {
   if (root == NULL) {
     return 0;
   }
   int value = 0;
   if (root->key % 2 == 0) {
      value = root->key;
   }
   return value + sum_Numbers(root->left) + sum_Numbers(root->right);
}



/*
    MAX element of a BINARY TREE
    using a recursive approach
*/
int max_Numbers(struct node *root) {

    int maxN = -1;
    while (root != NULL) {
        maxN = root->key;
        root = root->right;
    }
   return maxN;
}


/*
    MIN element of a BINARY TREE
    using a recursive approach
*/
int min_Numbers(struct node *root) {

    int minN = -1;
    while (root != NULL) {
        minN = root->key;
        root = root->left;
    }
   return minN;
}


/*
    MAXIMUM LENGTH of a BINARY TREE
    using a recursive approach
*/
int maxDepth(struct node* node)
{
   if (node==NULL)
       return -1;
   else
   {
       /* compute the depth of each subtree */
       int lDepth = maxDepth(node->left);
       int rDepth = maxDepth(node->right);

       /* use the larger one */
       if (lDepth > rDepth)
           return(lDepth+1);
       else return(rDepth+1);
   }
}




/*
    Define a Linked List
*/
typedef struct list {
    int key;
    struct list* next;
} List;


/*
    Define a new NODE in the Linked List
*/
List* newListNode (int key) {
    List *new = malloc(sizeof(List));
    new->key = key;
    new->next = NULL;
    return new;
}

/*
    Create an ORDERED linked list from a Binary Tree
*/
List* flattenToLL(struct node *root) {
    List *list1 = (root->left) ? flattenToLL(root->left) : NULL;
    List *list2 = (root->right) ? flattenToLL(root->right) : NULL;
    List *list3 = newListNode(root->key);

    // The "middle" list3 cannot be NULL; append list2 to list3
    list3->next = list2; // If list2 is NULL, it's OK
    if (!list1) return list3; // Nothing to prepend
    List *last = list1;
    while (last->next) last=last->next; // Go to the end of list1
    last->next = list3; // Append list3+list2 to the end of list1
    return list1;
}





/*
# Binary tree  1

             3
        /        \
       1          6
        \        / \
         2      4   7
                     \

                      8


# Binary tree  2

              9
        /          \
       2            18
     /  \
   1     3
          \
           4
            \
             5
*/


int main(void)
{
    printf("Tree1:\n");
    // Creating Tree 1
    struct node *root1 = NULL;
    int data1[]={3,1,2,6,4,7,8}, n1, i1;
    n1=sizeof(data1)/sizeof(data1[0]);
    for(i1=0;i1<n1;i1++)
        root1=insert(root1,data1[i1]);

    int sumEv1 = sum_Numbers(root1);
    printf("Sum even is: %d\n", sumEv1);
    int maxN1 = max_Numbers(root1);
    printf("Max number is: %d\n", maxN1);
    int minN1 = min_Numbers(root1);
    printf("Min number is: %d\n", minN1);
    int maxLen1 = maxDepth(root1);
    printf("Max length tree is: %d\n", maxLen1);

    List* list1 = flattenToLL(root1);
    printf("Linked list with ordered numbers: ");
    while(list1!=NULL) {
    printf("%d ",list1->key);
    list1=list1->next;}
    printf("\n");
    printf("\n");


    printf("Tree2:\n");
    // Creating Tree 2
    struct node *root2 = NULL;
    int data[]={9,18,2,1,3,4,5}, n, i;
    n=sizeof(data)/sizeof(data[0]);
    for(i=0;i<n;i++)
        root2=insert(root2,data[i]);

    int sumEv = sum_Numbers(root2);
    printf("Sum even is: %d\n", sumEv);
    int maxN = max_Numbers(root2);
    printf("Max number is: %d\n", maxN);
    int minN = min_Numbers(root2);
    printf("Min number is: %d\n", minN);
    int maxLen = maxDepth(root2);
    printf("Max length tree is: %d\n", maxLen);

    List* list2 = flattenToLL(root2);
    printf("Linked list with ordered numbers: ");
    while(list2!=NULL) {
    printf("%d ",list2->key);
    list2=list2->next;}
    printf("\n");


}