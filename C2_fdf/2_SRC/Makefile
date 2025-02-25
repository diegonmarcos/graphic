# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 16:00:50 by dinepomu          #+#    #+#              #
#    Updated: 2025/02/15 11:37:51 by dinepomu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

UNAME_S := $(shell uname -s)
MAKEFLAGS += --silent



### VARIABELS ###

NAME		:= fdf

SRC_DIR		:= src/
OBJ_DIR		:= obj/
CC			:= gcc
CFLAGS		:= -g -O3 -Wall -Werror -Wextra
#FSANITIZE	:= -fsanitize=address -g3
FSANITIZE	:= 
NOFLAGS		:= -g
RM			:= rm -rf

INC		 		:= inc/
LIB				:= lib/
FT_MYLIB_NAME	:= ft_mylib
FT_MYLIB_DIR	:= $(LIB)ft_mylib/
FT_MYLIB		:= $(FT_MYLIB_DIR)libft_mylib.a

ifeq ($(UNAME_S),Linux)
	MINILIBX_DIR	:= $(LIB)minilibx/minilibx_linux/
	#MINILIBX		:= $(MINILIBX_DIR)libmlx.a
	MINILIBXCC		:= -I$(MINILIBX_DIR) -L $(MINILIBX_DIR) -lmlx
	LIBS			:= -lXext -lX11 -lm
else ifeq ($(UNAME_S),Darwin)
	MINILIBX_DIR	:= $(LIB)minilibx/minilibx_macos/
	#MINILIBX		:= $(MINILIBX_DIR)libmlx.a
	MINILIBXCC		:= -I$(MINILIBX_DIR) -L $(MINILIBX_DIR) -lmlx
	LIBS			:= -framework OpenGL -framework AppKit
endif

HEADER 				:= -I$(INC) -I$(FT_MYLIB_DIR) -I$(MINILIBX_DIR)
LIBRARIES			:= -L$(FT_MYLIB_DIR) -l$(FT_MYLIB_NAME) -L$(MINILIBX_DIR) -lmlx $(LIBS)






### SOURCES ###
SRC_FILES_MAIN	=						\
					_main				
SRC_FILES_SRC	= 						\
					1...map_load \
					1.0.load_mapini \
					1.0.load_mapsize \
					1.1.load_getpoints \
					1.1.load_loadpoints \
					1.2.load_colorize \
					1.2.load_gopolar \
					2...sys_ini \
					3...map_draw \
					3.1..draw_background \
					3.2..draw_parsemap \
					3.2.1.parse_geometry \
					3.2.2.parse_matrix \
					3.2.3.parse_scale \
					3.3..draw_drawning \
					3.3..drawning_gofit \
					3.3.1.drawning_wired \
					3.3.2.drawning_doted \
					3.3.2.drawning_myputpixel \
					3.4..draw_menu \
					4...views_bonus \
					5...control_keys \
					5...control_keys2 \
					5...control_mouse \
					6...utils \

SRC_FILES	= $(SRC_FILES_MAIN) $(SRC_FILES_SRC)

SRC 		= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 		= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS		= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF		=	.cache_exists

### SUBMODULES ###
MINILIBX_CODAM_URL = https://github.com/codam-coding-college/MLX42.git
MINILIBX_CODAM_DIR = lib/minilibx/minilibx_codam

MINILIBX_LINUX_URL = https://github.com/42Paris/minilibx-linux.git
MINILIBX_LINUX_DIR = lib/minilibx/minilibx_linux







### RULES ###
all:	mkdir clone_repos makelibs $(NAME)

#### Clone Repos ####
clone_repos: mkdir lib/minilibx/minilibx_linux
lib/minilibx/minilibx_linux:
	git clone $(MINILIBX_CODAM_URL) $(MINILIBX_CODAM_DIR)
	git clone $(MINILIBX_LINUX_URL) $(MINILIBX_LINUX_DIR)

#### Make Libs ####
makelibs:	
	$(MAKE) -C $(FT_MYLIB_DIR)

ifeq ($(UNAME_S),Linux)
	cd $(MINILIBX_DIR) && ./configure
	cd ../../..
endif
	@$(MAKE) -C $(MINILIBX_DIR)

#### Make Program ####
$(NAME):	$(OBJ)		
			$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBRARIES) -o $(NAME)		
			@echo " $(BLUE)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBRARIES) -o $(NAME)$(DEF_COLOR)"
			@echo "$(GREEN)✨ FDF compiled!$(DEF_COLOR)"
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
			mkdir -p $(OBJ_DIR)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) -MMD -c $< -o $@
-include 	${DEPS}

bonus:		
			$(MAKE) all







### CLEANERS ###
clean:
#			make clean -C $(FT_MYLIB_DIR)
			@echo "$(CYAN)ft_mylib object and dependency files cleaned.$(DEF_COLOR)"
			make clean -C $(MINILIBX_DIR)
			@echo "$(CYAN)Minilibx object files cleaned.$(DEF_COLOR)"	
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)Fdf object files cleaned!$(DEF_COLOR)"

fclean:		clean
#			make fclean -C $(FT_MYLIB_DIR)
			@echo "$(CYAN)libft_mylib.a lib cleaned!$(DEF_COLOR)"
			$(RM) -f $(MINILIBX_DIR)libmlx.a
			@echo "$(CYAN)libmlx.a lib cleaned!$(DEF_COLOR)"			
			$(RM) -f $(NAME)
			@echo "$(CYAN)Fdf executable files cleaned!$(DEF_COLOR)"
			rm -rf log


re:			fclean all
			@$(MAKE)	
			@echo "$(GREEN)Cleaned and rebuilt everything for Fdf!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

fclean_all: fclean
			$(RM) lib/minilibx

.PHONY:		all clean fclean re norm mkdir



### TESTERS ###

valgrind:	all
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log/valgrind.test ./$(NAME) maps/42.fdf 2>&1
			
			cat log/valgrind.test \
			| grep -E "ERROR SUMMARY|definitely lost|indirectly lost|possibly lost|still reachable|uninitialised" \
			| tee log/valgrind_sum.log \

			cat log/valgrind.test \
			| grep -E "at " | grep -v "libexec" \
			| tee log/valgrind_sum2.log \





### HELPERS ###
mkdir:
	mkdir -p $(OBJ_DIR)
	mkdir -p $(LIB)
	mkdir -p $(FT_MYLIB_DIR)
	mkdir -p log/2.Memory_Check/allocs

helper:
	printf "Usage: ./fdf [maps]\n\n"
	printf "Maps:\n"
	printf "	- maps/42.fdf\n"
	printf "	- maps/10-2.fdf\n"
	printf "	- maps/10-2.fdf\n"
	printf "	- maps/...\n"	


### COLORS ###
DEF_COLOR = \033[0;39m
GRAY = \033[0;90m
RED = \033[0;91m
GREEN = \033[0;92m
YELLOW = \033[0;93m
BLUE = \033[0;94m
MAGENTA = \033[0;95m
CYAN = \033[0;96m
WHITE = \033[0;97m