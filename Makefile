SRCS = pipex.c\
	path.c\
	ft_split.c\
	libft_f.c

OBJS = ${SRCS:.c=.o}

NAME = pipex

CFLAGS = -Wall -Wextra -Werror

CC = gcc

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


all: ${NAME}

${NAME}:
	@${CC} -o ${NAME} ${CFLAGS} ${SRCS}

# ${NAME} : ${OBJS}
# 	${CC} ${CFLAGS}  -o ${NAME} $(OBJS)

clean:
	${RM} ${OBJS}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY : all clean fclean re
