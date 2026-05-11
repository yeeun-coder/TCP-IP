#include <stdio.h> 
#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>

int main(void)
{
        int fd1, fd2, fd3;
        fd1=socket(PF_INET, SOCK_STREAM, 0);
        fd2=open("test.dat", O_CREAT|O_WRONLY|O_TRUNC);
        fd3=socket(PF_INET, SOCK_DGRAM, 0);

        printf("file descriptor 1: %d\n", fd1);
        printf("file descriptor 2: %d\n", fd2);
        printf("file descriptor 3: %d\n", fd3);

        close(fd1);
        close(fd2);
        close(fd3);
        return 0;
}
#int fd1, fd2, fd3; 여기에 int 타입을 묻는게 잘 나옴?

// gcc -o fds fd_seri.c 
// ./fds
// 실행 결과
//file descriptor 1: 3
// file descriptor 2: 4
// file descriptor 3: 5
// 그러면 test.dat가 생성됨
// rm test.dat : 지우기
