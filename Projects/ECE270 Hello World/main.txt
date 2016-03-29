#include <stdio.h>
#include <stdlib.h>

int main()
{
    //wipe some dust off the cover
    printf("Hello world!\n");
    //actually shaking some of the dust out from between the pages
    int stuff1,stuff2;
    long int stuff3=0;

    do{
        printf("Enter a number between ~ -32,000 and 32,000\n");
        scanf("\n%d",&stuff1);
        stuff2=(stuff1*3+5);
        stuff3=(stuff1*stuff2);
        printf("\n%d\n%d\n%ld\n",stuff1,stuff2,stuff3);
    }while(stuff3<6000);
    getch();

    //Apparently the dev is not so dusty as he once supposed

    return 0;
}
