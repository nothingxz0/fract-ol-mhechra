NAME = fractol
CC = cc
CFLAGS = -O3 -pthread -Wall -Wextra -Werror -g
LDFLAGS = -L/home/slasfar/include/minilibx/ -L$(PRINTF_DIR) -lmlx -lX11 -lXext -lm -lftprintf

# ft_printf: 
PRINTF_DIR = ft_printf
PRINF_LIB = $(PRINTF_DIR)/libftprintf.a

SRCS = main.c \
    event_manager.c \
    check_model.c \
    color.c \
    frac_init.c \
    free_all.c \
    ft_atod.c \
    handle_number.c \
    math.c \
    render_frac.c \
    scale.c \
    usage.c \
    utils.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(PRINF_LIB):
	@echo "Compiling ft_printf object files ..."
	@make -C $(PRINTF_DIR) > /dev/null

$(NAME): $(OBJS) $(PRINF_LIB)
	@echo "Linking $(NAME)..."
	@$(CC) $(OBJS) $(LDFLAGS) -o $(NAME)

%.o: %.c
	@echo "Compiling object file $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJS)
	@make -C $(PRINTF_DIR) clean > /dev/null

fclean: clean
	@echo "Cleaning executables..."
	@rm -f $(NAME)
	@make -C $(PRINTF_DIR) fclean > /dev/null

re: fclean all

.PHONY: all clean fclean re