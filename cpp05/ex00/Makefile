CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Bureaucrat.cpp  main.cpp
OBJS = $(SRCS:.cpp=.o)

NAME = Bureaucrat

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: clean all

.PHONY: all clean fclean re