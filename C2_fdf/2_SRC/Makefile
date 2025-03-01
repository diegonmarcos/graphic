# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 16:00:50 by dinepomu          #+#    #+#              #
#    Updated: 2025/03/01 13:48:15 by dinepomu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

################################################################################
### VARIABELS ###

NAME			:= fdf

SRC_DIR			:= src/
OBJ_DIR			:= obj/
CC				:= gcc
CFLAGS			:= -g -O3 -Wall -Werror -Wextra
RM				:= rm -rf
MAKEFLAGS 		+= --silent

FT_MYLIB_NAME	:= mylibc
FT_MYLIB_DIR	:= libs/mylibc/
FT_MYLIB		:= $(FT_MYLIB_DIR)mylibc.a

MINILIBX_DIR	:= libs/minilibx/minilibx_linux/
MINILIBXCC		:= -I$(MINILIBX_DIR) -L $(MINILIBX_DIR) -lmlx
LIBS			:= -lXext -lX11 -lm

HEADER 			:= -Iinc -I$(FT_MYLIB_DIR) -I$(MINILIBX_DIR)
LIBRARIES		:= -L$(FT_MYLIB_DIR) -l$(FT_MYLIB_NAME) -L$(MINILIBX_DIR) -lmlx $(LIBS)





################################################################################
### SOURCES ###
SRC_FILES_MAIN		=						\
					_main				
SRC_FILES_SRC		= 						\
					1___map_load 			\
					1_0_load_mapini 		\
					1_0_load_mapsize 		\
					1_1_load_getpoints 		\
					1_1_load_loadpoints 	\
					1_2_load_colorize 		\
					1_2_load_gopolar 		\
					2___sys_ini 			\
					3___map_draw 			\
					3_1__draw_background 	\
					3_2__draw_parsemap 		\
					3_2_1_parse_geometry 	\
					3_2_2_parse_matrix 		\
					3_2_3_parse_scale 		\
					3_3__draw_drawning 		\
					3_3__drawning_gofit 	\
					3_3_1_drawning_wired 	\
					3_3_2_drawning_doted 	\
					3_3_2_drawning_myputpixel \
					3_4__draw_menu 			\
					4___views_bonus 		\
					5___control_keys 		\
					5___control_keys2 		\
					5___control_mouse 		\
					6___utils 				\

SRC_FILES			= $(SRC_FILES_MAIN) $(SRC_FILES_SRC)

SRC 				= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS				= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF				=	.cache_exists

### SUBMODULES ###
MINILIBX_CODAM_URL	= https://github.com/codam-coding-college/MLX42.git
MINILIBX_CODAM_DIR	= libs/minilibx/minilibx_codam

MINILIBX_LINUX_URL	= https://github.com/42Paris/minilibx-linux.git
MINILIBX_LINUX_DIR	= libs/minilibx/minilibx_linux

MAP = 0
MAPS = maps/$(MAP).fdf
ifeq ($(MAP),earth)
MAP1 = MGDS_WHOLE_WORLD_OCEAN0_L
MAPS = maps/$(MAP1).fdf
else ifeq ($(MAP),mars)
MAP1 = mars_org
MAPS = maps/$(MAP1).fdf
else ifeq ($(MAP),fractol)
MAP1 = julia
MAPS = maps/$(MAP1).fdf
else ifeq ($(MAP),mandel)
MAP1 = mandelbrot
MAPS = maps/$(MAP1).fdf
endif


################################################################################
### RULES ###
all:	mkdir clone_repos makelibs $(NAME) run

#### Clone Repos ####
clone_repos: mkdir libs/minilibx/minilibx_linux
libs/minilibx/minilibx_linux:
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
			@echo "$(GREEN) Bin Linked!$(DEF_COLOR)"
			$(MAKE) run
			
$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(INCS)
			mkdir -p $(OBJ_DIR)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			$(CC) $(CFLAGS) -MMD -c $< -o $@
-include 	${DEPS}

bonus:		
			$(MAKE) all

run:
ifneq ($(MAP), 0)
	./fdf $(MAPS)
endif


################################################################################
### CLEANERS ###
clean:
#			make clean -C $(FT_MYLIB_DIR)
			@echo "$(CYAN)ft_mylib object and dependency files deleted.$(DEF_COLOR)"
			make clean -C $(MINILIBX_DIR)
			@echo "$(CYAN)Minilibx object files deleted.$(DEF_COLOR)"	
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)Object files deleted!$(DEF_COLOR)"

fclean:		clean
#			make fclean -C $(FT_MYLIB_DIR)
			@echo "$(CYAN)libft_mylib.a lib cleaned!$(DEF_COLOR)"
			$(RM) -f $(MINILIBX_DIR)libmlx.a
			@echo "$(CYAN)libmlx.a lib cleaned!$(DEF_COLOR)"			
			$(RM) -f $(NAME)
			@echo "$(CYAN)files cleaned!$(DEF_COLOR)"
			rm -rf log


re:			fclean all
			@$(MAKE)	
			@echo "$(GREEN)Rebuilded!$(DEF_COLOR)"

fclean_all: fclean
			$(RM) libs/minilibx

.PHONY:		all clean fclean re norm mkdir


################################################################################
### TESTERS ###

valgrind:	all
			valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes --log-file=log/valgrind.test ./$(NAME) maps/42.fdf 2>&1
			
			cat log/valgrind.test \
			| grep -E "ERROR SUMMARY|definitely lost|indirectly lost|possibly lost|still reachable|uninitialised" \
			| tee log/valgrind_sum.log \

			cat log/valgrind.test \
			| grep -E "at " | grep -v "libexec" \
			| tee log/valgrind_sum2.log \


normimette:
			@echo "$(CYAN)Norminette:$(DEF_COLOR)"
			@norminette $(SRC) $(INCLUDE) | grep -v Norme -B1 || true

################################################################################
### HELPERS ###
mkdir:
	mkdir -p $(OBJ_DIR)
#	mkdir -p $(LIB)
	mkdir -p $(FT_MYLIB_DIR)
	mkdir -p log/2.Memory_Check/allocs

help:
	printf "Usage: ./fdf [maps]\n\n"
	printf "Maps:\n"
	printf "	- maps/42.fdf\n"
	printf "	- maps/10-2.fdf\n"
	printf "	- maps/10-2.fdf\n"
	printf "	- maps/...\n"	


################################################################################
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