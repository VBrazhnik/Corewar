#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vbrazhni <vbrazhni@student.unit.ua>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/24 18:27:10 by vbrazhni          #+#    #+#              #
#    Updated: 2018/12/23 18:27:06 by vbrazhni         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

ASM_NAME = asm
COREWAR_NAME = corewar

CC = gcc
FLAGS = -Wall -Werror -Wextra -O3

# Libraries and Includes

ASM_LIBRARIES = -lftprintf -L$(FT_PRINTF_DIRECTORY)
ASM_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

COREWAR_LIBRARIES = -lncurses -lftprintf -L$(FT_PRINTF_DIRECTORY)
COREWAR_INCLUDES = \
	-I$(HEADERS_DIRECTORY)\
	-I$(LIBFT_HEADERS)\
	-I$(FT_PRINTF_HEADERS)

LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_DIRECTORY = ./ft_printf/libft/
LIBFT_HEADERS = $(LIBFT_DIRECTORY)includes/

FT_PRINTF = $(FT_PRINTF_DIRECTORY)libftprintf.a
FT_PRINTF_DIRECTORY = ./ft_printf/
FT_PRINTF_HEADERS = $(FT_PRINTF_DIRECTORY)includes/

# Headers

HEADERS_DIRECTORY = ./includes/

# asm

ASM_HEADERS_LIST = \
	op.h\
	asm.h\
	asm_error.h\
	asm_asm.h\
	asm_disasm.h
ASM_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(ASM_HEADERS_LIST))

# corewar

COREWAR_HEADERS_LIST = \
	op.h\
	corewar.h\
	corewar_error.h\
	corewar_vs.h
COREWAR_HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(COREWAR_HEADERS_LIST))

# Sources

# asm

ASM_SOURCES_DIRECTORY = ./sources/asm/
ASM_SOURCES_LIST = \
	asm.c\
	filename.c\
	print.c\
	utils.c
ASM_SOURCES = $(addprefix $(ASM_SOURCES_DIRECTORY), $(ASM_SOURCES_LIST))

ASM_ASSEMBLER_SOURCES_DIRECTORY = $(ASM_SOURCES_DIRECTORY)assembler
ASM_ASSEMBLER_SOURCES_LIST = \
	assemble.c\
	init.c\
	get_row.c\
	parse.c\
	parse_is.c\
	parse_utils.c\
	skip.c\
	token.c\
	process_info.c\
	process_code.c\
	process_code_utils.c\
	process_arg.c\
	label.c\
	write.c\
	free.c\
	error.c\
	error_info.c\
	utils.c
ASM_ASSEMBLER_SOURCES = $(addprefix $(ASM_ASSEMBLER_SOURCES_DIRECTORY), $(ASM_ASSEMBLER_SOURCES_LIST))

ASM_DISASSEMBLER_SOURCES_DIRECTORY = $(ASM_SOURCES_DIRECTORY)disassembler
ASM_DISASSEMBLER_SOURCES_LIST = \
	disassemble.c\
	init.c\
	parse_bytecode.c\
	process_code.c\
	process_arg_types.c\
	validate.c\
	warning.c\
	statement.c\
	write.c\
	free.c\
	error.c\
	utils.c
ASM_DISASSEMBLER_SOURCES = $(addprefix $(ASM_DISASSEMBLER_SOURCES_DIRECTORY), $(ASM_DISASSEMBLER_SOURCES_LIST))

# corewar

COREWAR_SOURCES_DIRECTORY = ./sources/corewar/
COREWAR_SOURCES_LIST = \
	corewar.c\
	init.c\
	parse_corewar_args.c\
	parse_corewar_flags.c\
	parse_champion.c\
	find.c\
	parse_types_code.c\
	cursor.c\
	exec.c\
	exec_utils.c\
	check.c\
	validate.c\
	free.c\
	print.c\
	log.c\
	calc.c\
	utils.c
COREWAR_SOURCES = $(addprefix $(COREWAR_SOURCES_DIRECTORY), $(COREWAR_SOURCES_LIST))

COREWAR_OP_SOURCES_DIRECTORY = $(COREWAR_SOURCES_DIRECTORY)op/
COREWAR_OP_SOURCES_LIST = \
	op_add.c\
	op_aff.c\
	op_and.c\
	op_fork.c\
	op_ld.c\
	op_ldi.c\
	op_lfork.c\
	op_live.c\
	op_lld.c\
	op_lldi.c\
	op_or.c\
	op_st.c\
	op_sti.c\
	op_sub.c\
	op_xor.c\
	op_zjmp.c\
	utils.c
COREWAR_OP_SOURCES = $(addprefix $(COREWAR_OP_SOURCES_DIRECTORY), $(COREWAR_OP_SOURCES_LIST))

COREWAR_VS_SOURCES_DIRECTORY = $(COREWAR_SOURCES_DIRECTORY)vs/
COREWAR_VS_SOURCES_LIST =\
	exec.c\
	colors.c\
	configure.c\
	draw.c\
	draw_status.c\
	draw_cursor.c\
	draw_info.c\
	draw_bar.c\
	free.c\
	init.c\
	draw_help.c\
	sounds.c\
	utils.c
COREWAR_VS_SOURCES = $(addprefix $(COREWAR_VS_SOURCES_DIRECTORY), $(COREWAR_VS_SOURCES_LIST))

# Objects

OBJECTS_DIRECTORY = ./objects/

# asm

ASM_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)asm/
ASM_OBJECTS_LIST = $(patsubst %.c, %.o, $(ASM_SOURCES_LIST))
ASM_OBJECTS	= $(addprefix $(ASM_OBJECTS_DIRECTORY), $(ASM_OBJECTS_LIST))

ASM_ASSEMBLER_OBJECTS_DIRECTORY = $(ASM_OBJECTS_DIRECTORY)assembler/
ASM_ASSEMBLER_OBJECTS_LIST = $(patsubst %.c, %.o, $(ASM_ASSEMBLER_SOURCES_LIST))
ASM_ASSEMBLER_OBJECTS	= $(addprefix $(ASM_ASSEMBLER_OBJECTS_DIRECTORY), $(ASM_ASSEMBLER_OBJECTS_LIST))

ASM_DISASSEMBLER_OBJECTS_DIRECTORY = $(ASM_OBJECTS_DIRECTORY)disassembler/
ASM_DISASSEMBLER_OBJECTS_LIST = $(patsubst %.c, %.o, $(ASM_DISASSEMBLER_SOURCES_LIST))
ASM_DISASSEMBLER_OBJECTS	= $(addprefix $(ASM_DISASSEMBLER_OBJECTS_DIRECTORY), $(ASM_DISASSEMBLER_OBJECTS_LIST))

# corewar

COREWAR_OBJECTS_DIRECTORY = $(OBJECTS_DIRECTORY)corewar/
COREWAR_OBJECTS_LIST = $(patsubst %.c, %.o, $(COREWAR_SOURCES_LIST))
COREWAR_OBJECTS	= $(addprefix $(COREWAR_OBJECTS_DIRECTORY), $(COREWAR_OBJECTS_LIST))

COREWAR_OP_OBJECTS_DIRECTORY = $(COREWAR_OBJECTS_DIRECTORY)op/
COREWAR_OP_OBJECTS_LIST = $(patsubst %.c, %.o, $(COREWAR_OP_SOURCES_LIST))
COREWAR_OP_OBJECTS	= $(addprefix $(COREWAR_OP_OBJECTS_DIRECTORY), $(COREWAR_OP_OBJECTS_LIST))

COREWAR_VS_OBJECTS_DIRECTORY = $(COREWAR_OBJECTS_DIRECTORY)vs/
COREWAR_VS_OBJECTS_LIST = $(patsubst %.c, %.o, $(COREWAR_VS_SOURCES_LIST))
COREWAR_VS_OBJECTS	= $(addprefix $(COREWAR_VS_OBJECTS_DIRECTORY), $(COREWAR_VS_OBJECTS_LIST))

# COLORS

GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

.PHONY: all clean fclean re

all: $(COREWAR_NAME) $(ASM_NAME)

$(COREWAR_NAME): $(FT_PRINTF) $(COREWAR_OBJECTS_DIRECTORY) $(COREWAR_OP_OBJECTS_DIRECTORY) $(COREWAR_VS_OBJECTS_DIRECTORY) $(COREWAR_OBJECTS) $(COREWAR_OP_OBJECTS) $(COREWAR_VS_OBJECTS)
	@$(CC) $(FLAGS) $(COREWAR_LIBRARIES) $(COREWAR_INCLUDES) $(COREWAR_OBJECTS) $(COREWAR_OP_OBJECTS) $(COREWAR_VS_OBJECTS) -o $(COREWAR_NAME)
	@echo "\n$(COREWAR_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(COREWAR_NAME): $(GREEN)$(COREWAR_NAME) was created$(RESET)"

$(ASM_NAME): $(FT_PRINTF) $(ASM_OBJECTS_DIRECTORY) $(ASM_ASSEMBLER_OBJECTS_DIRECTORY) $(ASM_DISASSEMBLER_OBJECTS_DIRECTORY) $(ASM_OBJECTS) $(ASM_ASSEMBLER_OBJECTS) $(ASM_DISASSEMBLER_OBJECTS)
	@$(CC) $(FLAGS) $(ASM_LIBRARIES) $(ASM_INCLUDES) $(ASM_OBJECTS) $(ASM_ASSEMBLER_OBJECTS) $(ASM_DISASSEMBLER_OBJECTS) -o $(ASM_NAME)
	@echo "\n$(COREWAR_NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(COREWAR_NAME): $(GREEN)$(ASM_NAME) was created$(RESET)"

$(COREWAR_OBJECTS_DIRECTORY):
	@mkdir -p $(COREWAR_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(COREWAR_OBJECTS_DIRECTORY) was created$(RESET)"

$(COREWAR_OP_OBJECTS_DIRECTORY):
	@mkdir -p $(COREWAR_OP_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(COREWAR_OP_OBJECTS_DIRECTORY) was created$(RESET)"

$(COREWAR_VS_OBJECTS_DIRECTORY):
	@mkdir -p $(COREWAR_VS_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(COREWAR_VS_OBJECTS_DIRECTORY) was created$(RESET)"

$(ASM_OBJECTS_DIRECTORY):
	@mkdir -p $(ASM_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(ASM_OBJECTS_DIRECTORY) was created$(RESET)"

$(ASM_ASSEMBLER_OBJECTS_DIRECTORY):
	@mkdir -p $(ASM_ASSEMBLER_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(ASM_ASSEMBLER_OBJECTS_DIRECTORY) was created$(RESET)"

$(ASM_DISASSEMBLER_OBJECTS_DIRECTORY):
	@mkdir -p $(ASM_DISASSEMBLER_OBJECTS_DIRECTORY)
	@echo "$(COREWAR_NAME): $(GREEN)$(ASM_DISASSEMBLER_OBJECTS_DIRECTORY) was created$(RESET)"

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
