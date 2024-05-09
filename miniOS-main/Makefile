# Compiler and Compiler Flags
CC=gcc
CFLAGS=-Wall -g -Iinclude
# Linker flags
LDFLAGS=-lreadline

# The build target executable:
TARGET=minios

# Source, Object files
SRCS=kernel/kernel.c kernel/system.c kernel/20211089/fork.c kernel/20211089/ipc.c kernel/20211089/est_pi.c kernel/20211089/round_robin.c kernel/syscalls/fork.c kernel/syscalls/exec.c kernel/syscalls/process_control.c
OBJS=$(SRCS:.c=.o)


# Include directory
INCLUDE_DIR=include

# Test executable
TEST_TARGET=tests/test_syscalls
TEST_SRCS=tests/test_syscalls.c
TEST_OBJS=$(TEST_SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(LDFLAGS)

# To obtain object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Build and run test
test: $(TEST_TARGET)
	./$(TEST_TARGET)

$(TEST_TARGET): $(OBJS) $(TEST_OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS) $(TEST_OBJS) $(LDFLAGS)

# Clean up:
clean:
	rm -f $(OBJS) $(TARGET) $(TEST_OBJS) $(TEST_TARGET)

