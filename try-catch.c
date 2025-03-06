#include <stdlib.h>
#include <stdio.h>
#include "try-catch.h"

#define FileException 1

#define new_FileException(message) \
	new_Exception(FileException, message)

int main(void) {
    FILE* fp;
    Exception* e;

    TRY {
        fp = fopen("./myfile.txt", "w+");
        fputs("Hello world\n", fp);

        e = new_FileException("Problem writing to file.");
        THROW(e);

        printf("This message is never shown.");

    } CATCH (FileException) {
	    printf("%s\n", currentException->message);

    } FINALLY {
        fclose(fp);
        free(e);
    }
}
