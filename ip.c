#include <stdio.h>
#include <arpa/inet.h>
int main(void)
{
    unsigned long addr = 0x12345678;
    unsigned char * p = (unsigned char *)&addr;
    printf("%0x%x%x%x\n", p[0], p[1], p[2], p[3]);
    unsigned long addr1 = htonl(addr);
    p = (unsigned char *)&addr1;
    printf("%x %x %x %x\n", p[0], p[1], p[2], p[3]);
    printf("%u\n", inet_addr("192.168.0.1"));
    struct in_addr add;
    add.s_addr = inet_addr("192.168.0.1");
    printf("%s\n", inet_ntoa(add));
    return 0;
}
