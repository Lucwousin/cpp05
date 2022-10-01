/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.cpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 16:18:51 by lsinke        #+#    #+#                 */
/*   Updated: 2022/10/01 16:18:51 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Form.hpp>
#include <Bureaucrat.hpp>

Form::Form(const Form &other):
		_name(other._name),
		_signGrade(other._signGrade),
		_execGrade(other._execGrade),
		_signed(other._signed) {}

Form::Form(const std::string &name, int signGrade, int execGrade):
		_name(name),
		_signGrade(signGrade),
		_execGrade(execGrade),
		_signed(false) {
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

Form::~Form() {}

const std::string &Form::getName() const {
	return _name;
}

int Form::getSignGrade() const {
	return _signGrade;
}

int Form::getExecGrade() const {
	return _execGrade;
}

bool Form::isSigned() const {
	return _signed;
}

void Form::beSigned(const Bureaucrat &by) {
	if (by.getGrade() > _signGrade)
		throw SignException();
	_signed = true;
}

const char *Form::GradeTooHighException::what() const throw() {
	return "Grade too high! You can't have a grade higher (lower?) than 1!";
}


const char *Form::GradeTooLowException::what() const throw() {
	return "Grade too low! You can't have a grade lower (higher?) than 150!";
}

const char *Form::SignException::what() const throw() {
	return "The grade is too low to sign this form!";
}

std::ostream &operator<<(std::ostream &lhs, const Form &rhs) {
	lhs << "Form: " << rhs.getName()
		<< ", Sign grade: " << rhs.getSignGrade()
		<< ", Exec grade: " << rhs.getExecGrade()
		<< ", signed? " << rhs.isSigned();
	return lhs;
}
