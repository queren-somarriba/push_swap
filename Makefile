# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: qsomarri <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/01 18:55:06 by qsomarri          #+#    #+#              #
#    Updated: 2024/09/14 15:40:53 by qsomarri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS_NAME = checker

CC = @cc

CFLAGS = -Wall -Wextra -Werror -g -I./includes

RM = @rm -rf

MAKE = @make -C

SRCS_DIR = srcs

SRCS =	$(SRCS_DIR)/commands.c \
	$(SRCS_DIR)/commands2.c \
	$(SRCS_DIR)/commands_utils.c \
	$(SRCS_DIR)/parsing.c \
	$(SRCS_DIR)/parsing_utils.c \
	$(SRCS_DIR)/list_utils.c \
	$(SRCS_DIR)/list_utils2.c \
	$(SRCS_DIR)/list_utils3.c \
	$(SRCS_DIR)/push_swap.c \
	$(SRCS_DIR)/push_swap_utils.c \
	$(SRCS_DIR)/push_swap_utils2.c \

OBJ_DIR = obj

OBJS = $(SRCS:$(SRCS_DIR)/%.c=$(OBJ_DIR)/%.o)

BONUS_SRCS_DIR = bonus

BONUS_SRCS =	$(BONUS_SRCS_DIR)/checker_bonus.c \
        	$(BONUS_SRCS_DIR)/commands_utils_bonus.c \
	        $(BONUS_SRCS_DIR)/parsing_bonus.c \
	       	$(BONUS_SRCS_DIR)/parsing_utils_bonus.c \
	        $(BONUS_SRCS_DIR)/list_utils3_bonus.c \


OBJS_BONUS = $(BONUS_SRCS:$(BONUS_SRCS_DIR)/%:.c=$(OBJ_DIR)/%.o)

LIBFT_PATH = ./libft

LIBFT = $(LIBFT_PATH)/libft.a

# Compilation des fichiers objets
$(OBJ_DIR)/%.o: $(SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_SRCS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

# Cible principale
all: $(NAME)

# Création de l'exécutable
$(NAME): $(LIBFT) $(OBJS)
	@$(CC) -o $(NAME) $(CFLAGS) $(OBJS) -L$(LIBFT_PATH) -lft
		@echo "\033[36m    ______/ \-.   _  "
		@echo "\033[36m .-/     (    o\_//    *~o~o~* PUSH_SWAP Compiled !*~o~o~* "
		@echo "\033[36m  |  ___  \_/\---'   "
		@echo "\033[36m   |_||  |_||        "
		@echo "\033[0;35m                      Bonne correction !"
		@echo "\033[0;92m * $(NAME) program file was created\033[0m *"

bonus :	$(LIBFT) $(OBJS_BONUS)
	@$(CC) -o $(BONUS_NAME) $(CFLAGS) $(OBJS_BONUS) -L$(LIBFT_PATH) -lft
		@echo "\033[36m     /\_/\           ___"
		@echo "\033[36m    = o_o =_______    \ \     *~o~o~* BONUS Compiled !*~o~o~* "
		@echo "\033[36m     __^      __(  \.__) )    "
		@echo "\033[36m (@)<_____>__(_____)____/   "
		@echo "\033[0;35m                     Bonne correction !"
		@echo "\033[0;92m* $(BONUS_NAME) program file was created\033[0m *"


# Construction de la libft
$(LIBFT):
	@$(MAKE) $(LIBFT_PATH) all

# Création du répertoire des objets
$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

# Nettoyage des fichiers objets
clean:
	@$(MAKE) $(LIBFT_PATH) clean
	@$(RM) $(OBJ_DIR)
	@echo "\033[0;91m* $(NAME) object files was deleted *\033[0m"

# Nettoyage complet
fclean: clean
	@$(MAKE) $(LIBFT_PATH) fclean
	@$(RM) $(NAME) $(BONUS_NAME)
	@echo "\033[0;91m* $(NAME) was deleted *\033[0m"

# Reconstruction complète
re: fclean all

party :	
	@printf "\033c"
	@echo "\n\033[35m♪┏(・o･)┛♪"
	@sleep 0.5
	@printf "\033c"
	@echo "\033[1;33m♪┗(・o･)┓♪"
	@sleep 0.5
	@printf "\033c"
	@echo "\n\033[36m♪┏(・o･)┛♪"
	@sleep 0.5
	@printf "\033c"
	@echo "\033[34m♪┗(・o･)┓♪\n"

.PHONY: all clean fclean re bonus
