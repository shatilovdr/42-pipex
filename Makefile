#PIPEX_PROJECT_MAKEFILE
include lib/libft/.make
NAME			:=	pipex

# DRAWER_NAME		:= drawer.c tp_initialise.c track_keys.c track_scroll.c draw_img.c put_img.c calculate_rotation_matrix.c put_lines.c get_screen_coordinates.c rotate_coordinates.c
# DRAWER_PATH		:= ./srcs/drawer/
# DRAWER			:= $(addprefix $(DRAWER_PATH), $(DRAWER_NAME))

SRCS_NAME		:=	main.c px_initialize.c execute_commands.c open_files.c check_access.c execution_failures.c wait_childs.c get_command.c find_executable.c free_px.c
SRCS_PATH		:=	./srcs/
SRCS			:=	$(addprefix $(SRCS_PATH), $(SRCS_NAME))

LIBFT_PATH		:=	lib/$(LIBFT_PATH)
LIBFT			:=	$(addprefix $(LIBFT_PATH), $(LIBFT))
LIBFT_SOURSES	:=	$(addprefix $(LIBFT_PATH), $(LIBFT_SOURSES))

all: $(NAME)

%.o: %.c
	@$(CC) $(FLAGS) -c $< -o $@

$(NAME): $(SRCS) $(LIBFT)
	@cc $(FLAGS) $(SRCS) $(LIBFT) $ -o $(NAME)
	@echo "$(GREEN)\n--------------->pipex created successfully!<--------------$(EC)"

$(LIBFT): $(LIBFT_SOURSES)
	@$(MAKE) -C $(LIBFT_PATH)

clean:
	@$(MAKE) clean -C $(LIBFT_PATH)
	@rm -rf $(NAME).dSYM
	@rm -rf .DS_Store
	@echo "$(GREEN)*.o files removed!$(EC)"

fclean: clean
	@rm -f $(NAME)
	@$(MAKE) fclean -C $(LIBFT_PATH)
	@echo "$(GREEN)All files removed!$(EC)"

re: fclean all