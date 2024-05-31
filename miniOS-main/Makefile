# Compiler and Compiler Flags
CC=gcc
CFLAGS=-Wall -g -Iinclude
# Linker flags
LDFLAGS=-lpthread -lreadline

# The build target executable:
TARGET=minios

# Source, Object files
SRCS=kernel/kernel.c kernel/system.c kernel/20211089/ipc.c kernel/20211089/est_pi.c kernel/20211089/round_robin.c kernel/syscalls/sys_fork.c kernel/syscalls/sys_exec.c kernel/syscalls/sys_abort.c kernel/syscalls/sys_exit.c kernel/20211089/createfile.c kernel/event_control/wait_time.c kernel/event_control/wait_event.c kernel/event_control/signal_event.c kernel/syscalls/sys_getpid.c kernel/syscalls/sys_getppid.c kernel/syscalls/sys_kill.c kernel/syscalls/sys_wait.c
OBJS=$(SRCS:.c=.o)

# Include directory
INCLUDE_DIR=include

# Test target
TEST_TARGET=test_process
TEST_SRCS=tests/test_process.c
TEST_OBJS=$(TEST_SRCS:.c=.o)

.PHONY: all clean

all: $(TARGET) $(TEST_TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

$(TEST_TARGET): $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(TEST_OBJS) $(LDFLAGS)

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

# Help
help:
	@echo "Makefile for building MiniOS project"
	@echo "Usage:"
	@echo "  make               # Build the main application"
	@echo "  make clean         # Clean up all build artifacts"
