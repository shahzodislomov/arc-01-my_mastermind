CC = gcc
CFLAGS = -Wall -Wextra -Werror

TARGET = my_mastermind

SRCS = my_mastermind.c

$(TARGET): $(SRCS)
  $(CC) $(CFLAGS) $^ -o $@

clean:
  rm -f $(TARGET)

.PHONY:fclean

fclean:
  rm -rf $(TARGET)
