#PIPEX_PROJECT_MAKEFILE
include lib/libft/.make
NAME			:=	pipex

SRCS_NAME		:=	main.c check_inputs.c px_initialize.c execute_commands.c open_files.c check_access.c get_command.c \
					find_executable.c cmd_args_parser.c wait_childs.c free_px.c execution_failures.c 
SRCS_PATH		:=	./srcs/mandatory/
SRCS			:=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))
OBJS			:= $(SRCS:.c=.o)

BNS_SRCS_NAME	:=	main_bonus.c check_inputs_bonus.c here_doc_bonus.c edit_args_bonus.c px_initialize_bonus.c \
					execute_commands_bonus.c open_files_bonus.c check_access_bonus.c get_command_bonus.c \
					find_executable_bonus.c cmd_args_parser_bonus.c wait_childs_bonus.c free_px_bonus.c \
					execution_failures_bonus.c 
BNS_SRCS_PATH	:=	./srcs/bonus/
BNS_SRCS		:=	$(addprefix $(BNS_SRCS_PATH), $(BNS_SRCS_NAME))
BNS_OBJS		:= $(BNS_SRCS:.c=.o)


LIBFT_PATH		:=	lib/$(LIBFT_PATH)
LIBFT			:=	$(addprefix $(LIBFT_PATH), $(LIBFT))
LIBFT_SOURSES	:=	$(addprefix $(LIBFT_PATH), $(LIBFT_SOURSES))

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): .mandatory
	@echo "$(GREEN)\n--------------->pipex created successfully!<--------------$(EC)"

.mandatory: $(OBJS) $(LIBFT)
	@cc $(FLAGS) $(OBJS) $(LIBFT) $ -o $(NAME)
	@touch .mandatory
	@rm -rf .bonus

bonus: .bonus
	@echo "$(GREEN)\n------------->pipex_bonus created successfully!<------------$(EC)"

.bonus: $(BNS_OBJS) $(LIBFT)
	@cc $(FLAGS) $(BNS_OBJS) $(LIBFT) $ -o $(NAME)
	@touch .bonus
	@rm -rf .mandatory

$(LIBFT): $(LIBFT_SOURSES)
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@rm -rf $(OBJS)
	@rm -rf $(BNS_OBJS)
	@rm -rf .mandatory
	@rm -rf .bonus
	@rm -rf $(NAME).dSYM
	@rm -rf .DS_Store
	@echo "$(GREEN)*.o files removed!$(EC)"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(GREEN)All files removed!$(EC)"

re: fclean all