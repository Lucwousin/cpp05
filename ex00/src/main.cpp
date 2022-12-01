/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 21:51:38 by lsinke        #+#    #+#                 */
/*   Updated: 2022/09/29 21:51:38 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <iostream>

enum ErrorState {
	SUCCESS,
	TOO_HIGH,
	TOO_LOW
};

static ErrorState	testCtor(const std::string &name, int grade) {
	try {
		Bureaucrat crat(name, grade);
	} catch (const Bureaucrat::GradeTooHighException &e) {
		return (TOO_HIGH);
	} catch (const Bureaucrat::GradeTooLowException &e) {
		return (TOO_LOW);
	}
	return (SUCCESS);
}

static ErrorState	testCrement(Bureaucrat ref, bool in) {
	int oldGrade = ref.getGrade();

	try {
		if (in)
			ref.incrementGrade();
		else
			ref.decrementGrade();
	} catch (const Bureaucrat::GradeTooHighException &e) {
		return (TOO_HIGH);
	} catch (const Bureaucrat::GradeTooLowException &e) {
		return (TOO_LOW);
	}

	assert(ref.getGrade() == (in ? oldGrade - 1 : oldGrade + 1));
	return (SUCCESS);
}

int	main() {
	for (int i = 1; i <= 150; i++)
		assert(testCtor("crat", i) == SUCCESS);

	assert(testCtor("crat", 0) == TOO_HIGH);
	assert(testCtor("crat", 151) == TOO_LOW);

	assert(testCrement(Bureaucrat("hi", 1), false) == SUCCESS);
	assert(testCrement(Bureaucrat("lo", 150), true) == SUCCESS);
	assert(testCrement(Bureaucrat("hi", 1), true) == TOO_HIGH);
	assert(testCrement(Bureaucrat("lo", 150), false) == TOO_LOW);

	Bureaucrat crat("bobby", 75);
	std::cout << crat << std::endl;
}
