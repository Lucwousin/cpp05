/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.cpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 16:18:51 by lsinke        #+#    #+#                 */
/*   Updated: 2022/10/01 16:18:51 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <AForm.hpp>
#include <Bureaucrat.hpp>

AForm::AForm(const AForm &other):
		_name(other._name),
		_signGrade(other._signGrade),
		_execGrade(other._execGrade),
		_target(other._target),
		_signed(other._signed) {}

AForm::AForm(const std::string &name, int signGrade, int execGrade, const std::string &target):
		_name(name),
		_signGrade(signGrade),
		_execGrade(execGrade),
		_target(target),
		_signed(false) {
	if (_signGrade < 1 || _execGrade < 1)
		throw GradeTooHighException();
	if (_signGrade > 150 || _execGrade > 150)
		throw GradeTooLowException();
}

AForm::~AForm() {}

const std::string &AForm::getName() const {
	return _name;
}

const std::string &AForm::getTarget() const {
	return _target;
}

int AForm::getSignGrade() const {
	return _signGrade;
}

int AForm::getExecGrade() const {
	return _execGrade;
}

bool AForm::isSigned() const {
	return _signed;
}

void AForm::beSigned(const Bureaucrat &by) {
	if (by.getGrade() > _signGrade)
		throw SignException();
	_signed = true;
}

void AForm::execute(const Bureaucrat &by) const {
	if (by.getGrade() > _execGrade)
		throw ExecException("The grade is too low to execute this form!");
	if (!_signed)
		throw ExecException("The form has not yet been signed!");
	_execute(_target);
}

const char *AForm::GradeTooHighException::what() const throw() {
	return "Grade too high! You can't have a grade higher (lower?) than 1!";
}


const char *AForm::GradeTooLowException::what() const throw() {
	return "Grade too low! You can't have a grade lower (higher?) than 150!";
}

const char *AForm::SignException::what() const throw() {
	return "The grade is too low to sign this form!";
}

AForm::ExecException::ExecException(const char *reason): _reason(reason) {}

const char *AForm::ExecException::what() const throw() {
	return _reason;
}

std::ostream &operator<<(std::ostream &lhs, const AForm &rhs) {
	lhs << "Form: " << rhs.getName()
		<< ", Sign grade: " << rhs.getSignGrade()
		<< ", Exec grade: " << rhs.getExecGrade()
		<< ", signed? " << rhs.isSigned();
	return lhs;
}
