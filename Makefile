ifeq ($(shell uname), Linux)
	CXX = g++
else
	CXX = c++
endif

SDL2_LIB = $(shell sdl2-config --cflags --libs) -lSDL2_image

OPENGL_LIB = -lGLU -lGL 

RM = rm -rf
CXXFLAGS = -Werror -Wall -Wextra -Wfatal-errors
CXXFLAGS += -std=c++11 -pedantic
CXXFLAGS += -I$(INC_DIR) 
CXXFLAGS += -g
#CXXFLAGS += -g3 -fsanitize=address

LDFLAGS = $(SDL2_LIB) $(OPENGL_LIB)

SRC_DIR = ./

_SRC =	main.cpp\
	Camera.cpp\
     	Cube.cpp\
    	Material.cpp\
      	MessageBus.cpp\
       	SkyBox.cpp\
	redirectconsole.cpp\
	Console.cpp\
      	Ground.cpp\
      	Mesh.cpp\
  	Object.cpp\
  	clock.cpp\
     	sdlglutils.cpp\
	Context.cpp\
      	Light.cpp\
     	Message.cpp\
     	Scene.cpp\

SRC = $(addprefix $(SRC_DIR), $(_SRC))

INC_DIR = ./
HEADER=	

INC = $(addprefix $(INC_DIR), $(HEADER))

NAME = cagan 

OBJ_DIR = obj/
_OBJ = $(_SRC:.cpp=.o)
OBJ = $(addprefix $(OBJ_DIR), $(_OBJ))


.PHONY: all clean fclean re run leak json

all: $(NAME)

#TODO a corriger et ajouter la dependance
$(LIB_JSON):
	$(MAKE) -C $(JSON_DIR)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(OBJ_DIR)%.o : $(SRC_DIR)%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(NAME): $(OBJ_DIR) $(OBJ) 
	$(CXX) $(CXXFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

run:
	./$(NAME)

leak: CXXFLAGS = -Werror -Wall -Wextra  -pedantic -g3
leak: re
	leaks -atExit -- ./$(NAME)

clean:
	$(RM) $(OBJ_DIR)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(NAME).dSYM
	make -C $(JSON_DIR) fclean

re: fclean all

# normalize file
lint: 
	clang-format --style=file -i  $(INC)  $(SRC) 
