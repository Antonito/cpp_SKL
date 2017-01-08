##
## defs.mk for Makefile in /home/bache_a/work/perso/Makefile
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Nov 25 19:18:58 2016 Antoine Baché
## Last update Sun Jan  8 03:23:43 2017 Antoine Baché
##

# Commands definitions
RM:=		rm -f
ECHO:=		echo -ne
RANLIB:=	ar rcs
CP:=		cp
CHDIR:=		cd
IGNORE:=	2> /dev/null ||:
STRIP:=		strip

# Compilation and link definitions
LD=		gcc
CC=		gcc

## C
C_VER:=		gnu99
CFLAGS+=	-W					\
		-Wall					\
		-Wextra					\
		-Werror					\
		-std=$(C_VER)
