#include <stdio_ext.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>

void Eco();
void CreaHilo();
void *FuncionHilo();
void ContarSeniales();
void Salir();
void SumaSenial();
int pid,hijo1,hijo2,NHilo,bucle=1,status,nSignal=0;

int main(int argc, char *argv[])
{
	signal(SIGUSR2,Eco);

	pid = atoi(argv[1]);

	printf("Ejercicio uno...\n");
	fflush(stdout);
	__fpurge(stdin);
	getchar();
	
	kill(pid,SIGUSR1);
	sleep(5);


	printf("Ejercicio dos...\n");
	fflush(stdout);
	__fpurge(stdin);
	getchar();

	kill(pid,SIGUSR1);
	sleep(5);


	printf("Ejercicio tres...\n");
	fflush(stdout);
	__fpurge(stdin);
	getchar();

	kill(pid,SIGUSR1);
	sleep(1);
	
	if((hijo1=fork())==0)
	{
		printf("Soy el hijo 1. %d\n",getpid());
		fflush(stdout);
		/*do
		{*/
			signal(SIGUSR2,CreaHilo);
			//signal(SIGALRM,Salir);
			//pause;
		//}while(bucle=1);
		exit(status);
		
	}

	else if((hijo2=fork())==0)
	{
		printf("Soy el hijo 2. %d\n",getpid());
		fflush(stdout);
		/*do
		{*/
			signal(SIGUSR1,ContarSeniales);
			//signal(SIGALRM,Salir);
			//pause;
		//}while(bucle=1);
		exit(status);
	}

	else
		kill(pid,SIGUSR1);

	printf("Ejercicio cuatro...\n");
	fflush(stdout);
	__fpurge(stdin);
	getchar();

	printf("Ejercicio cinco...\n");
	fflush(stdout);
	__fpurge(stdin);
	getchar();

	kill(pid,SIGUSR1);

	printf("Ejercicio seis...\n");
	fflush(stdout);
	__fpurge(stdin);
	getchar();

	kill(pid,SIGUSR1);
	sleep(1);
	exit(status);
}

void Eco()
{
	kill(pid,SIGUSR1);
}

void CreaHilo()
{
    
	pthread_t IdHilo;

	NHilo++;
	pthread_create (&IdHilo, NULL, FuncionHilo, NULL);
}

void *FuncionHilo()
{
	int i,id=NHilo;
	
	for(i=0;i<5;i++)
	{
		printf("Soy el hilo %d\n",id);
		sleep(5);
	}
	
}

void Salir()
{
	bucle=0;
}

void ContarSeniales()
{
	signal(SIGUSR2,SumaSenial);

}

void SumaSenial()
{
	nSignal++;
	printf("Numero de señales recibidas: %d\n",nSignal);
	kill(pid,SIGUSR2);
}
	


