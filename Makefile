# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lumorale <lumorale@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/20 13:19:05 by lumorale          #+#    #+#              #
#    Updated: 2023/04/04 14:21:12 by lumorale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	so_long

CC				=	gcc
CFLAGS			=	-Wall -Werror -Wextra
RM				=	rm -f
AR				=	ar -rcs

SRCS			=	src/so_long.c \
					src/checker.c \
					

#		COLORS		#
CYELLOW			=\033[1;33m
CGREEN			=\033[0;32m
CRED			=\033[0;91m
CRESET			=\033[0m

OBJS			=	$(SRCS:.c=.o)

INC_LFT = -Ilibft
LIBFT = libft/libft.a

INC_FTP = -Ift_printf
PRINTF = ft_printf/libftprintf.a

INC_GNL = -Iget_next_line
LINE = get_next_line/get_next_line.a

MLX_DIR = MLX42
LIBMLXL = libmlx42.a
LIBMLX = $(MLX_DIR)/libmlx42.a -ldl -lglfw -pthread -lm
INC_MLX = -I$(MLX_DIR)/include/MLX42 -Iinclude -lglfw -L"/Users/$$USER/.brew/opt/glfw/lib/"

INC = -Iinclude $(INC_LFT) $(INC_FTP) $(INC_GNL) $(INC_MLX)

%.o: %.c
				@$(CC) $(CFLAGS) -c $< -o $@

all:			$(LIBFT) $(PRINTF) $(LINE) $(LIBMLXL) $(NAME)

$(LIBFT):
				@make -C ./libft

$(PRINTF):
				@make -C ./ft_printf

$(LINE):
				@make -C ./get_next_line

$(LIBMLXL):
				@echo "\n$(CYELLOW)Go to compile MLX42 library...$(CRESET)"
				@make -C ./MLX42

$(NAME):		$(OBJS)
				@$(CC) $(FLAGS) $(INC) $(LIBMLX) $(LIBFT) $(PRINTF) $(LINE) $(OBJS)   -o $(NAME)
				@echo "\n$(CYELLOW)$(NAME) -> $(CGREEN) compiled$(CRESET)"

clean:
				@$(RM) $(OBJS)  
				@make -C ./libft clean
				@make -C ./ft_printf clean
				@make -C ./get_next_line clean
				@make -C ./MLX42
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} objects files were deleted.${CRESET}"

fclean:			clean
				@$(RM) $(NAME)
				@make -C ./libft fclean
				@make -C ./ft_printf fclean
				@make -C ./get_next_line fclean
				@make -C ./MLX42 fclean
				@echo "${CYELLOW}${NAME} $(CGREEN) -> ${CRED} was deleted.${CRESET}"

re:				fclean all

.PHONY:			all clean fclean re