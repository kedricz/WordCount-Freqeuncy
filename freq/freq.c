#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node 
{
  char *word;
  int count;
  struct node *left;
  struct node *right;

}node; // end struct


// Add node function
node *addNode(node *p, char *w)
{ 
  if(p == NULL)
    {
      node *temp;
      temp = (node*)malloc(sizeof(node));      
      temp->word = strdup(w);  
      temp->count = 1;
      temp->left = temp->right = NULL;
      return temp;
    }
  
  else if(strcmp(w, (p->word)) > 0)
    p->right = addNode(p->right, w);


  else if(strcmp(w, (p->word)) < 0)
    p->left = addNode(p->left, w);


  // if the word is in the tree
  else
    p->count++;

  return p;

} // end addNode function



// Print the tree in-order
void printInorder(struct node *p)
{
  if(p != NULL)
    {
      printInorder(p->left);
      printf("%d %s\n", p->count, p->word);
      printInorder(p->right);
    }
    
} // end printInorder






int main(int argc, char* argv[])
{
  node *root;
  root = NULL;

  int i;
 
  if(argc > 1)
    {

      for(i = 1; i < argc; i++)
	{
	  root = addNode(root, argv[i]);
	}


      printInorder(root);

    }

  else 
    printf("%s\n", "no word");

  return 0;

} // end main()
