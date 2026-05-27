# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mobenais <mobenais@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/26 00:00:00 by                   #+#    #+#              #
#    Updated: 2026/05/26 11:38:33 by mobenais         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# =========================== COULEURS ======================================= #
RED      := \033[0;31m
GREEN    := \033[0;32m
YELLOW   := \033[0;33m
BLUE     := \033[0;34m
MAGENTA  := \033[0;35m
CYAN     := \033[0;36m
WHITE    := \033[0;37m
BOLD     := \033[1m
RESET    := \033[0m

# =========================== VARIABLES ====================================== #
NAME     := chrono
CC       := cc
CFLAGS   := -Wall -Wextra -Werror -g
INC      := -I header
HEADER   := header/chrono.h
SRC      := src/chrono.c src/conio_new.c
OBJ_DIR  := obj
OBJ      := $(SRC:src/%.c=$(OBJ_DIR)/%.o)

TOTAL    := $(words $(SRC))
CURRENT  := 0

# =========================== REGLES ========================================= #
all: banner $(NAME)

$(NAME): $(OBJ)
	@printf "$(CYAN)$(BOLD)\n   >> Édition des liens...$(RESET)\n"
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)
	@printf "$(GREEN)$(BOLD)\n"
	@printf "   ╔══════════════════════════════════════════╗\n"
	@printf "   ║   ✔  COMPILATION RÉUSSIE  ➜  ./$(NAME)    ║\n"
	@printf "   ╚══════════════════════════════════════════╝\n$(RESET)\n"

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@mkdir -p $(OBJ_DIR)
	@$(eval CURRENT=$(shell echo $$(($(CURRENT)+1))))
	@printf "$(YELLOW)   [%d/%d] $(BLUE)Compilation de $(BOLD)%-25s$(RESET)\r" $(CURRENT) $(TOTAL) "$<"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@
	@printf "$(GREEN)   [✔] $(WHITE)$(BOLD)%-40s$(RESET)\n" "$< compilé"


run:
	@./$(NAME)

banner:
	@printf "$(MAGENTA)$(BOLD)\n"
	@printf "   ░█▀▀░█░█░█▀▄░█▀█░█▀█░█▀█\n"
	@printf "   ░█░░░█▀█░█▀▄░█░█░█░█░█░█\n"
	@printf "   ░▀▀▀░▀░▀░▀░▀░▀▀▀░▀░▀░▀▀▀\n"
	@printf "$(CYAN)        ⏱   POMODORO  ⏱$(RESET)\n\n"
	@printf "Usage: %s <hours> <minutes> <seconds>\n"

clean:
	@printf "$(RED)$(BOLD)   ✘  Suppression des objets...$(RESET)\n"
	@rm -rf $(OBJ_DIR)
	@printf "$(GREEN)   [✔] Objets supprimés$(RESET)\n"

fclean: clean
	@printf "$(RED)$(BOLD)   ✘  Suppression du binaire $(NAME)...$(RESET)\n"
	@rm -f $(NAME)
	@printf "$(GREEN)   [✔] $(NAME) supprimé$(RESET)\n"

re: fclean all

help:
	@printf "$(CYAN)$(BOLD)\n   ┌─────────── AIDE ───────────┐$(RESET)\n"
	@printf "$(YELLOW)   │  make        $(WHITE)→ compile$(RESET)\n"
	@printf "$(YELLOW)   │  make clean  $(WHITE)→ nettoie .o$(RESET)\n"
	@printf "$(YELLOW)   │  make fclean $(WHITE)→ nettoie tout$(RESET)\n"
	@printf "$(YELLOW)   │  make re     $(WHITE)→ recompile$(RESET)\n"
	@printf "$(CYAN)$(BOLD)   └────────────────────────────┘$(RESET)\n\n"

.PHONY: all clean fclean re banner help
