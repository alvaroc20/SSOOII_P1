#include "utils.c"

pid_t pidA, pidB, pidC;
int status;

/*************************** Process Management **************************/
void install_signal_handler();
void signal_handler(int sig);
pid_t create_single_process(char *path, char *str_process_class);
void logFile(char message[]);







/*************************** Main Function **************************/

int main(){
   install_signal_handler(SIGINT, install_signal_handler);

   /*PA process creation, waiting for completion and log writing*/
   logFile("*********** System Log *************\n");
   pidA = create_single_process(pathPA, classPA);
   waitpid(pidA, &status, 0);
   logFile("Directory creation finished.\n");

   /*Create PB and PC */
   pidB = create_single_process(pathPB, classPB);
   pidC = create_single_process(pathPC, classPC);

   /* Waiting for PB completion and log writing */
   waitpid(pidB, &status, 0);
   logFile("Copying of examination models, finalised.\n");

   /*Waiting for PC completion and log writing*/
   waitpid(pidC, &status, 0);
   logFile("Creation of files with the grade necessary to reach the cut-off mark, finalised.\n");
}








/*************************** Process Management **************************/

void signal_handler(int sig) 
{
   switch (sig)
   {
      case SIGINT:
         printf("[MANAGER %d]: terminated (SIGINT).\n", getpid());
         printf("\n[MANAGER]: Program termination (Ctrl + C).\n");

         exit(EXIT_SUCCESS);
    }
}

void install_signal_handler()
{
   if (signal(SIGINT, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "[MANAGER %d]: Error installing handler: %s.\n", 
	      getpid(), strerror(errno));    
      exit(EXIT_FAILURE);
   }
}

void logFile(char message[]){
   FILE *log;
   log = fopen("log.txt", "a");

   if (log == NULL) {
      fprintf(stderr,"[MANAGER]: Error opening the log.\n");
      exit (1);
  }

   if(fprintf(log,"\n%s",message) == -1){
      fprintf(stderr,"[MANAGER] Error writing in the log.\n");
      exit (1);
  }
  fclose(log);
}

pid_t create_single_process(char *path, char *str_process_class){
    
    pid_t pid;

    switch(pid = fork()){

      case -1:
         fprintf(stderr, "[MANAGER]: Error creating %s process: %s. \n", str_process_class, strerror(errno));
         exit(EXIT_FAILURE);

         /*Child Process*/
      case 0:
         if(execl(path, str_process_class) == -1){
            fprintf(stderr, "[MANAGER]: Error using execl() in %s process: %s. \n", str_process_class, strerror(errno));
            exit(EXIT_FAILURE);
         }
    }

   /* Parent process */
    printf("[MANAGER]: %s process created.\n", str_process_class);
    sleep(1);
    return pid;
}




