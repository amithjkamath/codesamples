#include <stdio.h>

int main(int argc, char *argv[])
{
    char *ptr = (char*)malloc(10);

    if(NULL == ptr)
    {
        printf("\n Malloc failed \n");
        return -1;
    }
    else if(argc == 1)
    {
        printf("\n Usage  \n");
    }
    else
    {
        memset(ptr, 0, 10);

        strncpy(ptr, argv[1], 9);

        while(*ptr != 'z')
        {
            if(*ptr == '\0')
                break;
            else
                ptr++;
        }

        if(*ptr == 'z')
        {
            printf("\n String contains 'z'\n");
            // Do some more processing
        }

       free(ptr);
    }

	printf("%d");
    return 0;
}