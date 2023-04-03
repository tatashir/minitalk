# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tatashir <tatashir@student.42tokyo.jp>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/26 20:16:58 by tatashir          #+#    #+#              #
#    Updated: 2023/04/03 14:07:14 by tatashir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC  = cc
CFLAGS    = -Wall -Wextra -Werror
NAME  = minitalk
NAME_CLIENT = client
NAME_SERVER = server
SRCS_CLIENT = client.c
SRCS_SERVER = server.c
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}
AR = ar
ARFLAGS = rcs
all: ${NAME}
${NAME}: ${NAME_SERVER} ${NAME_CLIENT}

${NAME_SERVER}: ${OBJS_SERVER}
	${MAKE} -C libft
	${MAKE} -C ft_printf
	${CC} ${CFLAGS} 42libft/libft.a ft_printf/libftprintf.a ${SRCS_SERVER} -o ${NAME_SERVER}

${NAME_CLIENT}: ${OBJS_CLIENT}
	${MAKE} -C libft
	${MAKE} -C ft_printf
	${CC} ${CFLAGS} 42libft/libft.a ft_printf/libftprintf.a ${SRCS_CLIENT} -o ${NAME_CLIENT}

clean:
	${RM} ${OBJS_CLIENT} ${OBJS_SERVER}
	${RM} libft/*.o libft/*.a ft_printf/*.o ft_printf/*.a
fclean:clean
	${RM} ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

# SRCS			=\
# 					ft_putnbr_fd.c


# OBJS    = 	$(SRCS:.c=.o)
# RM      = 	rm -rf
# CFLAGS	= -Wall -Wextra -Werror
# all:		$(NAME)
# $(NAME): $(OBJS)
# 		ar rcs $(NAME) $(OBJS)
# clean:	
# 	$(RM) $(OBJS)
# fclean:	clean
# 	 $(RM) $(NAME)
# re:		fclean all

.PHONY:		all clean fclean re