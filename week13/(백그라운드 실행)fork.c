#include <stdio.h>
#include <unistd.h>

int gval=10;
int main(int argc, char *agrv[])
{
	pid_t pid;
	int lval=20;
	gval++, lval+=5;

	pid=fork();
	if(pid==0)  // if Child Process
		gval+=2, lval+=2;
	else        // if Parent Process
		gval-=2, lval-=2;

	if(pid==0)
		printf("Child Proc: [%d, %d] \n", gval, lval);
	else
		printf("Parent Proc: [%d, %d] \n", gval, lval);

	sleep(10);

	return 0;
}


// gcc fork.c -o fork

// ./fork &         → 백그라운드 실행

// 실행 결과
// [1] 46502
// week13 % Parent Proc: [9, 23]  : 알아서 실행
// Child Proc: [13, 27]
// (기다림)
// [1]  + done       ./fork
