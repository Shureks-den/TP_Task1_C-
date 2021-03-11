TARGET = main.out
HDRS_DIR = project/include

SRCS = \
       main.c \
       file_creation.c \
	   form_sorter.c

.PHONY: all clean

all: $(SRCS)
	$(CC) -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS) 

clean:
	rm -rf $(TARGET)
