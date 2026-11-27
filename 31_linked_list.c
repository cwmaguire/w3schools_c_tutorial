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

Link *link_new(Type, void *);
void link_free(Link *);
void list_free(Link *);
Link *str_link(char *);
Link *int_link(int *);
Link *char_link(char *);
Link *new_link(Type, void *);

int main(){
 
  char *v1 = "foo";
  int v2 = 99;
  char v3 = 'a';

  printf("%p - v1 pointer to char *\n", v1);
  Link *link = link_new(STR, v1);

  printf("%p - link\n", (void *)link);
  printf("%p - link->val\n", link->val);
  printf("%s - link->val\n", (char *)link->val);

  Link *link2 = link_new(INT, (void *) &v2);
  link->next = (void *)link2;

  Link *link3 = link_new(CHAR, (void *) &v3);
  ((Link *)link->next)->next = (void *)link3;
  //link_append(link, link_new(CHAR, v3));
  
  Link *next = link;
   while (next != NULL){
    if(next->t == STR){
      printf("value: %s\n", (char *)next->val);
    }else if(next->t == INT){
      printf("value: %i\n", *(int *)next->val);
    }else if(next->t == CHAR){
      printf("value: %c\n", *(char *)next->val);
    }else{
      printf("Type doesn't match: %i\n", next->t);
    }
    next = next->next;
  }

  list_free(link);

  return 0;
}


Link *link_new(Type t, void *val){
  switch(t){
    case STR:
      return str_link((char *)val);
      break;
    case INT:
      return int_link((int *)val);
      break;
    case CHAR:
      return char_link((char *)val);
      break;
  }
  return NULL;
}

Link *str_link(char *s){
  size_t size = strlen(s) + 1;
  char *new_str = malloc(size);
  strcpy(new_str, s);            // copies the NULL, but I don't think we have one
  new_str[size] = '\0'; // pop the NULL on the end
  return new_link(STR, (void *)new_str);
}

Link *int_link(int *i){
  int *new_int = malloc(sizeof(int));
  *new_int = *i;
  return new_link(INT, (void *)new_int);
}

Link *char_link(char *c){
  char *new_char = malloc(sizeof(char));
  *new_char = *c;
  return new_link(CHAR, (void *)new_char);
}

Link *new_link(Type t, void *val){
  Link *new = malloc(sizeof(Link));
  *new = (Link){.val = val, .t = t, .next = NULL};
  return new;
}

void link_free(Link *link){
  printf("%p - Freeing value\n", link->val);
  free(link->val);
  printf("%p - Freeing link\n", (void *)link);
  free(link);
}

void list_free(Link *link){
  if(link->next != NULL){
    list_free((Link *)link->next);
  }
  link_free(link);
}

