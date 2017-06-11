# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nbeny <nbeny@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/11 13:41:33 by nbeny             #+#    #+#              #
#    Updated: 2017/06/11 13:41:40 by nbeny            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

# LIBFT
LFTPATH = libft/
LFTIPATH = -I $(LFTPATH)
LFT = -L $(LFTPATH) -lft


OBJPATH = obj
SRCPATH = .
INCLUDE = -I ./

# MLX
CC = gcc
GRAPHLIB = -L ./minilibx -lmlx -framework openGl -framework AppKit
LIBX =	-I /usr/X11/include -L /usr/X11/lib -lX11 -lmlx -lXext

LIBS = $(LFT) $(GRAPHLIB)
INCLUDES = $(INCLUDE) $(LFTIPATH) $(GRAPHINC)


BASEFLAGS = -Wall -Wextra
CFLAGS = $(BASEFLAGS) -Werror


LFTCALL = all
LFTRE = re


SRCSFILES = ft_array.c ft_check.c ft_coord2d.c ft_coord3d.c \
				ft_error.c ft_fdf.c ft_init.c get_next_line.c \
				ft_line.c ft_init2.c ft_free.c

SRC = $(addprefix $(SRCPATH)/,$(SRCSFILES))
OBJECTS = $(SRC:$(SRCPATH)/%.c=$(OBJPATH)/%.o)

RM = rm -rf

Y = \033[0;33m
R = \033[0;31m
G = \033[0;32m
E = \033[39m

all: l $(NAME)

$(NAME): $(OBJECTS)
	@echo "$(Y)[COMPILING FDF] $(G) $(CC) -o $@ $(CFLAGS) objs.o $(LIBS) $(E)"
	@$(CC) -o $@ $(CFLAGS) $(OBJECTS) $(INCLUDES) $(LIBS)
	@echo "$(Y)[COMPILING FDF DONE]$(E)"

$(OBJECTS): $(OBJPATH)/%.o : $(SRCPATH)/%.c
	@mkdir -p $(dir $@)
	$(CC) -o $@ $(CFLAGS) $(INCLUDES) -c $<

clean:
	$(RM) $(OBJPATH)

fclean: clean
	$(RM) $(NAME)

l:
	@echo "$(Y)[COMPILING LIBFT] $(G) make -C $(LFTPATH) $(LFTCALL) $(E)"
	@make -C $(LFTPATH) $(LFTCALL)
	@echo "$(Y)[COMPILING LIBFT DONE]$(E)"

re: fclean all
