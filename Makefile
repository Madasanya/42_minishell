CC			= gcc
CFLAGS		= -g3 -Wall -Wextra -Werror
RM			= rm -rf
SRCD		= ./srcs/


UNAME = $(shell uname)
#echo $(UNAME)

ifeq ($(UNAME), Linux)

SRC			=	builtin/src/ft_builtin_cd.c builtin/src/ft_builtin_echo.c builtin/src/ft_builtin_env.c builtin/src/ft_builtin_exit.c builtin/src/ft_builtin_exit_utils.c builtin/src/ft_builtin_export.c \
				builtin/src/ft_builtin_export_utils.c builtin/src/ft_builtin_init.c builtin/src/ft_builtin_pwd.c builtin/src/ft_builtin_unset.c builtin/src/ft_builtin_utils.c builtin/src/ft_builtin_env_utils.c \
				utils/src/ft_check_path_env_linux.c utils/src/ft_check_symlink.c lexor/src/ft_lexor_env_check.c executor/src/ft_executor.c utils/src/ft_utils_free.c \
				executor/src/ft_heredoc.c executor/src/ft_heredoc_utils.c initiator/src/ft_initiator_utils.c initiator/src/ft_initiator.c lexor/src/ft_lexor.c lexor/src/ft_lexor_handlers.c \
				lexor/src/ft_lexor_utils.c lexor/src/ft_lexor_utils2.c parser/src/ft_parser.c parser/src/ft_parser_handler.c parser/src/ft_parser_utils.c parser/src/ft_parser_path_finder.c executor/src/ft_pipex.c \
				executor/src/ft_pipex_error_handling.c executor/src/ft_pipex_filecheck.c executor/src/ft_pipex_utils.c utils/src/ft_rtoa_path.c initiator/src/ft_signal_handler.c utils/src/ft_utils.c \
				utils/src/ft_utils_join.c utils/src/ft_utils_num.c utils/src/get_next_line.c main.c

endif

ifeq ($(UNAME), Darwin)
SRC			=	builtin/src/ft_builtin_cd.c builtin/src/ft_builtin_echo.c builtin/src/ft_builtin_env.c builtin/src/ft_builtin_exit.c builtin/src/ft_builtin_exit_utils.c builtin/src/ft_builtin_export.c \
				builtin/src/ft_builtin_export_utils.c builtin/src/ft_builtin_init.c builtin/src/ft_builtin_pwd.c builtin/src/ft_builtin_unset.c builtin/src/ft_builtin_utils.c builtin/src/ft_builtin_utils_env.c \
				utils/src/ft_check_path_env_mac.c utils/src/ft_check_symlink.c lexor/src/ft_lexor_env_check.c executor/src/ft_executor.c utils/src/ft_utils_free.c\
				executor/src/ft_heredoc.c executor/src/ft_heredoc_utils.c initiator/src/ft_initiator_utils.c initiator/src/ft_initiator.c lexor/src/ft_lexor.c lexor/src/ft_lexor_handlers.c \
				lexor/src/ft_lexor_utils.c lexor/src/ft_lexor_utils2.c parser/src/ft_parser.c parser/src/ft_parser_handler.c parser/src/ft_parser_utils.c parser/src/ft_parser_path_finder.c executor/src/ft_pipex.c \
				executor/src/ft_pipex_error_handling.c executor/src/ft_pipex_filecheck.c executor/src/ft_pipex_utils.c utils/src/ft_rtoa_path.c initiator/src/ft_signal_handler.c utils/src/ft_utils.c \
				utils/src/ft_utils_join.c utils/src/ft_utils_num.c utils/src/get_next_line.c main.c
endif


# Command to add the source folder prefix (instead of having it added manually to SRC)
SRCF		= $(addprefix $(SRCD),$(SRC))
OBJD		= ./obj/
# for every SRCF file which is an .c file an o file will be created according to the implicit rule (see $(OBJD)%.o: $(SRCD)%.c)
OBJF		= $(SRCF:$(SRCD)%.c=$(OBJD)%.o)
BUILD		= $(OBJF:$(OBJD)%.o)

NAME		= minishell
HEADD		= ./incl/
HEADF		= minishell.h

LIBFTD		= ./libft/
LIBFT_OBJD	= objs
LIBFT_SRCD	= srcs/
LIBFTL		= libft.a

LIBFT_OBJF    = ${LIBFTD}${LIBFT_OBJD}/*.o
LIBFT_MAKE    = make -C ${LIBFTD}



#if to the respective c file in the source directory no matching o file in the object
#directory is available, then create it according to the following rules:
#Note: the object directory will only be created if not existing already. -p flag throws no errors when already there
$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)/builtin/src
	@mkdir -p $(OBJD)/lexor/src
	@mkdir -p $(OBJD)/parser/src
	@mkdir -p $(OBJD)/executor/src
	@mkdir -p $(OBJD)/initiator/src
	@mkdir -p $(OBJD)/utils/src
	$(CC) $(CFLAGS) -I ${HEADD} -c -o $@ $<

# $(NAME):	${OBJF}
# 			make libftmake
# 			$(CC) $(CFLAGS) $(SRCF) -o $(NAME) $(HEADD)$(HEADF) $(LIBFTD)$(LIBFTL)
$(NAME):	${OBJF}
			make libftmake
			$(CC) $(CFLAGS) $(SRCF) -o $(NAME) -I $(HEADD) $(LIBFTD)$(LIBFTL) -L /usr/local/lib -I /usr/local/include -lreadline


all:		${NAME}

libftmake:
			${LIBFT_MAKE}

clean:
			${RM} ${OBJD}
			make -C ${LIBFTD} clean

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFTD}${LIBFTL}
			@${RM} ${HEADD}minishell.h.gch
			@rm -rf minishell.dSYM

re:			fclean all

.PHONY:		all clean fclean re