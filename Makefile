Name = push_swap

Files = push_swap.c mandatory/max_int.c mandatory/big_sorting.c \
		mandatory/small_sorting.c mandatory/push_swap_utils.c \
		mandatory/check_functions.c mandatory/instructions/ra_rb_rr.c \
		mandatory/instructions/rra_rrb_rrr.c mandatory/instructions/sa_sb_ss_pa_pb.c \

BFiles = checker.c Bonus/max_int_bonus.c Bonus/gnl/get_next_line.c \
		Bonus/gnl/get_next_line_utils.c  Bonus/push_swap_utils_bonus.c \
		Bonus/check_functions_bonus.c Bonus/instructions/rra_rrb_rrr_bonus.c\
		Bonus/instructions/ra_rb_rr_bonus.c Bonus/instructions/sa_sb_ss_pa_pb_bonus.c \

OBJ = ${Files:.c=.o}
BOBJ = ${BFiles:.c=.o}

All : $(Name)

$(Name) : $(OBJ)
	cc -Wall -Wextra -Werror $(OBJ) -o $(Name)

bonus : $(BOBJ)
	cc -Wall -Wextra -Werror $(BOBJ) -o checker

clean :
	rm -f $(OBJ) $(BOBJ)

fclean : clean
	rm -f push_swap checker

re : fclean All