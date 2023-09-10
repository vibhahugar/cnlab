#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define bucketSize 512

void bktInput(int a, int b) {
    if (a > bucketSize)
        printf("\n\t\tBucket overflow");
    else {
        usleep(500000); // Sleep for 500 milliseconds
        while (a > b) {
            printf("\n\t\t%d bytes outputted.", b);
            a -= b;
            usleep(500000); // Sleep for 500 milliseconds
        }
        if (a > 0)
            printf("\n\t\tLast %d bytes sent\t", a);
        printf("\n\t\tBucket output successful");
    }
}

int main() {
    int op, pktSize,i;
    srand(time(NULL));

    printf("Enter output rate : ");
    scanf("%d", &op);

    for (i = 1; i <= 5; i++) {
        usleep(rand() % 1000000); // Sleep for a random time up to 1 second
        pktSize = rand() % 1000;
        printf("\nPacket no %d\tPacket size = %d", i, pktSize);
        bktInput(pktSize, op);
    }

    return 0;
}
