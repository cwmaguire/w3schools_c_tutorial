#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct {
  char fmt[3];
  char desc[30];
} Format;

int main(){
  time_t current;
  time(&current);
  printf("Time: %s\n", ctime(&current));

  Format f[20]  = {{"%a", "Abbreviated week day"},
                   {"%A", "Day of week"},
                   {"%b", "Abbrevaited month"},
                   {"%B", "Month"},
                   {"%c", "Preferred date and time"},
                   {"%C", "Century"},
                   {"%d", "Day of month"},
                   {"%D", "M/d/y"},
                   {"%e", "Day of month with space"},
                   {"%E", "?"},
                   {"%F", "M-D-Y"},
                   {"%G", "Year"},
                   {"%g", "year w/o century"},
                   {"%H", "24 hour"}};
                   // etc.

  struct tm *t = localtime(&current); // could also do `time(NULL);`
  char formatted_date[50];
  size_t size;
  char pad[30] = "                             ";
  char padding[30];
  int pad_amount = 0;
  for(int i = 0; i < 14; i++){
    size = strftime(formatted_date, 50, f[i].fmt, t);
    pad_amount = sizeof(padding) - strlen(f[i].desc);
    strncpy(padding, pad, pad_amount);
    padding[pad_amount] = '\0';
    // printf("length desc: %li; "
    //        "length padding: %li; "
    //        "sizeof(padding): %li"
    //        "padding: **%s**\n",
    //        strlen(f[i].desc),
    //        sizeof(padding) - strlen(f[i].desc),
    //        sizeof(padding),
    //        padding);
    printf("%s - %s:%s%s; (%li)\n", f[i].fmt, f[i].desc, padding, formatted_date, size);
  }

  printf("\n\n");
  printf("Year: %i\n", t->tm_year);

  return 0;
}
