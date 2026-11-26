#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum {
  INT,
  STR,
  CHAR
} Type;

typedef struct {
  void *val;
  Type t;
  void *next;
} Link;

typedef union {
  Link l;
  int i;
} Node;

Link *link_new(Type, void *);
void link_free(Link *);

int main(){
 
  char *v1 = "foo";
  //int v2 = 99;
  //char v3 = 'a';

  printf("%p - v1 pointer to char *\n", v1);
  Link *link = link_new(STR, v1);

  printf("%p - link\n", (void *)link);
  printf("%p - link->val\n", link->val);
  printf("%s - link->val\n", (char *)link->val);
  //link_append(link, link_new(INT, v2));
  //link_append(link, link_new(CHAR, v3));
  
  //while(node != NULL){
  //  if(list.type == STR){
  //    printf("value: %s\n", (*char)list.val);
  //  }else if(list.type == INT){
  //    printf("value: %i\n", &(*int)list.val);
  //  }else if(list.type == CHAR){
  //    printf("value: %c\n", &(*char)list.val);
  //  }
  //  node = node.l.next;
  //}

  link_free(link);

  return 0;
}

Link *link_new(Type t, void *val){
  size_t size;
  if(t == STR){
    size = (strlen((char *)val) + 1); // strlen does NOT count the NULL, so leave extra space
  }else if(t == INT){
    size = sizeof(int);
  }else if(t == CHAR){
    size = sizeof(char);
  }
  
  void *new_val = malloc(size);
  printf("%p - new val in link_new(...), size %li\n", new_val, size);

  if(t == STR){
    //new_val = (char *) val;
    strcpy(new_val, val);            // copies the NULL, but I don't think we have one
    ((char *) new_val)[size] = '\0'; // pop the NULL on the end
  }else if(t == INT){
    new_val = (int *) val;
  }else if(t == CHAR){
    new_val = (char *) val;
  }else{
    printf("Did not match type: %i\n", t);
  }

  Link *new = malloc(sizeof(Link));
  printf("%p - new Link\n", (void *)new); // why is this the same address as new_val?
  *new = (Link){.val = new_val, .t = t, .next = NULL};
  return new;
}

void link_free(Link *link){
  printf("%p - Freeing value\n", link->val);
  free(link->val);
  printf("%p - Freeing link\n", (void *)link);
  free(link);
}
