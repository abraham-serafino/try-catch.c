# try-catch.c
Using setjmp to implement Exception-handling in C

# Limitations
* Strange errors will occur if you use CATCH without TRY
* You have to manually "free" the exception created by new_Exception().
