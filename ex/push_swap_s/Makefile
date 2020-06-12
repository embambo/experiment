.PHONY: all clean fclean re silent_clean silent_fclean silent_re

NAME = push_swap
RM = /bin/rm -rfv
RMS = /bin/rm -rf
SHARED_F = ../shared_s/
SLIB = slib.a
LIBFT_F = ../libft/
LIBFT = libft.a
OUT = ../
CFILES = push_swap.c
CFILES += basic_sort.c
CFILES += bubble_sort.c
CFILES += operations_helper.c
CFILES += portions.c
CFILES += portions_helper.c
CFILES += push_back_to_a.c
CFILES += rr_multi.c
CFILES += rra_multi.c
CFILES += sort_5_helper.c
CFILES += push_to_b_helper.c
CFILES += operations.c 
CFILES += operations3.c
CFILES += operations2.c 
CFILES += parse_args.c
CFILES += is_sorted.c
OFILES = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@if [ ! -e $(SHARED_F)$(SLIB) ]; then \
		make silent_re -C $(SHARED_F); \
	fi
	@if [ ! -e $(LIBFT_F)$(LIBFT) ]; then \
		make silent_re -C $(LIBFT_F); \
	fi
	@if [ -e $(SHARED_F)$(SLIB) -a -e $(LIBFT_F)$(LIBFT) ]; then \
		echo "$(NAME) compiling... \c"; \
		gcc -Wall -Wextra -Werror -c $(CFILES); \
		gcc -Wall -Wextra -Werror $(OFILES) $(SHARED_F)$(SLIB) $(LIBFT_F)$(LIBFT) -o $(NAME); \
		cp $(NAME) $(OUT); \
		echo "$(NAME) compiled"; \
	else \
		echo "something wrong with $(LIBFT) or/and $SLIB) libraries"; \
	fi

clean:
	@$(RM) $(OFILES) | wc -l | tr '\n' ' ' && echo ft_*.o files deleted

fclean: clean
	@$(RM) $(NAME) | wc -l | tr '\n' ' ' && echo $(NAME) deleted

re: fclean all

silent_clean:
	@$(RMS) $(OFILES)

silent_fclean: silent_clean
	@$(RMS) $(NAME)

silent_re: silent_fclean alll
