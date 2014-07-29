#include <stdio.h>
#include <string.h>

#define SIZE 1
#define NUMELEN 5
int main()
{
	FILE *fd = NULL;
	
	char buff[100];
	memset(buff, 0, sizeof(buff));

	fd = fopen("test.txt", "rw+");
	if (NULL == fd){
		printf(" fopen() error \n");
		return 1;
	}
printf("\n file opened successfully through fopen()\n");

if (SIZE* NUMELEN != fread(buff, SIZE, NUMELEN, fd)){
	printf(" failed\n");
	return 1;
}

printf("some bytes read through fread\n");

printf("\n The bytes read are [%s]\n",buff);

    if(0 != fseek(fd,10,SEEK_CUR))
    {
        printf("\n fseek() failed\n");
        return 1;
    }

    printf("\n fseek() successful\n");

    if(SIZE*NUMELEN != fwrite(buff,SIZE,strlen(buff),fd))
    {
        printf("\n fwrite() failed\n");
        return 1;
    }

    printf("\n fwrite() successful, data written to text file\n");

    fclose(fd);

    printf("\n File stream closed through fclose()\n");

    return 0;

}


