# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/13 17:13:57 by dagarmil          #+#    #+#              #
#    Updated: 2024/12/13 17:39:53 by dagarmil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RESET			= "\033[0m"
BLACK    		= "\033[30m"    # Black
RED      		= "\033[31m"    # Red
GREEN    		= "\033[32m"    # Green
YELLOW   		= "\033[33m"    # Yellow
BLUE     		= "\033[34m"    # Blue
MAGENTA  		= "\033[35m"    # Magenta
CYAN     		= "\033[36m"    # Cyan
WHITE    		= "\033[37m"    # White

# Compiler
NAME			= fractol
CC				= cc
CFLAGS			= -Wall -Wextra -Werror
MAKE			= make -sC
MKDIR			= mkdir -p
RM				= rm -rf

# Libs
LIBFT_DIR		= libft
LIBFT			= $(LIBFT_DIR)/libft.a
LINKER  	    = -lft -L $(LIBFT_DIR)

# Includes
INCLUDES_DIR 	= includes
INCLUDES_FLAG 	= -I$(INCLUDES_DIR) \
				  -I$(LIBFT_DIR) \

INCLUDES		= $(wildcard $(INCLUDES_DIR)/*.h) \
				  $(LIBFT_DIR)/libft.h \

# Sources
SRCS_DIR		= srcs/
SRC_FILES		= main.c \
				  utils.c \
				  events.c \
				  render.c \
			 	  fractals.c \
				  mandelbox.c \
				  make_engine.c \

SRCS			= $(addprefix $(SRCS_DIR), $(SRC_FILES))

# Objects
OBJS_DIR		= objs/
OBJ_FILES		= $(SRC_FILES:.c=.o)
OBJS			= $(addprefix $(OBJS_DIR), $(OBJ_FILES))

MLX_DIR			= mlx_linux
MLX				= $(MLX_DIR)/libmlx.a
LINKER			+= -lmlx -lm -lz -lXext -lX11 -L $(MLX_DIR)
INCLUDES_FLAG	+= -I$(MLX_DIR)


all : $(LIBFT) $(MLX) $(OBJS_DIR) $(NAME)

$(LIBFT) :
	@echo $(CYAN) "Compiling libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(YELLOW) "libft Compiled!" $(RESET)

$(MLX) :
	@echo $(CYAN) "Compiling mlx..." $(RESET)
	@$(MAKE) $(MLX_DIR)
	@echo $(YELLOW) "mlx compiled!" $(RESET)

$(OBJS_DIR) :
	@$(MKDIR) $(OBJS_DIR)

$(NAME) : $(OBJS) Makefile
	@echo $(GREEN) "Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(OBJS) $(LINKER) -o $(NAME)
	@echo $(YELLOW) "Compiling FINISHED" $(RESET)

$(OBJS_DIR)%.o : $(SRCS_DIR)%.c $(INCLUDES)
	@$(CC) $(CFLAGS) $(INCLUDES_FLAG) -c $< -o $@

clean :
	@$(RM) $(OBJS_DIR)
	@echo $(RED) "Cleaned!" $(RESET)

fclean : clean
	@$(RM) $(NAME)
	@$(MAKE) $(MLX_DIR) clean
	@$(MAKE) $(LIBFT_DIR) fclean
	@echo $(RED) "Full Cleaned!" $(RESET)

re: fclean all

.PHONY: all clean fclean re
