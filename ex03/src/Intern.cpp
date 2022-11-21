/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.cpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 18:14:55 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/21 18:14:55 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <Intern.hpp>
#include <PresidentialPardonForm.hpp>
#include <ShrubberyCreationForm.hpp>
#include <RobotomyRequestForm.hpp>
#include <iostream>

#define FORM_COUNT	3

Intern::Intern() {}

Intern::Intern(const Intern &other) {
	(void) other;
}

Intern::~Intern() {}

Intern &Intern::operator=(const Intern &rhs) {
	(void) rhs;
	return *this;
}

static AForm	*newPardonForm(const std::string &target) {
	return new PresidentialPardonForm(target);
}

static AForm	*newShrubberyForm(const std::string &target) {
	return new ShrubberyCreationForm(target);
}

static AForm	*newRobotomyForm(const std::string &target) {
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeForm(const std::string &form, const std::string &target) const {
	AForm *(*ctorfuns[FORM_COUNT])(const std::string &target) = {
		newPardonForm,
		newShrubberyForm,
		newRobotomyForm
	};
	const std::string formnames[FORM_COUNT] = {
		"presidential pardon",
		"shrubbery creation",
		"robotomy request"
	};

	for (int i = 0; i < FORM_COUNT; i++) {
		if (formnames[i] == form) {
			AForm *newForm = ctorfuns[i](target);
			std::cout << "Intern creates " << *newForm << '\n';
			return newForm;
		}
	}
	std::cout << "Intern was unable to create a " << form << " form for " << target << '\n';
	return NULL;
}

