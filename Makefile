NAME=philo
BONUS = philo_bonus

CFLAGS= -Wall -Werror -Wextra -g -pthread
CC = gcc

SRC_1=	
		

BONUS_SRC=	

OBJECTS_1= $(SRC_1:.c=.o)
BONUS_OBJ = ${BONUS_SRC:.c=.o}

HEADER = philo.h
HEADER_BONUS=


all:  $(NAME) 
bonus :  $(BONUS)

%.o: %.c	$(HEADER) 
	$(CC) $(CFLAGS)  -c -o  $@ $<

$(NAME): $(OBJECTS_1) $(HEADER)
	$(CC) $(CFLAGS)  $(OBJECTS_1)  -o $(NAME) 

$(BONUS): $(BONUS_OBJ) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(BONUS_OBJ)  -o $(BONUS) 

clean : 
	rm -f *.o

fclean : clean
	rm -f $(NAME) $(BONUS)

re : fclean all

.PHONY : all re clean fclean bonus