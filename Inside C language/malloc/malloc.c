#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

struct pls {
  uint32_t len;
  uint32_t refcount;
 //there are the possibility to implement: #ifdef PLS_DEBUG ... #endif to save bytes 
  uint32_t magic;
  char str[]; //C99
};

/*First encaunter with the malloc() function and data struct. */

/*Initialize a prefixed lenght string with the specified
string in 'init' of lenght 'len'.

The created strings have the following layout:

+----+----+-------------///
|LLLL|CCCC|My strings here
+----+----+------------///

Where L is one unsigned byte statig the total length of the string.
Thus this strings are binary safe: zero bytes are permitted in the
middle. C is refernces counter

Warning: this function does not check for buffer overflows. */

char *ps_create(char *init, int len) {
  struct pls *p = malloc(sizeof(struct pls)+len+1);
  p->len = len;
  p->refcount = 1;
  p->magic = 0xDEADBEEF;
  for (int j = 0; j < len; j++) {
    p->str[j] = init[j]; //We should use memcpy() here.
  }
  p->str[len] = 0;
  return p->str;
}

/*Display the string 's' on the screen. */
void ps_print(char *s) {
  struct pls *p = (struct pls*)(s - sizeof(*p));
  for (size_t j = 0; j < p->len; j++) {
    putchar(p->str[j]);
  }
  putchar('\n');
}

/* Free a previously created PS string. */
void ps_free(char *s) {
  free(s-sizeof(struct pls));
}

/* Validate that a PS string look valid. */
void ps_validate(struct pls *p) {
  if(p->magic != 0xDEADBEEF) {
    printf("INVALID STRING: Aborting\n");
    exit(1);
  }
} 

/* Drop the reference count of the string object by one
  and frees the object if the refcount reached 0. */
void ps_relese(char *s) {
  struct pls *p = (struct pls*)(s - sizeof(*p));
  ps_validate(p);

  p->refcount--;
  if(p->refcount == 0) {
    p->magic = 0;
    ps_free(s);
  }
} 

/* Increse the reference count of the string object. */
void ps_retain(char *s) {
  struct pls *p = (struct pls*)(s - sizeof(*p));
  if(p->refcount == 0) {
    printf("ABORTED ON RETAIN OD ILLEGAL STRING\n");
    exit(1);
  }
  p->refcount++;
}

/* Return the length of  the string in 0(1) time. */
uint32_t ps_len(char *s) {
    struct pls *p = (struct pls*)(s - sizeof(*p));
    return p->len;
}

char *global_string; 

int main(void) {
  char *mystr = ps_create("Hello WorldHello WorldHello World", 33);
  global_string = mystr;
  ps_retain(mystr);

  ps_print(mystr);
  ps_print(mystr);
  printf("%s %d\n", mystr, (int)ps_len(mystr));
  ps_relese(mystr);
  printf("%s \n", global_string);
  ps_relese(mystr); 
  return 0;
}
