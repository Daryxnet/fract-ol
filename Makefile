# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 12:48:53 by dagarmil          #+#    #+#              #
#    Updated: 2024/12/04 20:23:05 by dagarmil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Colors
RESET 	 	= "\033[0m"
BLACK 	 	= "\033[30m"    # Black
RED   	 	= "\033[31m" 	 # Red
GREEN    	= "\033[32m"    # Green
YELLOW   	= "\033[33m"    # Yellow
BLUE     	= "\033[34m"    # Blue
MAGENTA  	= "\033[35m"    # Magenta
CYAN     	= "\033[36m"    # Cyan
WHITE    	= "\033[37m"    # White

# Compiler
NAME 		= fractol
CC   		= cc
CFLAGS		= -Wall -Wextra -Werror
FLAGSMLX42  = -ldl -lglfw -pthread -lm
AR 			= ar rcs
MAKE        = make -C
MKDIR		= mkdir -p
RM			= rm -rf

# Libs
LIBFT_DIR 		= lib/Libft
LIBFT_LIB 		= $(LIBFT_DIR)/Libftnew.a
MLX42_LIB 		= $(MLX42_BUILD)/libmlx42.a
MLX42_SRC 		= lib/MLX42
MLX42_BUILD 	= lib/MLX42/build

# includes
INCLUDE_DIR 	= includes/
MLX42_H 		= lib/MLX42/include/MLX42/
LIBFT_H 		= lib/Libft/includes/
INCLUDE_FLAG	= -I./$(INCLUDE_DIR) \
				  -I./$(MLX42_H) \
				  -I./$(LIBFT_H) \

# Sources
SRCS_DIR 		= srcs/
SRCS 			= $(wildcard $(SRCS_DIR)/*.c)

# Objects
OBJS_DIR 		= objs/
OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJS_DIR)/%.o)


# Rules
all: $(LIBFT_LIB) $(MLX42_LIB) $(OBJS_DIR) $(NAME)

# Rule for Name
$(NAME): $(LIBFT_LIB) $(MLX42_LIB) $(OBJS) Makefile
	@echo $(GREEN) "Compiling $(NAME)..." $(RESET)
	@$(CC) $(CFLAGS) $(INCLUDE_FLAG) $(OBJS) $(LIBFT_LIB) $(MLX42_LIB) $(FLAGSMLX42) -o $(NAME)
	@echo $(YELLOW) "Compiling FINISHED" $(RESET)

# Objects directori
$(OBJS_DIR):
	mkdir -p $(OBJS_DIR)

# Rule for compile .c in .o
$(OBJS_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) $(INCLUDE_FLAG) -c $< -o $@

# Compile Libft
$(LIBFT_LIB):
	@echo $(CYAN) "Compiling Libft..." $(RESET)
	@$(MAKE) $(LIBFT_DIR)
	@echo $(YELLOW) "Libft compiled" $(RESET)

# Limpieza de objetos y el ejecutable
clean:
	@echo $(MAGENTA) "Cleaning..." $(RESET)
	@$(RM) $(OBJS_DIR)
	@make -C $(LIBFT_DIR) clean
	@echo $(RED) "Cleaned" $(RESET)

# Eliminar todo, incluyendo el ejecutable
fclean: clean
	@echo $(MAGENTA) "Removing library..." $(RESET)
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_LIB)
	@echo $(RED) "Removed library" $(RESET)

# Recompilar todo
re: fclean all
	@echo $(BLUE) "Rebuilding everything..." $(RESET)

.PHONY: all clean fclean re

