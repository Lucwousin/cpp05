# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: lsinke <lsinke@student.codam.nl>             +#+                      #
#                                                    +#+                       #
#    Created: 2022/06/23 19:36:26 by lsinke        #+#    #+#                  #
#    Updated: 2022/06/23 19:36:26 by lsinke        ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := bureaucrat_ex03

CC := c++

CFLAGS += -Wall -Werror -Wextra
CFLAGS += -std=c++98
CFLAGS += -g

SRCD :=	src/
SRCS :=	main.cpp					\
		Bureaucrat.cpp				\
		AForm.cpp					\
		ShrubberyCreationForm.cpp	\
		RobotomyRequestForm.cpp		\
		PresidentialPardonForm.cpp	\
		Intern.cpp
SRCP :=	$(addprefix $(SRCD), $(SRCS))

OBJD :=	obj/
OBJS :=	$(SRCS:.cpp=.o)
OBJP :=	$(addprefix $(OBJD), $(OBJS))

INCD :=	include/
INCS :=	Bureaucrat.hpp				\
		AForm.hpp					\
		ShrubberyCreationForm.hpp	\
		RobotomyRequestForm.hpp		\
		PresidentialPardonForm.hpp	\
		Intern.hpp
INCP := $(addprefix $(INCD), $(INCS))
CFLAGS += -I $(INCD)

all: $(NAME)

$(OBJD)%.o: $(SRCD)%.cpp $(INCP)
	@mkdir -p $(@D)
	@echo "Compiling: $<"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJP)
	@echo "Compiling main executable"
	@$(CC) $(CFLAGS) $(OBJP) -o $(NAME)

clean:
	@rm -rf $(OBJD)
	@echo "Done cleaning $(CURDIR)/$(OBJD)"
	@rm -f *_shrubbery

fclean: clean
	@rm -f $(NAME)
	@echo "Done cleaning executable $(CURDIR)/$(NAME)"

re: fclean
	@$(MAKE)

.PHONY: all clean fclean re