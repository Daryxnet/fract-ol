# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/08/28 12:48:53 by dagarmil          #+#    #+#              #
#    Updated: 2024/12/02 15:14:57 by dagarmil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

# Directorios
LIBFT_DIR = lib/Libft
MLX42_SRC = lib/MLX42
MLX42_BUILD = lib/MLX42/build
SRC_DIR = src
OBJ_DIR = obj
INCLUDE_DIR = include/

# Bibliotecas
LIBFT_LIB = $(LIBFT_DIR)/Libftnew.a
MLX42_LIB = $(MLX42_BUILD)/libmlx42.a
MLX42_H = lib/MLX42/include/MLX42/
LIBFT_H = lib/Libft/includes/
INCLUDE_H = $(INCLUDE_DIR)

# Archivos fuente y objetos
SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Compilador y flags
CC = cc
CFLAGS = -Wall -Wextra -Werror
FLAGSMLX42 = -ldl -lglfw -pthread -lm
AR = ar rcs

# Reglas
all: $(NAME)

# Regla para compilar el programa final
$(NAME): $(LIBFT_LIB) $(MLX42_LIB) $(OBJ)
	$(CC) $(CFLAGS) -I./$(MLX42_H) -I./$(LIBFT_H) -I./$(INCLUDE_H) $(OBJ) $(LIBFT_LIB) $(MLX42_LIB) $(FLAGSMLX42) -o $(NAME)

# Crear el directorio de objetos si no existe
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regla para compilar los archivos .c en .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -I./$(MLX42_H) -I./$(LIBFT_H) -I./$(INCLUDE_H) -c $< -o $@

# Compilación de Libft
$(LIBFT_LIB):
	@echo "Compiling Libft..."
	make -C $(LIBFT_DIR)
	@echo "Libft compiled"

# Limpieza de objetos y el ejecutable
clean:
	@echo "Cleaning..."
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean
	@echo "Cleaned"

# Eliminar todo, incluyendo el ejecutable
fclean: clean
	@echo "Removing library..."
	rm -f $(NAME)
	rm -f $(LIBFT_LIB)
	@echo "Removed library"

# Recompilar todo
re: fclean all
	@echo "Rebuilding everything..."

.PHONY: all clean fclean re

