CC = gcc -Wall -Werror -Wextra

NAME = push_swap

NAME_CHKR = checker

SRCS = ./srcs/main.c \
	./srcs/engine.c \
	./srcs/exec_ops.c \
	./srcs/ind_hunters.c \
	./srcs/ind_calc.c \
	./srcs/init.c \
	./srcs/insertion_sort.c \
	./srcs/utils.c \
	./srcs/operations.c \
	./srcs/rkrs_hunters.c \
	./srcs/rkrs_calc.c \
	./srcs/error_check.c

SRCS_CHKR = ./chkr/chkr_main.c \
	./chkr/chkr_init.c \
	./chkr/chkr_reader.c \
	./chkr/chkr_exec.c \
	./chkr/chkr_printer.c \
	./chkr/get_next_line/get_next_line.c \
	./chkr/get_next_line/get_next_line_utils.c \
	./srcs/insertion_sort.c \
	./srcs/utils.c \
	./srcs/operations.c \
	./srcs/error_check.c

OBJS = ${SRCS:.c=.o}

OBJS_CHKR = $(SRCS_CHKR:.c=.o)

LIBS = -L./libraries/ft_printf -L./libraries/libft -lftprintf -lft

all: $(NAME)

$(NAME):$(OBJS) lib
	$(CC) -o $(NAME) $(OBJS) $(LIBS)

lib:
	cd ./libraries/ft_printf; make;
	cd ./libraries/libft; make;

$(NAME_CHKR):$(OBJS_CHKR) lib
	gcc ${OBJS_CHKR} -o $(NAME_CHKR) $(LIBS)

clean:
	rm -f $(NAME) $(OBJS)

cleanlib:
	cd ./libraries/ft_printf; make fclean;
	cd ./libraries/libft; make fclean;

cleanchecker:
	rm -f $(NAME_CHKR) $(OBJS_CHKR)

fclean: clean cleanlib cleanchecker

re: clean all

rechecker: cleanchecker checker