# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mtrautne <mtrautne@student.42wolfsburg.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/16 14:44:41 by estruckm          #+#    #+#              #
#    Updated: 2023/04/26 13:20:23 by mtrautne         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
# Name des kompilierten Programms
SRCS	=	ft_numlen_bonus.c ft_itoa.c ft_putendl_fd.c ft_putnbr_fd.c ft_putstr_fd.c ft_putchar_fd.c ft_striteri.c ft_strmapi.c ft_split.c ft_strtrim.c ft_strjoin.c ft_substr.c ft_strdup.c ft_memmove.c ft_atoi.c ft_calloc.c ft_strnstr.c ft_memset.c ft_memcmp.c ft_memchr.c ft_strncmp.c ft_strrchr.c ft_strchr.c ft_toupper.c ft_tolower.c ft_strlcat.c ft_strlcpy.c ft_memcpy.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c ft_isprint.c ft_strlen.c ft_itoa_s.c ft_free_integer_array.c ft_free_char_array.c ft_putstring.c ft_flagcheck.c ft_numlen_base.c ft_printf.c ft_putchar_printf.c ft_puthex.c ft_putnbr_base.c ft_putpointer.c ft_putstr_printf.c
# Hier alle zu kompilierenden .c-Dateien erfassen
SRCS_BONUS = ft_lstmap.c ft_lstiter.c ft_lstclear.c ft_lstdelone.c ft_lstadd_back.c ft_lstlast.c ft_lstadd_front.c ft_lstnew.c ft_lstsize.c
OBJS	=	${SRCS:.c=.o}
OBJS_BONUS = $(SRCS_BONUS:.c=.o)
# Damit nur veränderte .c-Dateien in .o-Dateien kompiliert werden
RM		=	rm -f
# -f (force) macht fclean jederzeit ausführbar (auch ohne .o-Dateien)
CC		=	cc
# Kompiliersprache
CFLAGS	=	-Wall -Wextra -Werror

%.o:%.c
	@$(CC) $(CFLAGS) -o $@ -c $<

all:		${NAME}
# Die verwendeten Flags
${NAME}:	${OBJS} ${OBJS_BONUS}
	@ar rcs $(NAME) $(OBJS) $(OBJS_BONUS)

bonus: 		$(OBJS_BONUS)
	@ar rcs ${NAME} ${OBJS_BONUS}
clean:
	@${RM} ${OBJS} ${OBJS_BONUS}
# Löscht die .o-Dateien
fclean:		clean
	@${RM} ${NAME}
# Löscht die .o- und exe-Dateien
re:			fclean all
# Löscht und rekompiliert
.PHONY:		all clean fclean re
# Führt die Befehle aus, auch wenn eine gleichnamige Datei existiert
