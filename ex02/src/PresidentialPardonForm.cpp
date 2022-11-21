/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.cpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:03:50 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/21 16:03:50 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <PresidentialPardonForm.hpp>
#include <iostream>

# define FORM_NAME		"Presidential pardon form"
# define SIGN_GRADE		25
# define EXEC_GRADE		5

PresidentialPardonForm::PresidentialPardonForm(const std::string &target):
		AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE, target) {}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other):
		AForm(other) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::_execute(const std::string &target) const {
	std::cout << target << " has been pardoned by Zaphod Beeblebrox\n";
}
