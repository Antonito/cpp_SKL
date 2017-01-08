##
## objs.mk for Makefile in /home/bache_a/work/perso/Makefile/mk
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Nov 25 20:29:09 2016 Antoine Baché
## Last update Sun Jan  8 03:51:10 2017 Antoine Baché
##

OBJ_DIR:=		./

OBJ_AS:=	$(SRC:%.s=$(OBJ_DIR)%.o)
OBJ_C:=		$(SRC:%.c=$(OBJ_DIR)%.o)
OBJ_CPP:=	$(SRC:%.cpp=$(OBJ_DIR)%.o)

OBJ:=		$(filter %.o, $(OBJ_AS) $(OBJ_C) $(OBJ_CPP))

ifneq ($(filter %.cpp, $(SRC)),)
LDFLAGS+=	-lstdc++
endif
