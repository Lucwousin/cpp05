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
#include <Form.hpp>
#include <iostream>

enum ErrorState {
	SUCCESS,
	TOO_HIGH,
	TOO_LOW
};

static ErrorState	testFormCtor(const std::string &name, int sign, int exec) {
	try {
		Form form(name, sign, exec);
	} catch (const Form::GradeTooHighException &e) {
		return (TOO_HIGH);
	} catch (const Form::GradeTooLowException &e) {
		return (TOO_LOW);
	}
	return (SUCCESS);
}

static bool	testSigning(Form form, Bureaucrat crat) {
	crat.signForm(form);
	return form.isSigned();
}

int	main() {
	for (int i = 1; i < 150 + 1; i++)
		assert(testFormCtor("form", i, 150 + 1 - i) == SUCCESS);

	assert(testFormCtor("chloro", 0, 1) == TOO_HIGH);
	assert(testFormCtor("aldehyde", 1, 0) == TOO_HIGH);
	assert(testFormCtor("ic acid", 1, 151) == TOO_LOW);
	assert(testFormCtor("uoli", 151, 1) == TOO_LOW);

	assert(testSigning(Form("success", 100, 69), Bureaucrat("jim", 99)) == true);
	assert(testSigning(Form("success", 100, 69), Bureaucrat("bob", 100)) == true);
	assert(testSigning(Form("failure", 99, 69), Bureaucrat("fred", 100)) == false);

	Form	printMe("ation", 69, 69);
	std::cout << printMe << std::endl;
}
