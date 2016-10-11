CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT =
LIBFT_PATH = libft/
SRC_PATH = src/
SRC =
NAME = fillit

SRC += $(SRC_PATH)alter_map.c
SRC += $(SRC_PATH)free_x.c
SRC += $(SRC_PATH)main.c
SRC += $(SRC_PATH)new_map.c
SRC += $(SRC_PATH)new_tetri.c
SRC += $(SRC_PATH)new_vector.c
SRC += $(SRC_PATH)print_map.c
SRC += $(SRC_PATH)read_source.c
SRC += $(SRC_PATH)redundant_move.c
SRC += $(SRC_PATH)solve_map.c
SRC += $(SRC_PATH)sqrt_ceiling.c
SRC += $(SRC_PATH)update_glist.c
SRC += $(SRC_PATH)evaluate_position.c
SRC += $(SRC_PATH)ft_lstcount.c
SRC += $(SRC_PATH)ft_tabcmp.c

LIBFT += $(LIBFT_PATH)ft_atoi.c
LIBFT += $(LIBFT_PATH)ft_bzero.c
LIBFT += $(LIBFT_PATH)ft_isalnum.c
LIBFT += $(LIBFT_PATH)ft_isalpha.c
LIBFT += $(LIBFT_PATH)ft_isascii.c
LIBFT += $(LIBFT_PATH)ft_isdigit.c
LIBFT += $(LIBFT_PATH)ft_isprint.c
LIBFT += $(LIBFT_PATH)ft_itoa.c
LIBFT += $(LIBFT_PATH)ft_lstadd.c
LIBFT += $(LIBFT_PATH)ft_lstdel.c
LIBFT += $(LIBFT_PATH)ft_lstdelone.c
LIBFT += $(LIBFT_PATH)ft_lstiter.c
LIBFT += $(LIBFT_PATH)ft_lstmap.c
LIBFT += $(LIBFT_PATH)ft_lstnew.c
LIBFT += $(LIBFT_PATH)ft_lstrev.c
LIBFT += $(LIBFT_PATH)ft_memalloc.c
LIBFT += $(LIBFT_PATH)ft_memccpy.c
LIBFT += $(LIBFT_PATH)ft_memchr.c
LIBFT += $(LIBFT_PATH)ft_memcmp.c
LIBFT += $(LIBFT_PATH)ft_memcpy.c
LIBFT += $(LIBFT_PATH)ft_memdel.c
LIBFT += $(LIBFT_PATH)ft_memmove.c
LIBFT += $(LIBFT_PATH)ft_memset.c
LIBFT += $(LIBFT_PATH)ft_putchar.c
LIBFT += $(LIBFT_PATH)ft_putchar_fd.c
LIBFT += $(LIBFT_PATH)ft_putendl.c
LIBFT += $(LIBFT_PATH)ft_putendl_fd.c
LIBFT += $(LIBFT_PATH)ft_putnbr.c
LIBFT += $(LIBFT_PATH)ft_putnbr_fd.c
LIBFT += $(LIBFT_PATH)ft_putstr.c
LIBFT += $(LIBFT_PATH)ft_putstr_fd.c
LIBFT += $(LIBFT_PATH)ft_strcat.c
LIBFT += $(LIBFT_PATH)ft_strchr.c
LIBFT += $(LIBFT_PATH)ft_strclr.c
LIBFT += $(LIBFT_PATH)ft_strcmp.c
LIBFT += $(LIBFT_PATH)ft_strcpy.c
LIBFT += $(LIBFT_PATH)ft_strdel.c
LIBFT += $(LIBFT_PATH)ft_strdup.c
LIBFT += $(LIBFT_PATH)ft_strequ.c
LIBFT += $(LIBFT_PATH)ft_striter.c
LIBFT += $(LIBFT_PATH)ft_striteri.c
LIBFT += $(LIBFT_PATH)ft_strjoin.c
LIBFT += $(LIBFT_PATH)ft_strlcat.c
LIBFT += $(LIBFT_PATH)ft_strlen.c
LIBFT += $(LIBFT_PATH)ft_strmap.c
LIBFT += $(LIBFT_PATH)ft_strmapi.c
LIBFT += $(LIBFT_PATH)ft_strncat.c
LIBFT += $(LIBFT_PATH)ft_strncmp.c
LIBFT += $(LIBFT_PATH)ft_strncpy.c
LIBFT += $(LIBFT_PATH)ft_strnequ.c
LIBFT += $(LIBFT_PATH)ft_strnew.c
LIBFT += $(LIBFT_PATH)ft_strnstr.c
LIBFT += $(LIBFT_PATH)ft_strrchr.c
LIBFT += $(LIBFT_PATH)ft_strsplit.c
LIBFT += $(LIBFT_PATH)ft_strstr.c
LIBFT += $(LIBFT_PATH)ft_strsub.c
LIBFT += $(LIBFT_PATH)ft_strtrim.c
LIBFT += $(LIBFT_PATH)ft_tolower.c
LIBFT += $(LIBFT_PATH)ft_toupper.c

all:
	@echo "-> Compiling C files..."
	gcc $(CFLAGS) -o $(NAME) $(LIBFT) $(SRC)

clean:
	@echo "-> Cleaning libft object files..."
	@rm -f bin/*.o

fclean: clean
	@echo "-> Cleaning $(NAME)..."
	@rm -f $(NAME)

re: fclean all

love: all

$(NAME): love
