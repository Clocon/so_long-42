# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 13:19:05 by lumorale          #+#    #+#              #
#    Updated: 2023/04/03 12:38:54 by lumorale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long
LIBFT			=	./libft/libft.a
PRINTF			=	./ft_printf/libftprintf.a
LINE			=	./get_next_line/get_next_line.a

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
AR				=	ar -rcs

SRCS			=	
					

#		COLORS		#
CYELLOW			=\033[1;33m
CGREEN			=\033[0;32m
CRED			=\033[0;91m
CRESET			=\033[0m

OBJS			=	$(SRCS:.c=.o)

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

all:			$(NAME) $(LIBFT) $(PRINTF) $(LINE)

$(LIBFT):
				@make -C ./libft

$(PRINTF):
				@make -C ./ft_printf

$(LINE):
				@make -C ./get_next_line

$(NAME):		$(LIBFT) $(OBJS) $(PRINTF) $(OBJS) $(LINE) $(OBJS)
				@$(CC) $(CFLAGS) $(LIBFT) $(PRINTF) $(LINE) $(OBJS)   -o $(NAME)
				@echo "\n$(CYELLOW)$(NAME) -> $(CGREEN) compiled$(CRESET)"

clean:
				@$(RM) $(OBJS)  
				@make -C ./libft clean
				@make -C ./ft_printf clean
				@make -C ./get_next_line clean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} objects files were deleted.${CRESET}"

fclean:			clean
				@$(RM) $(NAME)
				@make -C ./libft fclean
				@make -C ./ft_printf fclean
				@make -C ./get_next_line fclean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} was deleted.${CRESET}"

re:				fclean all

.PHONY:			all clean fclean re