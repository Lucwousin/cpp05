/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.cpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 21:22:59 by lsinke        #+#    #+#                 */
/*   Updated: 2022/09/29 21:22:59 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Bureaucrat.hpp>
#include <iostream>

// The other bureaucrat won't have an invalid grade, so we don't need to check!
Bureaucrat::Bureaucrat(const Bureaucrat &other):
_name(other._name), _grade(other._grade) {}

Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name) {
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	_grade = grade;
}

Bureaucrat::~Bureaucrat() {}

const std::string &Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

void Bureaucrat::incrementGrade() {
	if (_grade == 1)
		throw GradeTooHighException();
	_grade--;
}

void Bureaucrat::decrementGrade() {
	if (_grade == 150)
		throw GradeTooLowException();
	_grade++;
}


const char *Bureaucrat::GradeTooHighException::what() const throw() {
	return "Grade too high! You can't have a grade higher (lower?) than 1!";
}


const char *Bureaucrat::GradeTooLowException::what() const throw() {
	return "Grade too low! You can't have a grade lower (higher?) than 150!";
}

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs) {
	lhs << rhs.getName() << " is so great, they got grade " << rhs.getGrade() << "!";
	return lhs;
}
