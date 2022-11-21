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

#include <AForm.hpp>
#include <Bureaucrat.hpp>
#include <iostream>
#include <ShrubberyCreationForm.hpp>
#include <PresidentialPardonForm.hpp>
#include <RobotomyRequestForm.hpp>

static void	testForm(const Bureaucrat &crat, AForm &form)
{
	std::cout << crat << " is signing and executing " << form << "\n";

	crat.signForm(form);
	crat.executeForm(form);
}

int	main() {
	const Bureaucrat	highGrade("high ranking bureaucrat", 1);
	const Bureaucrat	lowGrade("low ranking bureaucrat", 150);

	{
		ShrubberyCreationForm shrub("shrubby");
		testForm(lowGrade, shrub);
		testForm(highGrade, shrub);
		std::cout << "\n\n";
	}
	{
		PresidentialPardonForm pardon("pardonny");
		testForm(lowGrade, pardon);
		testForm(highGrade, pardon);
		std::cout << "\n\n";
	}
	{
		RobotomyRequestForm robot("robotommy");
		testForm(lowGrade, robot);
		testForm(highGrade, robot);
	}
}
