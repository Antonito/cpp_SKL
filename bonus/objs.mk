##
## objs.mk for Makefile in /home/bache_a/work/perso/Makefile/mk
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Nov 25 20:29:09 2016 Antoine Baché
## Last update Wed Jan  4 11:38:09 2017 Antoine Baché
##

OBJ_DIR:=		./obj/

OBJ_AS:=	$(SRC:%.s=$(OBJ_DIR)%.o)
OBJ_C:=		$(SRC:%.c=$(OBJ_DIR)%.o)
OBJ_CPP:=	$(SRC:%.cpp=$(OBJ_DIR)%.o)

OBJ:=		$(filter %.o, $(OBJ_AS) $(OBJ_C) $(OBJ_CPP))

ifneq ($(filter %.cpp, $(SRC)),)
LDFLAGS+=	-lstdc++
endif
