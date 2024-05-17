# Compiler and Compiler Flags
CC=gcc
CFLAGS=-Wall -g -Iinclude
# Linker flags
LDFLAGS=-lpthread -lreadline

# The build target executable:
TARGET=minios

# Source, Object files
SRCS=kernel/kernel.c kernel/system.c kernel/20211089/fork.c kernel/20211089/ipc.c kernel/20211089/est_pi.c kernel/20211089/round_robin.c kernel/syscalls/sys_fork.c kernel/syscalls/sys_exec.c kernel/syscalls/sys_process_control.c kernel/syscalls/sys_waitpid.c lib/event_control.c kernel/20211089/createfile.c
OBJS=$(SRCS:.c=.o)

# Include directory
INCLUDE_DIR=include

# Test executables for system call and event control
TEST_SYS_TARGET=tests/test_syscalls
TEST_SYS_SRCS=tests/test_syscalls.c
TEST_SYS_OBJS=$(TEST_SYS_SRCS:.c=.o)

TEST_EVENT_TARGET=tests/event_control_test
TEST_EVENT_SRCS=tests/event_control_test.c
TEST_EVENT_OBJS=$(TEST_EVENT_SRCS:.c=.o)

VPATH = kernel:kernel/syscalls:kernel/20211089:lib:tests

.PHONY: all clean test test_syscalls test_event_control

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# Rule for building object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Test build targets
test: test_syscalls test_event_control

test_syscalls: $(TEST_SYS_TARGET)
	-./$(TEST_SYS_TARGET) || true

$(TEST_SYS_TARGET): $(TEST_SYS_OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(filter kernel/syscalls/sys_fork.o kernel/syscalls/sys_waitpid.o kernel/syscalls/sys_process_control.o,$(OBJS)) $(LDFLAGS)

test_event_control: $(TEST_EVENT_TARGET)
	./$(TEST_EVENT_TARGET)

$(TEST_EVENT_TARGET): $(TEST_EVENT_OBJS)
	@echo "Compiling and linking $@"
	$(CC) $(CFLAGS) -o $@ $^ $(filter kernel/syscalls/sys_fork.o kernel/syscalls/sys_waitpid.o kernel/syscalls/sys_process_control.o,$(OBJS)) $(LDFLAGS)

# Clean up
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_SYS_OBJS) $(TEST_SYS_TARGET) $(TEST_EVENT_OBJS) $(TEST_EVENT_TARGET)

# Help
help:
	@echo "Makefile for building MiniOS project"
	@echo "Usage:"
	@echo "  make               # Build the main application"
	@echo "  make test          # Run all tests"
	@echo "  make test_syscalls # Run system call tests"
	@echo "  make test_event_control # Run event control tests"
	@echo "  make clean         # Clean up all build artifacts"
