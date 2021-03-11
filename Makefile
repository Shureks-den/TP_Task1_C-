TARGET = main.out
HDRS_DIR = project/include

SRCS = \
       project/source/main.c \
       project/source/file_creation.c \
	   project/source/form_sorter.c

.PHONY: all clean

all: $(SRCS)
	$(CC) -Wall -Wextra -Werror -I $(HDRS_DIR) -o $(TARGET) $(CFLAGS) $(SRCS) 

clean:
	rm -rf $(TARGET)
