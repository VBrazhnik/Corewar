#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 18:27:10 by vbrazhni          #+#    #+#              #
#    Updated: 2018/10/24 18:27:11 by vbrazhni         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

COREWAR_NAME = corewar
ASM_NAME = asm

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3

COREWAR_LIBRARIES = -lftprintf -L$(FT_PRINTF_DIRECTORY)
COREWAR_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

ASM_LIBRARIES = -lftprintf -L$(FT_PRINTF_DIRECTORY)
ASM_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./ft_printf/libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

FT_PRINTF = $(FT_PRINTF_DIRECTORY)libftprintf.a
FT_PRINTF_DIRECTORY = ./ft_printf/
FT_PRINTF_HEADERS = $(FT_PRINTF_DIRECTORY)includes/

HEADERS_DIRECTORY = ./includes/

COREWAR_HEADERS_LIST = \
	op.h\
	corewar.h\
	corewar_error_msg.h\
	vs.h
COREWAR_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(COREWAR_HEADERS_LIST))

ASM_HEADERS_LIST = \
	op.h
ASM_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(ASM_HEADERS_LIST))

COREWAR_SOURCES_DIRECTORY = ./sources/corewar/
COREWAR_SOURCES_LIST = \
	corewar.c\
	init.c\
	parse_args.c\
	parse_flags.c\
	parse_champion.c\
	find.c\
	utils.c\
	print.c
COREWAR_SOURCES = $(addprefix $(COREWAR_SOURCES_DIRECTORY), $(COREWAR_SOURCES_LIST))

VS_SOURCES_DIRECTORY = ./sources/corewar/vs/
VS_SOURCES_LIST = \
	init.c
VS_SOURCES = $(addprefix $(VS_SOURCES_DIRECTORY), $(VS_SOURCES_LIST))

ASM_SOURCES_DIRECTORY = ./sources/asm/
ASM_SOURCES_LIST = 
ASM_SOURCES = $(addprefix $(ASM_SOURCES_DIRECTORY), $(ASM_SOURCES_LIST))

OBJECTS_DIRECTORY = ./objects/

COREWAR_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)corewar/
COREWAR_OBJECTS_LIST = $(patsubst %.c, %.o, $(COREWAR_SOURCES_LIST))
COREWAR_OBJECTS	= $(addprefix $(COREWAR_OBJECTS_DIRECTORY), $(COREWAR_OBJECTS_LIST))

VS_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)corewar/vs/
VS_OBJECTS_LIST = $(patsubst %.c, %.o, $(VS_SOURCES_LIST))
VS_OBJECTS	= $(addprefix $(VS_OBJECTS_DIRECTORY), $(VS_OBJECTS_LIST))

ASM_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)asm/
ASM_OBJECTS_LIST = $(patsubst %.c, %.o, $(ASM_SOURCES_LIST))
ASM_OBJECTS	= $(addprefix $(ASM_OBJECTS_DIRECTORY), $(ASM_OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(COREWAR_NAME)

$(COREWAR_NAME): $(FT_PRINTF) $(COREWAR_OBJECTS_DIRECTORY) $(VS_OBJECTS_DIRECTORY) $(COREWAR_OBJECTS) $(VS_OBJECTS)
	@$(CC) $(FLAGS) $(COREWAR_LIBRARIES) $(COREWAR_INCLUDES) $(COREWAR_OBJECTS) $(VS_OBJECTS) -o $(COREWAR_NAME)
	@echo "\n$(COREWAR_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(COREWAR_NAME): $(GREEN)$(COREWAR_NAME) was created$(RESET)"

$(ASM_NAME): $(FT_PRINTF) $(ASM_OBJECTS_DIRECTORY) $(ASM_OBJECTS)
	@$(CC) $(FLAGS) $(ASM_LIBRARIES) $(ASM_INCLUDES) $(ASM_OBJECTS) -o $(ASM_NAME)
	@echo "\n$(COREWAR_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(COREWAR_NAME): $(GREEN)$(ASM_NAME) was created$(RESET)"

$(COREWAR_OBJECTS_DIRECTORY):
	@mkdir -p $(COREWAR_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(COREWAR_OBJECTS_DIRECTORY) was created$(RESET)"

$(VS_OBJECTS_DIRECTORY):
	@mkdir -p $(VS_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(VS_OBJECTS_DIRECTORY) was created$(RESET)"

$(ASM_OBJECTS_DIRECTORY):
	@mkdir -p $(ASM_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(ASM_OBJECTS_DIRECTORY) was created$(RESET)"

$(COREWAR_OBJECTS_DIRECTORY)%.o : $(COREWAR_SOURCES_DIRECTORY)%.c $(COREWAR_HEADERS)
	@$(CC) $(FLAGS) -c $(COREWAR_INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(ASM_OBJECTS_DIRECTORY)%.o : $(ASM_SOURCES_DIRECTORY)%.c $(ASM_HEADERS)
	@$(CC) $(FLAGS) -c $(ASM_INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(FT_PRINTF):
	@echo "$(COREWAR_NAME): $(GREEN)Creating $(FT_PRINTF)...$(RESET)"
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY)

clean:
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(COREWAR_NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@$(MAKE) -sC $(FT_PRINTF_DIRECTORY) fclean
	@echo "$(COREWAR_NAME): $(RED)$(FT_PRINTF) was deleted$(RESET)"
	@rm -f $(ASM_NAME)
	@echo "$(COREWAR_NAME): $(RED)$(ASM_NAME) was deleted$(RESET)"
	@rm -f $(COREWAR_NAME)
	@echo "$(COREWAR_NAME): $(RED)$(COREWAR_NAME) was deleted$(RESET)"

re:
	@$(MAKE) fclean
	@$(MAKE) all