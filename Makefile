CC = gcc
COMPILER_FLAGS = -c -I 
.SILENT:
# <End product>: <Neccessary components>
# <Actions to perform to make it>

TARGET:exe clean

binaries: 
	@mkdir binaries
	@mkdir libs

dll.o: dll.c
	@$(CC) $(COMPILER_FLAGS) . dll.c -o binaries/dll.o

dll_util.o: dll_util.c
	@$(CC) $(COMPILER_FLAGS) . dll_util.c -o binaries/dll_util.o

libdll.a: dll.o dll_util.o
	@ar rs libs/libdll.a binaries/dll.o binaries/dll_util.o

application.o: application.c 
	@$(CC) $(COMPILER_FLAGS) binaries application.c -o binaries/application.o

exe:binaries application.o libdll.a
	@$(CC) binaries/application.o -o exe -L . libs/libdll.a -ldll 
	@echo Build successful

clean:
	@rm -r ./binaries/
	@rm -r ./libs/