#include <stdio.h>
#include <arpa/inet.h>

int main(int argc, char *argv[])
{
        char *addr1="1.2.3.4";
        char *addr2="1.2.3.256";

        unsigned long conv_addr=inet_addr(addr1);
        if(conv_addr==INADDR_NONE)
                printf("Error occured! \n");
        else
                printf("Network ordered integer addr: %#lx \n", conv_addr);

        conv_addr=inet_addr(addr2);
        if(conv_addr==INADDR_NONE)
                printf("Error occureded \n");
        else
                printf("Network ordered integer addr: %#lx \n\n", conv_addr);
        return 0;
}


// gcc inet_addr.c -o addr

// ./addr

// 실행 결과
// Network ordered integer addr: 0x4030201
// Error occureded
