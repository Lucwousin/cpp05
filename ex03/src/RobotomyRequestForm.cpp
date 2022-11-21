/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.cpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:03:50 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/21 16:03:50 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <RobotomyRequestForm.hpp>
#include <iostream>

# define FORM_NAME		"Robotomy request form"
# define SIGN_GRADE		72
# define EXEC_GRADE		45

RobotomyRequestForm::RobotomyRequestForm(const std::string &target):
		AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE, target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other):
		AForm(other) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::_execute(const std::string &target) const {
	std::cout << "< LOUD DRILLING NOISES >\n";
	srand(std::time(nullptr));
	if (rand() & 1) {
		std::cout << target << " has been successfully robotomized!\n";
	} else {
		std::cout << "Failed to robotomize " << target << '\n';
	}
}
