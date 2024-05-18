# Compiler and Compiler Flags
CC=gcc
CFLAGS=-Wall -g -Iinclude
# Linker flags
LDFLAGS=-lpthread -lreadline

# The build target executable:
TARGET=minios

# Source, Object files
SRCS=kernel/kernel.c kernel/system.c kernel/20211089/ipc.c kernel/20211089/est_pi.c kernel/20211089/round_robin.c kernel/syscalls/sys_fork.c kernel/syscalls/sys_exec.c kernel/syscalls/sys_abort.c kernel/syscalls/sys_exit.c kernel/syscalls/sys_waitpid.c kernel/20211089/createfile.c kernel/event_control/wait_time.c kernel/event_control/wait_event.c kernel/event_control/signal_event.c kernel/event_control/event_control.c
OBJS=$(SRCS:.c=.o)

# Include directory
INCLUDE_DIR=include

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET)

# Help
help:
	@echo "Makefile for building MiniOS project"
	@echo "Usage:"
	@echo "  make               # Build the main application"
	@echo "  make clean         # Clean up all build artifacts"
