#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>

/* Total number of processes */
int g_nProcesses;

/*************************** Process Management **************************/
void install_sighandler();
void signal_handler(int sig);








/*************************** Main Function **************************/

int main(){
    install_signal_handler(SIGINT, install_signal_handler);
}








/*************************** Process Management **************************/

void signal_handler(int sig) 
{
   switch (sig)
   {
      case SIGINT:
         printf("[MANAGER %d] terminated (SIGINT).\n", getpid());
         printf("\n[MANAGER] Program termination (Ctrl + C).\n");

         exit(EXIT_SUCCESS);
    }
}

void install_signal_handler()
{
   if (signal(SIGINT, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "[MANAGER %d] Error installing handler: %s.\n", 
	      getpid(), strerror(errno));    
      exit(EXIT_FAILURE);
   }
}

pid_t create_single_process(){
    
}




