#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/sysinfo.h>
#include <sys/times.h>
#include <sys/wait.h>

/*
  /usr/include/unistd.h

  Clone the calling process, creating an exact copy.
  Return -1 for errors, 0 to the new process,
  and the process ID of the new process to the old process.

  extern __pid_t fork (void) __THROWNL;

  __pid_t = pid_t = int
*/

void use_misc(), use_posix2(), use_xopen_extended();
void get_login();
void set_login();
void get_ttyslot();
void get_hostname();
void get_domainname();
void get_host_id();
void _get_nprocs();
void _get_phys_pages();
void _get_avphys_pages();
void print_cpu_times();

int main(){

  use_misc();
  use_posix2();
  use_xopen_extended();
  get_login();
  set_login();
  get_login();
  get_ttyslot();
  get_hostname();
  get_domainname();
  get_host_id();
  _get_nprocs();
  _get_phys_pages();
  _get_avphys_pages();
  print_cpu_times();

  printf("\n");

  pid_t child_pid = fork();
  pid_t pid = getpid();
  if(child_pid == 0){
    pid_t parent_pid = getppid();
    printf("Hello from the child process: %i; I'm a child of %i\n", pid, parent_pid);
  }else{
    printf("Hello from the parent process: %i\n", pid);

    printf("Waiting for child %i\n", child_pid);
    int *stat_loc = malloc(sizeof(int));
    pid_t child = waitpid (child_pid, stat_loc, 0);
    free(stat_loc);
    printf("Child finished %i - %i\n", child_pid, child);
  }

  return 0;
}

void use_misc(){
#ifdef __USE_MISC
  printf("__USE_MISC\n");
#else
  printf("No __USE_MISC\n");
#endif
}

void use_posix2(){
#ifdef __USE_MISC
  printf("__USE_POSIX2\n");
#else
  printf("No __USE_POSIX2\n");
#endif
}

void use_xopen_extended(){
#ifdef __USE_MISC
  printf("__USE_XOPEN_EXTENDED\n");
#else
  printf("No __USE_XOPEN_EXTENDED\n");
#endif
}

void get_login(){
  char *login = getlogin();
  printf("login: %s\n", login);
}

void set_login(){
  char *login = "something_else";
  char *login2 = malloc(strlen(login));
  strcpy(login2, login);
  printf("login: %s, login2: %s\n", login, login2);
  setlogin(login2);
  free(login2);
}

void get_ttyslot(){
  // Not sure why this doesn't work
  //int ttyslot = ttyslot();
  //printf("ttyslot: %i\n", ttyslot);
  printf("ttyslot doesn't work\n");
}

void get_hostname(){
  char *hostname = malloc(100);
  gethostname(hostname, 100);
  printf("Hostname: %s\n", hostname);
  free(hostname);
}

void get_domainname(){
  char *domainname = malloc(100);
  getdomainname(domainname, 100);
  printf("Domainname: %s\n", domainname);
  free(domainname);
}

void get_host_id(){
  printf("Host ID: %li\n", gethostid());
}

void _get_nprocs(){
  printf("Nprocs: %i\n", get_nprocs()); 
}

void _get_phys_pages(){
  printf("Physical pages: %li\n", get_phys_pages()); 
}

void _get_avphys_pages(){
  printf("Available physical pages: %li\n", get_avphys_pages()); 
}

void print_cpu_times(){
  struct tms *t;
  t = malloc(sizeof(struct tms));
  clock_t ts = times(t);
  printf("User CPU time: %li\n", ts);
  printf("User CPU time: %li\n", t->tms_utime);
  printf("System CPU time: %li\n", t->tms_stime);
  printf("User CPU time of dead children: %li\n", t->tms_cutime);
  printf("System CPU time of dead children: %li\n", t->tms_cstime);
  free(t);


}

/*
Structure describing CPU time used by a process and its children.
struct tms
  {
    clock_t tms_utime;		User CPU time.
    clock_t tms_stime;		System CPU time.

    clock_t tms_cutime;		User CPU time of dead children.
    clock_t tms_cstime;		System CPU time of dead children.
  };

   Store the CPU time used by this process and all its
   dead children (and their dead children) in BUFFER.
   Return the elapsed real time, or (clock_t) -1 for errors.
   All times are in CLK_TCKths of a second.

extern clock_t times (struct tms *__buffer) __THROW;
*/
