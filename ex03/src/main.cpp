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
#include <Intern.hpp>
#include <iostream>

static void	createForm(const Intern &intern, const std::string &name, const std::string &target) {
	const AForm *form = intern.makeForm(name, target);
	delete form;
	std::cout << "\n";
}

int	main() {
	const Intern	intern;

	createForm(intern, "shrubbery creation", "target");
	createForm(intern, "robotomy request", "target");
	createForm(intern, "presidential pardon", "target");
	createForm(intern, "invalid", "target");
}
