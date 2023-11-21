define NEWLINE


endef

CFLAGS+=-Wall -Wextra -Werror -c -MMD -MP
export CFLAGS

NAME:=minishell

FILES:=\
	string/str_has_all\
	string/str_has_any\
	utils/free_all\
	main\

BONUS:=\

SRC_DIR:=src
OBJ_DIR:=obj

OBJ_FILES=$(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(FILES)))
OBJ_FILES_BONUS=$(addsuffix _bonus.o, $(addprefix $(OBJ_DIR)/, $(BONUS))) $(addsuffix .o, $(addprefix $(OBJ_DIR)/, $(filter-out $(BONUS), $(FILES))))

INCLUDES:=-Iinclude -I$(SRC_DIR)

SLIBS:=\
	ft\

SLIBPATHS=$(addsuffix .a, $(join $(addprefix lib/, $(SLIBS)), $(addprefix /lib, $(SLIBS))))

DYLIBS:=\

DYLIBPATHS=$(addsuffix .dylib, $(join $(addprefix lib/, $(DYLIBS)), $(addprefix /lib, $(DYLIBS))))

.PHONY: all clean fclean re bonus debug test

all: $(NAME)

bonus: OBJ_FILES=$(OBJ_FILES_BONUS)
bonus: all

debug: CFLAGS+=-g
debug: bonus all

$(NAME): $(SLIBPATHS) $(DYLIBPATHS) $(OBJ_FILES) $(OBJ_FILES_BONUS)
	cc -o $(NAME) $(OBJ_FILES) $(dir $(addprefix -L./, $(SLIBPATHS))) $(addprefix -l, $(SLIBS)) $(dir $(addprefix -L./, $(DYLIBPATHS))) $(addprefix -l, $(DYLIBS))
	$(foreach dylib, $(DYLIBPATHS), cp $(dylib) .)
	$(foreach dylib, $(DYLIBPATHS), install_name_tool -change $(notdir $(dylib)) @executable_path/$(notdir $(dylib)) $(NAME)$(NEWLINE))
#i hate macs

-include $(OBJ_FILES:.o=.d)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	cc $(CFLAGS) -o $@ $< $(INCLUDES)

%.a:
	$(MAKE) -C $(dir $@)

%.dylib:
	$(MAKE) -C $(dir $@)

clean:
	rm -rf obj
	$(foreach lib, $(dir $(SLIBPATHS)),$(MAKE) -C $(lib) clean$(NEWLINE))
	$(foreach dylib, $(DYLIBPATHS), $(MAKE) -C $(dir $(dylib)) clean$(NEWLINE))

fclean: clean
	rm -f $(NAME) $(notdir $(DYLIBPATHS))

re: fclean all
