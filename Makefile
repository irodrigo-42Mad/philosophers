# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: irodrigo <irodrigo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/24 13:40:37 by irodrigo          #+#    #+#              #
#    Updated: 2021/10/12 14:04:50 by irodrigo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# OS DISCLAIMER #
.DELETE_ON_ERROR:

INCLUDES = -I/usr/include -I. -Iincludes/

NAME = philo
NAMEBONUS = philo_bonus

# SOURCES #
SRC 		= 	ft_main ft_check_error ft_checking ft_strlen ft_time ft_utils ft_utils_lib ft_exec ft_clean ft_philo_init ft_exec_aux
SRCBONUS 	=
HLIBS		=	ft_philo.h headers/ft_errors.h

SRCFIN = $(addsuffix .c, $(SRC))
SRCFINBONUS = $(addsuffix .c, $(SRCBONUS))
OBJS = $(SRCFIN:.c=.o)
OBJSBONUS = $(SRCFINBONUS:.c=.o)

# COMPILER #
CC = gcc -Wall -Wextra -Werror -pthread #-fsanitize=address -g3
#-fsanitize=address

# COLOUR DEFINITION #
BLUE = \033[0;34m
GREEN = \033[1;32m
RESET = \033[0m

# CLEANING INSTRUCTION #
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJS)
	@echo "$(BLUE)==========CREATING $(NAME)==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJS} ${LIBS} -o ${NAME}
	@echo "Done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating $(NAME) file"

bonus:  $(OBJSBONUS)
	@echo "$(BLUE)==========CREATING $(NAMEBONUS)==========$(RESET)"
	@$(CC) $(INCLUDES) ${OBJSBONUS} $(LIBFT) $(MLX) ${LIBS} -o ${NAMEBONUS}
	@echo "Done"
	@echo "$(GREEN)==========WELLDONE==========$(RESET)"
	@echo "Success creating $(NAMEBONUS) file"

normi: fclean
	norminette $(SRCFIN) $(SRCFINBONUS) $(HLIBS)

clean:
	@$(RM) $(OBJS)
	@$(RM) $(OBJSBONUS)
	@echo "$(GREEN)==========REMOVED==========$(RESET)"
	@echo "Success normal cleaning"

fclean: clean
	@$(RM) ${NAME}
	@echo "$(GREEN)==========TOTALLY REMOVED==========$(RESET)"
	@echo "Success deepest cleaning"

re : fclean all

.PHONY: all clean fclean re addsuffix normi
