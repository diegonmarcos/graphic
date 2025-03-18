# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dinepomu <dinepomu@student.42berlin.de>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/23 11:09:01 by dinepomu          #+#    #+#              #
#    Updated: 2025/03/18 12:36:17 by dinepomu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
# https://linktr.ee/diegonmarcos											   #
# **************************************************************************** #

# ############################################################################ #
#                                 MAKEFILE                                     #
# ############################################################################ #

#1. DESCRIPTION:
#	This is make file for build either PROGRAM, LIBRARY, PROGRAM+LIBRARY 
#		with their dependecies connect.
#
# - This Makefile is a template for a project with the following structure:
#	1. Headers.h, files all them must be placed inside the folder "include".
#	2. Library.a, files all them must be inside of the folder "libs"
#	3. The library makefile must be inside of the folder "libs/mylib"

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                          VARIABLES INITIALIZATIONS                           #
# ############################################################################ #
# ************************************************************************ #
# *** Name Output *** #
NAME0 = mylibx

# *** ../ or ../../ or empty *** # Libraries autocmactly already have the ../
override OUTPUT_PLACE = 

# ***Is? *** #
override IS_PROGRAM_AND_NOT_LIB = 0
override INCLUDE_LIB = 1
override BUILD_LIBRARY = 1

# ************************************************************************ #
# *** Files source *.c *** #
SOURCE_MAIN =								\

SOURCE_FILES = 								\
				mydrawcircle.c				\
				mydrawline.c				\
				myputpixel.c				\
				matrix_3d_copy.c			\
				matrix_3d_ini.c				\
				matrix_3d_mult.c			\
				mlx_x11.c					\
				ft_x11_mlx_dda_drawline.c	\
				ft_x11_mlx_xdrawline.c		\
				ft_opengl_sdl_drawline.c

#SOURCE_MAIN = $(wildcard src/*.c) $(wildcard src/*/*.c)

VPATH = src/src_all:						\

# *** Extra Rules (Bonus) *** #
CHECKER_BONUS_DIR = 
CHECKER_BUILD = $(MAKE) -C $(CHECKER_BONUS_DIR)

# *** DEBUG MAKE? *** #
.SILENT:

# ************************************************************************ #
# *** Library *.a (libraries to be included) THE ORDER MATTERS!!! *** #
LIBS_DIR = 
LIB_1_NAME =
LIB_1_PATH = $(LIBS_DIR)/$(LIB_1_NAME)
#LIB_2_NAME =
#LIB_2_PATH = $(LIBS_DIR)/$(LIB_1_NAME)

# *** Type of the Lib *** #
#IS_LIB_STATIC_AND_NOT_DYNAMIC = 1

# *** HEADERS *.h *** #
CFLAGS_INCL = -Iinc -Ilibs/$(LIB_1_NAME)/include $(HEADER)

# ************************************************************************ #
# *** Compiler, Make and Library compilers Declar *** #
MAKE = make -j#												# Number of jobs to run simultaneously amout of cores in the CPU wihtou the numbers it takes the max
MAKE += -O --no-print-directory
#MAKE += --trace all --warn-undefined-variables
#MAKE += --debug=b -j1 --warn-undefined-variables
#MAKE += --debug=v -j1 --warn-undefined-variables
#MAKE += --debug=t -j1 --warn-undefined-variables

COMPILER = clang
LIB_COMP_STATIC = ar rcs
#LIB_COMP_DYNAMIC_obj = fPIC
#LIB_COMP_DYNAMIC_lib = shared
RM = rm -rf
CFLAG_ASAN =
CFLAGS_DBG = -Wall -Wextra -g

# ############################################################################ #
#                                 HELPERS                                      #
# ############################################################################ #
# ************************************************************************ #
# *** Name definition *** #
NAME1 = $(OUTPUT_PLACE)$(NAME0)

ifeq ($(IS_PROGRAM_AND_NOT_LIB), 1)
	NAME = $(NAME1)
else
	NAME = lib$(NAME1).a
endif

# *** Source Files .c Definition path *** #
SOURCES = $(SOURCE_MAIN) $(SOURCE_FILES)

# *** Include or not a library (REMEBER TO MANAGE DEPENDECIES OF THE LIBRARIES, the root library comes after the child)
LDFLAGS +=
ifeq ($(INCLUDE_LIB), 1)
	LDFLAGS += -L$(LIBS_DIR) -l$(LIB_1_NAME)
	LDFLAGS += $(LIBRARIES)
endif

# ************************************************************************ #
#                         OBJECTS AND DEPENDENCIES                         #
# ************************************************************************ #
#Object Files and Dependency Files Definition path Main *** #
OBJECTS_MAIN =  $(patsubst %.c,objs/%.o,$(notdir $(SOURCE_MAIN)))
DEPS_MAIN = $(OBJECTS_MAIN:.o=.d)
DEPFLAGS = -MMD -MP#															# This will create the files(headers) as dependendcy and track them
-include $(DEPS_MAIN)

#Object Files and Dependency Files Definition path Lib *** #
OBJECTS_LIB =  $(patsubst %.c,objs/%.o,$(notdir $(SOURCE_FILES)))
DEPS_LIB = $(OBJECTS_LIB:.o=.d)
#DEPFLAGS = -MMD -MP#															# This will create the files(headers) as dependendcy and track them
-include $(DEPS_LIB)

OBJECTS = $(OBJECTS_MAIN) $(OBJECTS_LIB) 

###  ▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓▓  ###
# ############################################################################ #
#                                 RULES/ALL                                    #
# ############################################################################ #
.DEFAULT_GOAL:= build_dependencies

# ************************************************************************ #
#                               DEPENDENCIES                               #
# ************************************************************************ #
# *** Default rule *** #
build_dependencies:
	$(MAKE) libs_build
	$(MAKE) check_up_to_date

# *** Build the library included *** #
libs_build:
ifeq ($(BUILD_LIBRARY), 1)
#	$(MAKE) -C $(LIB_1_PATH) MAKEFLAGS=""
	$(MAKE) make_minilibx
	@echo "$(YELLOW)(•̀ᴗ•́)و $@ Done!$(RESET)"
else
#	@echo "$(GRAY)Skipping library build$(RESET)"
endif

# ************************************************************************ #
#                               MAIN                                       #
# ************************************************************************ #
# *** Default rule *** #
build_project:
	$(MAKE) hello
	$(MAKE) folders_build
#	$(MAKE) folders_lns_build
	$(MAKE) program_or_lib
	$(MAKE) combine_libs

# *** Compiling the source files into object files *** #
objs/%.o:	%.c
	mkdir -p objs
	$(COMPILER) $(CFLAGS_DBG) $(CFLAG_ASAN) $(CFLAGS_INCL) $(DEPFLAGS) -c $< -o $@
	@echo "$(GRAY)()و $@ $(NAME) Compiling Objects !$(RESET)"

# *** Is program or a Lib? ***
program_or_lib:
ifeq ($(IS_PROGRAM_AND_NOT_LIB), 1)
	echo "  $(YELLOW)Linking a Program$(RESET)"
	$(MAKE) LIB_OUTPUT="libs/lib$(NAME0).a" lib
	$(MAKE) program
else
	echo "  $(YELLOW)Linking a Lib$(RESET)"
	$(MAKE) LIB_OUTPUT=$(NAME) lib
endif

# *** Linking the object files into a library *** #
lib:	$(OBJECTS_LIB)
	$(LIB_COMP_STATIC) $(LIB_OUTPUT) $(OBJECTS_LIB)
	@echo "  $(YELLOW)(•̀ᴗ•́)و lib$(NAME).a Library Generated!$(RESET)"

# *** Linking the object files into the program *** #
program:	$(OBJECTS)
	$(COMPILER) $(OBJECTS_MAIN) -Llibs -l$(NAME0) $(LDFLAGS) $(CFLAG_ASAN) -o $(NAME)
	@echo "  $(YELLOW)(•̀ᴗ•́)و $(NAME) Bin Generated!$(RESET)"
	$(MAKE) check_up_to_date

combine_libs:
ifeq ($(INCLUDE_LIB), 1)
	echo "Creating combined library reference..."
	mv libmylibx.a libs/libmylibx_0.a
	echo "GROUP ( libs/libmylibx_0.a libs/minilibx_linux/libmlx.a -lXext -lX11 -lm )" > libmylibx.a
	echo "  $(YELLOW)(•̀ᴗ•́)و libmylibx_combined.a Library reference created!$(RESET)"
else
	@echo "$(GRAY)Skipping library merge$(RESET)"
endif

# *** Phony *** #
.PHONY:		all build program_or_lib libs_build					\
			clean fclean fclean_all re 							\
			library_clean library_fclean library_re 			\
			folder_lns_builder folders_build check_up_to_date 	\
			hello debug 										\
			werror norm_1 norm_2 log_all werror_bonus			\
			testing_alles test_export 							\
			make_dbg create_bins								\
			leaks valgrind asan time_and_perfomance				\
			help bonus											\
			bonus bonus_re										\
			run_visualizer										\

#NOT PHONY:	program lib

# ############################################################################ #
#                                 RULES/RECLEAN                                #
# ############################################################################ #
# *** Clean Objects only *** #
clean:
	$(RM) objs
#	$(MAKE) clean -C $(CHECKER_BONUS_DIR)
	@echo	"$(RED)	¯\_(ツ)_/¯ OBJECTS REMOVED!$(RESET)"

# *** Clean+Bins+Libs *** #
fclean:	clean
	$(RM) $(NAME)
#	$(RM) libs/lib$(NAME1).a
#	$(MAKE) fclean -C $(CHECKER_BONUS_DIR)
	$(RM) testers
	$(RM) libs/lib$(NAME0)_g.a
	$(RM) libs/lib$(NAME0)_asan.a
	$(RM) libs/lib$(NAME0)_g3.a
	@echo	"$(RED)		(╯°□°）╯︵ ┻━┻ FILE, OBJ REMOVED!$(RESET)"

# *** FClean+Build *** #
re: fclean build_dependencies

# *** FClean+logs_folder *** #
fclean_all:	fclean
	$(RM) log
	if [ -f imgui.ini ]; then \
		rm imgui.ini; \
	fi
	@echo	"$(RED)			(╯°□°）╯︵ ┻━┻ FILE, OBJ AND LOG REMOVED!$(RESET)"

# *** Re_all *** #
re_all: fclean_all build_dependencies








# ############################################################################ #
#                        DEPENDENCIES AND MODULES                              #
# ############################################################################ #
MINILIBX_DIR	:= libs/minilibx_linux/
MINILIBXCC		:= -I$(MINILIBX_DIR) -L $(MINILIBX_DIR) -lmlx

HEADER 			:= -I$(MINILIBX_DIR)
LIBRARIES		:= \
					-lXext -lX11 -lm		\
					-L$(MINILIBX_DIR) -lmlx \
					-L../mylibc -lmylibc




### SUBMODULES ###
MINILIBX_CODAM_URL	= https://github.com/codam-coding-college/MLX42.git
MINILIBX_CODAM_DIR	= libs/minilibx/minilibx_codam

MINILIBX_LINUX_URL	= https://github.com/42Paris/minilibx-linux.git
MINILIBX_LINUX_DIR	= libs/minilibx/minilibx_linux



################################################################################
### RULES ###
all:	mkdir clone_repos makelibs $(NAME) run

#### Clone Repos ####
clone_repos: libs/minilibx/minilibx_linux
libs/minilibx/minilibx_linux:
	git clone $(MINILIBX_LINUX_URL) libs/minilibx_linux
#	git clone $(MINILIBX_CODAM_URL) libs/minilibx_codam


#### Make Libs ####
make_minilibx:
	$(MAKE) clone_repos || true
	cd libs/minilibx_linux && ./configure
	cd ../../..
	$(MAKE) -C libs/minilibx_linux
















# ############################################################################ #
#                                HELPER                                        #
# ############################################################################ #
# *** Build message of timestamps changes *** #
check_up_to_date:
	if [ ! -f "$(NAME)" ]; then \
		echo "$(GRAY)\n# ############################################################################ #$(RESET)"; \
		echo "$(GRAY)$(NAME)				$(shell date)\n$(YELLOW)STATUS: Bin does not exist. Building...$(RESET)"; \
		echo "$(GRAY)# ############################################################################ #\n$(RESET)"; \
		$(MAKE) build_project; \
	else \
		if find src/ include/ -newer "$(NAME)" -print | grep -q .; then \
			echo "$(GRAY)\n# ############################################################################ #$(RESET)"; \
			echo "$(GRAY)$(NAME)				$(shell date)\n$(RED)STATUS: Some files have changed. Rebuilding...$(RESET)"; \
			echo "$(GRAY)# ############################################################################ #\n$(RESET)"; \
			$(MAKE) build_project; \
		else \
			echo "$(GRAY)\n# ############################################################################ #$(RESET)"; \
			echo "$(GRAY)$(NAME)				$(shell date)\n$(GREEN)STATUS: is up-to-date.$(RESET)"; \
			echo "$(GRAY)# ############################################################################ #\n$(RESET)"; \
			exit 0; \
		fi; \
	fi
#### Check if $(NAME) exists. If not, skip the up-to-date check.
#### If $(NAME) exists, check if any source files are newer.

# *** Hello message *** #
hello:
	@echo "$(GRAY)\n################################################$(RESET)"
	@echo "$(GRAY)# Hello, $(USER)! $(shell date)$(RESET)"
	@echo "$(GRAY)# Welcome to Makefile for:$(BLUE) $(NAME)!$(RESET)"
	@echo "$(GRAY)################################################$(RESET)"
	echo "---"

# *** help message *** #
help:
	@echo "$(GRAY)\n### 1.DESCRIPTION:$(RESET)"
	@echo "$(GREEN)	This is make file for build either PROGRAM, LIBRARY, PROGRAM+LIBRARY with their dependencies connect.$(RESET)"
	@echo "$(GREEN)	- This Makefile is a template for a project with the following structure:$(RESET)"
	@echo "$(GREEN)	1. Headers.h, files all them must be placed inside the folder 'include'.$(RESET)"
	@echo "$(GREEN)	2. Library.a, files all them must be inside of the folder 'libs'.$(RESET)"
	@echo "$(GREEN)	3. The library makefile must be inside of the folder 'libs/mylib'.$(RESET)"
	@echo "$(GRAY)	structure:$(RESET)"
	@echo "$(GREEN)my_project/$(RESET)"
	@echo "$(GREEN)├── include/$(RESET)"
	@echo "$(GREEN)│   ├── main.h$(RESET)"
	@echo "$(GREEN)│   └── mylib.h$(RESET)"
	@echo "$(GREEN)├── libs/$(RESET)"
	@echo "$(GREEN)│   ├── mylib/$(RESET)"
	@echo "$(GREEN)│   │   ├── src/$(RESET)"
	@echo "$(GREEN)│   │   │   └── mylib.c$(RESET)"
	@echo "$(GREEN)│   │   │── objs/$(RESET)"
	@echo "$(GREEN)│   │   │   └── mylib.o$(RESET)"
	@echo "$(GREEN)│   │   └── Makefile <-- (1) Sub-Makefile for the library$(RESET)"
	@echo "$(GREEN)│   └── libmylib.a <-- (2) Library file outside mylib directory$(RESET)"
	@echo "$(GREEN)├── objs/$(RESET)"
	@echo "$(GREEN)│   ├── main.o$(RESET)"
	@echo "$(GREEN)│   ├── main_utils.o$(RESET)"
	@echo "$(GREEN)│   ├── main_utils1.o$(RESET)"
	@echo "$(GREEN)│   └── main_utils2.o$(RESET)"
	@echo "$(GREEN)├── src/$(RESET)"
	@echo "$(GREEN)│   └── main.c$(RESET)"
	@echo "$(GREEN)│       ├── UtilsA/$(RESET)"
	@echo "$(GREEN)│       │   ├── main_utils.c$(RESET)"
	@echo "$(GREEN)│       │   └── main_utils1.c$(RESET)"
	@echo "$(GREEN)│       └── UtilsB/$(RESET)"
	@echo "$(GREEN)│          └── main_utils2.c$(RESET)"
	@echo "$(GREEN)└── Makefile$(RESET)"
	@echo "$(GRAY)\n### 2. USAGE:$(RESET)"
	@echo "$(GREEN)	make [option]$(RESET)"
	@echo "$(GRAY)\n### 3. OPTIONS:$(RESET)"
	@echo "$(GRAY) DEFAULT RULES:$(RESET)"
	@echo "$(GREEN)	1. all, clean, fclean, fclean_all, re$(RESET)"
	@echo "$(GRAY) FUNCTIONS BUILD:$(RESET)"
	@echo "$(GREEN)	2. program_or_lib, program, lib, libs_build $(RESET)"
	@echo "$(GREEN)	3. library_clean, library_fclean, library_re $(RESET)"
	@echo "$(GREEN)	4. hello, check_up_to_date, code_cleaner, files_lns_creator $(RESET)"
	@echo "$(GRAY) LINTING(static/Wflags):$(RESET)"
	@echo "$(GREEN)	5. liting: werror, norm_1, norm_2$(RESET)"
	@echo "$(GRAY) SANITIZATION(static/Asan) & RUNTIME ERROR(dynamic/Valgrind):$(RESET)"
	@echo "$(GREEN)	6. leaks: create_bins, valgrind, asan$(RESET)"
	@echo "$(GRAY) UNIT TESTS:$(RESET)"
	@echo "$(GREEN)	7. testing_alles: run_visualizer, time_and_perfomance$(RESET)"
	@echo "$(GRAY) DEBUGGERS:$(RESET)"
	@echo "$(GREEN)	8. make_dbg, libs_nm_art, debug, compile_debug_files$(RESET)"
	@echo "$(GRAY) HELPERS:$(RESET)"
	@echo "$(GREEN)	9. log_all, check_up_to_date, code_cleaner, folders_build, folder_lns_builder$(RESET)"
	@echo "$(GRAY) EXTRAS:$(RESET)"
	@echo "$(GREEN)	10. bonus\n$(RESET)"
	

# **************************************************************************** #
#                                DEFS/COLORS                               	   #
# **************************************************************************** #
DEL_LINE =		\033[2K
ITALIC =		\033[3m
BOLD =			\033[1m
RESET =			\033[0;39m
GRAY =			\033[0;90m
RED =			\033[0;91m
GREEN =			\033[0;92m
YELLOW =		\033[0;93m
BLUE =			\033[0;94m
MAGENTA =		\033[0;95m
CYAN =			\033[0;96m
WHITE =			\033[0;97m
BLACK =			\033[0;99m
ORANGE =		\033[38;5;209m
BROWN =			\033[38;2;184;143;29m
DARK_GRAY =		\033[38;5;234m
MID_GRAY =		\033[38;5;245m
DARK_GREEN =	\033[38;2;75;179;82m
DARK_YELLOW =	\033[38;5;143m
