# This Makefile will build the MinGW Win32 application.

# Object files to create for the executable
OBJS = obj/clock.o obj/winmain.o obj/wndproc.o

# Warnings to be raised by the C compiler
WARNS = -Wall

# Names of tools to use when building
CC = g++
RC = windres
EXE = Win32App.exe

# Compiler flags. Compile ANSI build only if CHARSET=ANSI.
ifeq (${CHARSET}, ANSI)
	CFLAGS = -O2 -D _WIN32_IE=0x0500 -D WINVER=0x0500 ${WARNS} -Iinclude
else
	CFLAGS = -O2 -D UNICODE -D _UNICODE -D _WIN32_IE=0x0500 -D WINVER=0x0500 ${WARNS} -Iinclude
endif

# Linker flags
LDFLAGS = -s -lgdi32 -Wl,--subsystem,windows

.PHONY: all clean

# Build executable by default
all: bin/${EXE}

# Delete all build output
clean:
	if exist bin\${EXE}  del /q bin\${EXE}
	if exist obj\*  del /q obj\*

# Create build output directories if they don't exist
bin obj:
	@if not exist "$@" mkdir "$@"

# Compile object files for executable
obj/%.o: src/%.cpp | obj
	${CC} ${CFLAGS} -c "$<" -o "$@"

# Build the exectuable
bin/${EXE}: ${OBJS} | bin
	${CC} -o "$@" ${OBJS} ${LDFLAGS}