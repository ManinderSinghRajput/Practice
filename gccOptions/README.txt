GCC compiles a C/C++ program into executable in 4 steps as shown in the above diagram. For example, a "gcc -o hello.exe hello.c" is carried out as follows:

Pre-processing: via the GNU C Preprocessor (cpp.exe), which includes the headers (#include) and expands the macros (#define).
> cpp hello.c > hello.i
The resultant intermediate file "hello.i" contains the expanded source code.
Compilation: The compiler compiles the pre-processed source code into assembly code for a specific processor.
> gcc -S hello.i
The -S option specifies to produce assembly code, instead of object code. The resultant assembly file is "hello.s".
Assembly: The assembler (as.exe) converts the assembly code into machine code in the object file "hello.o".
> as -o hello.o hello.s
Linker: Finally, the linker (ld.exe) links the object code with the library code to produce an executable file "hello.exe".
> ld -o hello.exe hello.o ...libraries...

