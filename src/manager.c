#include "utils.c"

/**************************************************************************
 * Project                : SSOOII Practice 1
 * 
 * 
 * Program Name           : manager.c
 * 
 * 
 * Author                 : Álvaro Cerdá
 * 
 * 
 * Date Created           : 17/02/2021
 * ************************************************************************/



/*************************** Process Management **************************/
void install_signal_handler();
void signal_handler(int sig);
pid_t create_single_process(char *path, char *str_process_class, const char *arg);
void logFile(char message[]);
void readPipe(int fd[]);
void createPD();






/*************************** Main Function **************************/

int main()
{

   pid_t pidA, pidB, pidC;
   int status;

   int fd[2];
   char buffer[256];

   install_signal_handler(SIGINT, install_signal_handler);

   /*PA process creation, waiting for completion and log writing*/
   logFile("*********** System Log *************\n");
   pidA = create_single_process(pathPA, classPA, NULL);
   waitpid(pidA, &status, 0);
   logFile("Directory creation finished.\n");

   pipe(fd);
   sprintf(buffer, "%i", fd[P_WRITE]);

   /*Create PB and PC */
   pidB = create_single_process(pathPB, classPB, NULL);
   pidC = create_single_process(pathPC, classPC, buffer);

   /* Waiting for PB completion and log writing */
   waitpid(pidB, &status, 0);
   logFile("Copying of examination models, finalised.\n");

   /*Waiting for PC completion and log writing*/
   waitpid(pidC, &status, 0);
   logFile("Creation of files with the grade necessary to reach the cut-off mark, finalised.\n");

   /*Pipe reading and channel closure*/
   readPipe(fd);
	close(fd[P_READ]);
	close(fd[P_WRITE]);

   logFile("********** END OF PROGRAM **********\n");

   return EXIT_SUCCESS;
}








/*************************** Process Management **************************/

void signal_handler(int sig) 
{
   switch (sig)
   {
      case SIGINT:
         printf("\n[MANAGER]: Program termination (Ctrl + C).\n");

         createPD();

         exit(EXIT_SUCCESS);
    }
}

void install_signal_handler()
{
   if (signal(SIGINT, signal_handler) == SIG_ERR)
   {
      fprintf(stderr, "\n[MANAGER %d]: Error installing handler: %s.\n", 
	      getpid(), strerror(errno));    
      exit(EXIT_FAILURE);
   }
}

/*Opening and writing a log file*/
void logFile(char message[])
{
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

/*Pipe reading through channel 0*/
void readPipe(int fd[])
{
	char text[1024] = "The average students grade result is:";
   char buffer[256] = "";
	
	if(read(fd[0], buffer, sizeof(buffer)+1) == -1){
      printf("Pipe reading error\n");
   }
	sprintf(text,"%s %s \n",text, buffer);
   logFile(text);
}


pid_t create_single_process(char *path, char *str_process_class, const char *arg)
{
    
    pid_t pid;

    switch(pid = fork()){

      case -1:
         fprintf(stderr, "[MANAGER]: Error creating %s process: %s. \n", str_process_class, strerror(errno));
         exit(EXIT_FAILURE);

         /*Child Process*/
      case 0:
         if(execl(path, str_process_class, arg, NULL) == -1){
            fprintf(stderr, "[MANAGER]: Error using execl() in %s process: %s. \n", str_process_class, strerror(errno));
            exit(EXIT_FAILURE);
         }
    }
    

   /* Parent process */
    printf("[MANAGER]: %s process created.\n", str_process_class);
    sleep(1);
    return pid;
}


void createPD()
{
   pid_t pd;
   pd = create_single_process(pathPD, classPD, NULL);

   if(pd == -1){
      fprintf(stderr, "[MANAGER]: Error creating PD process: %s.\n", strerror(errno));
      exit(EXIT_FAILURE);
   }

   wait(NULL);
   logFile("A voluntary interruption has taken place by Ctrl+C. The directory containing student data has been deleted.\n");
}




