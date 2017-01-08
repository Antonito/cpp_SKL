##
## rules.mk for Makefile in /home/bache_a/work/perso/Makefile/mk
##
## Made by Antoine Baché
## Login   <bache_a@epitech.net>
##
## Started on  Fri Nov 25 20:36:37 2016 Antoine Baché
## Last update Sun Jan  8 03:42:11 2017 Antoine Baché
##

include $(MK_COMMON_DIR)./objs.mk

NAME_EXTENSION=	$(suffix $(NAME))

# Messages
include $(MK_COMMON_DIR)./strings.mk

# Rules
$(NAME):	$(OBJ)
ifeq ($(NAME_EXTENSION),.a)
		@$(RANLIB) $(NAME) $(OBJ) && $(OK_GEN) || $(KO_GEN)
else
		@$(LD) $(OBJ) $(LDFLAGS) -o $(NAME) && $(OK_LINK) || $(KO_LINK)
endif

# Compiles ASM files
$(OBJ_DIR)%.o:	%.s
		@$(AS) $(ASFLAGS) -o $@ $< && \
		$(OK_COMP)$<$(END_LINE) || $(KO_COMP)$<$(END_LINE)

# Compiles C files
$(OBJ_DIR)%.o:	%.c
		@$(CC) $(CFLAGS) -c -o $@ $< && \
		$(OK_COMP)$<$(END_LINE) || $(KO_COMP)$<$(END_LINE)

# Compiles C++ files
$(OBJ_DIR)%.o:	%.cpp
		@$(CXX) $(CXXFLAGS) -c -o $@ $< && \
		$(OK_COMP)$<$(END_LINE) || $(KO_COMP)$<$(END_LINE)

all:		$(NAME)

# Prints informations
infos:
		@$(INFOS)

# Removes binary + call clean
fclean:		CALLER="fclean"
fclean:		clean
		@$(RM) $(NAME)
		@$(RM_BIN)

# Removes .o files
clean:
		@$(RM) $(OBJ)
		@$(RM_OBJ)

# Calls fclean and all
re:		fclean all

# Start the generated binary
run:
ifeq ($(MODE),test)
		@export LD_LIBRARY_PATH=$(ROOT_DIR)/deps/criterion/ ; ./$(NAME) --verbose
else
		@./$(NAME)
endif

# Strip the generated binary
strip:
		@$(STRIP) $(NAME) && $(STRIP_OK) || $(STRIP_KO)

.PHONY: all clean fclean re run
