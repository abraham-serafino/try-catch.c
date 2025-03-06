#ifndef _AMS_TRYCATCH_H_
#define _AMS_TRYCATCH_H_

#include <setjmp.h>

typedef enum exception_t {
    None
} ExceptionType;

typedef struct {
    int type;
    char* message;
} Exception;

jmp_buf _buffer;

#define TRY \
    Exception* currentException = (Exception*) setjmp(_buffer); \
    if (currentException == 0 || currentException->type == None)

#define CATCH(t) \
	if (currentException != 0 && currentException->type == t)

#define FINALLY ;

#define THROW(e) longjmp(_buffer, (int) e)

#endif # _AMS_TRYCATCH_H_

Exception* new_Exception(ExceptionType type, char* message) {
    Exception* e = malloc(sizeof(Exception) + sizeof(message));
    e->type = type;
    e->message = message;

    return e;
}
