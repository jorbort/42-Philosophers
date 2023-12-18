NAME=philo

CFLAGS= -Wall -Werror -Wextra -g -pthread
CC = gcc

SRC_1=	main.c monitor.c mutex.c philo.c time.c utils.c \
			
OBJECTS_1= $(SRC_1:.c=.o)


HEADER = philo.h

all:  $(NAME) 

%.o: %.c	$(HEADER) 
	$(CC) $(CFLAGS)  -c -o  $@ $<

$(NAME): $(OBJECTS_1) $(HEADER)
	$(CC) $(CFLAGS)  $(OBJECTS_1)  -o $(NAME) 

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all re clean fclean bonus