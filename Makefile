PH_SRCS =	srcs/exit.c srcs/engine.c srcs/utils.c srcs/utils2.c srcs/utils3.c srcs/main.c srcs/init.c

PH_HEADER =	include/philosophers.h

PH_NAME =	philo

PH_OBJ = 	${PH_SRCS:.c=.o}

FLAGS =		-Wall -Wextra -Werror

%.o: %.c
				@gcc -c -g3 -o $@ $?

$(PH_NAME): ${PH_OBJ}
				@gcc -g3 ${FLAGS} ${PH_OBJ} -pthread -o ${PH_NAME}
				@echo "[Done !]"

all:	${PH_NAME}

clean:	
				@echo "Cleaning..."
				@rm -f ${PH_OBJ} 
				@echo "Cleaning complete!"

fclean:			clean
				@rm -f ${PH_NAME} 

re:				fclean all

.PHONY :		fclean all re clean