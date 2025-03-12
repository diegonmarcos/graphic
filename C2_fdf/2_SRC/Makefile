# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/02/14 16:00:50 by dinepomu          #+#    #+#              #
#    Updated: 2025/03/12 14:31:39 by dinepomu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# https://linktr.ee/diegonmarcos											   #
# **************************************************************************** #

################################################################################
### VARIABELS ###

NAME			:= fdf

SRC_DIR			:= src/src_all/
OBJ_DIR			:= obj/
CC				:= gcc
CFLAGS			:= -g -O3 -Wall -Wextra
RM				:= rm -rf
MAKEFLAGS 		+= --silent

FT_MYLIB_NAME	:= mylibc
FT_MYLIB_DIR	:= libs/mylibc/
FT_MYLIB		:= $(FT_MYLIB_DIR)mylibc.a
FT_MYLIBX_NAME	:= mylibx_
FT_MYLIBX_DIR	:= libs/mylibx/
FT_MYLIBX		:= $(FT_MYLIB_DIR)mylibx.a

MINILIBX_DIR	:= libs/minilibx/minilibx_linux/
LIBS			:= -lXext -lX11 -lm

HEADER 			:= -Iinc -I$(FT_MYLIB_DIR) -I$(FT_MYLIBX_DIR)
LIBRARIES		:= -L$(FT_MYLIB_DIR) -l$(FT_MYLIB_NAME) -L$(FT_MYLIBX_DIR) -l$(FT_MYLIBX_NAME)


################################################################################
### SOURCES ###
SRC_FILES_MAIN		=							\
					_main				
SRC_FILES_SRC		= 							\
					0___vars_ini				\
					1_0_load_mapini				\
					1_0_load_mapsize			\
					1_1_load_getpoints			\
					1_2_load_colorize			\
					1_3_map_checker				\
					1___map_load				\
					2_0_render_events			\
					2_2__transf_views_bonus_1	\
					2___render_pipeline			\
					3_1__transformation_0		\
					3_1__transformation_1		\
					3_1__transformation_2		\
					3_3__render_views_bonus		\
					3_5__render_menu_bonus		\
					4_0__render_background		\
					4_2__map_render				\
					4_2__render_fittoscale		\
					5_0_mydrawcircle			\
					5_0_mydrawline				\
					6___utils					\
					6___utils_ckeys				\
					6___utils_control
SRC_FILES_BONUS = 								\


SRC_FILES			= $(SRC_FILES_MAIN) $(SRC_FILES_SRC) $(SRC_FILES_BONUS)

SRC 				= 	$(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
DEPS 				= 	$(addprefix $(OBJ_DIR), $(addsuffix .d, $(SRC_FILES)))
INCS				= 	$(addprefix $(INCLUDE), $(addsuffix .h, $(INC_FILES)))
###

OBJF				=	.cache_exists

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
all:	mkdir makelibs $(NAME) run


#### Make Libs ####
makelibs:	
	$(MAKE) -C $(FT_MYLIB_DIR)

ifeq ($(UNAME_S),Linux)
	cd $(MINILIBX_DIR) && ./configure
	cd ../../..
endif
#	@$(MAKE) -C $(MINILIBX_DIR)

#### Make Program ####
$(NAME):	$(OBJ)		
			$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBRARIES) -o $(NAME)		
			@echo " $(BLUE)$(CC) $(CFLAGS) $(FSANITIZE) $(OBJ) $(LIBRARIES) -o $(NAME)$(DEF_COLOR)"
			@echo "$(GREEN) Bin Linked!$(DEF_COLOR)"
			
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
#			@echo "$(CYAN)ft_mylib object and dependency files deleted.$(DEF_COLOR)"
			$(RM) -rf $(OBJ_DIR)
			@echo "$(CYAN)Object files deleted!$(DEF_COLOR)"

fclean:		clean
#			make fclean -C $(FT_MYLIB_DIR)
#			@echo "$(CYAN)libft_mylib.a lib cleaned!$(DEF_COLOR)"		
			$(RM) -f $(NAME)
			@echo "$(CYAN)files cleaned!$(DEF_COLOR)"
			rm -rf log

re:			fclean all
			@$(MAKE)	
			@echo "$(GREEN)Rebuilded!$(DEF_COLOR)"

fclean_all: fclean

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














###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# **************************************************************************** #
#                                DOXYGEN                               	   #
# **************************************************************************** #
DOXYGEN_FILE = log/7.Doxygen/Doxygen
DOXYGEN_PATH = log/7.Doxygen
doxygen:
	rm -rf $(DOXYGEN_PATH)
	$(MAKE) create_Doxyfile
	$(MAKE) doxfile_mod
	doxygen ./$(DOXYGEN_FILE)
	xdg-open log/7.Doxygen/html/index.html


create_Doxyfile:
	mkdir -p $(DOXYGEN_PATH)
	doxygen -g $(DOXYGEN_FILE)

doxfile_mod:
	sed -i 's/PROJECT_NAME           = "My Project"/PROJECT_NAME           = "$(NAME)"/g' ./$(DOXYGEN_FILE)
	sed -i 's/PROJECT_BRIEF          = "My Project Brief"/PROJECT_BRIEF          = "$(NAME)"/g' ./$(DOXYGEN_FILE)
	sed -i 's/OUTPUT_DIRECTORY       =/OUTPUT_DIRECTORY       = log\/7.Doxygen/g' ./$(DOXYGEN_FILE)
	sed -i 's/OPTIMIZE_OUTPUT_FOR_C  = NO/OPTIMIZE_OUTPUT_FOR_C  = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/EXTRACT_ALL            = NO/EXTRACT_ALL            = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/HIDE_SCOPE_NAMES       = NO/HIDE_SCOPE_NAMES       = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/INPUT                  =/INPUT                  = src/g' ./$(DOXYGEN_FILE)
	sed -i 's/RECURSIVE              = NO/RECURSIVE              = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/EXCLUDE                =/EXCLUDE                = src\/src_all/g' ./$(DOXYGEN_FILE)
	sed -i 's/GENERATE_LATEX         = NO/GENERATE_LATEX         = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/GENERATE_TREEVIEW      = NO/GENERATE_TREEVIEW      = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/GENERATE_MAN           = NO/GENERATE_MAN           = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/GENERATE_DOCBOOK       = NO/GENERATE_DOCBOOK       = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/CALL_GRAPH             = NO/CALL_GRAPH             = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/CALLER_GRAPH           = NO/CALLER_GRAPH           = YES/g' ./$(DOXYGEN_FILE)
	sed -i 's/TIMESTAMP              = NO/TIMESTAMP              = YES/g' ./$(DOXYGEN_FILE)
#	sed -i 's/STRIP_FROM_PATH        =/STRIP_FROM_PATH        = ..\/..\/..\//g' ./$(DOXYGEN_FILE)



.PHONY: doxygen create_Doxyfile


