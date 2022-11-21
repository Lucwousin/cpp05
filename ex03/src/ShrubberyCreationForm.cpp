/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.cpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 17:37:42 by lsinke        #+#    #+#                 */
/*   Updated: 2022/10/01 17:37:42 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <ShrubberyCreationForm.hpp>
#include <Bureaucrat.hpp>
#include <fstream>
#include <iostream>

# define FORM_NAME		"Shrubbery creation form"
# define SIGN_GRADE		145
# define EXEC_GRADE		137

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target):
		AForm(FORM_NAME, SIGN_GRADE, EXEC_GRADE, target) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
		AForm(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::_execute(const std::string &target) const {
	std::ofstream	out(target + "_shrubbery");
	if (out.is_open()) {
		out <<	"                                                         .\n"
				"                                              .         ;\n"
				"                 .              .              ;%     ;;\n"
				"                   ,           ,                :;%  %;\n"
				"                    :         ;                   :;%;'     .,\n"
				"           ,.        %;     %;            ;        %;'    ,;\n"
				"             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n"
				"              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n"
				"               ;%;      %;        ;%;        % ;%;  ,%;'\n"
				"                `%;.     ;%;     %;'         `;%%;.%;'\n"
				"                 `:;%.    ;%%. %@;        %; ;@%;%'\n"
				"                    `:%;.  :;bd%;          %;@%;'\n"
				"                      `@%:.  :;%.         ;@@%;'\n"
				"                        `@%.  `;@%.      ;@@%;\n"
				"                          `@%%. `@%%    ;@@%;\n"
				"                            ;@%. :@%%  %@@%;\n"
				"                              %@bd%%%bd%%:;\n"
				"                                #@%%%%%:;;\n"
				"                                %@@%%%::;\n"
				"                                %@@@%(o);  . '\n"
				"                                %@@@o%;:(.,'\n"
				"                            `.. %@@@o%::;\n"
				"                               `)@@@o%::;\n"
				"                                %@@(o)::;\n"
				"                               .%@@@@%::;\n"
				"                               ;%@@@@%::;.\n"
				"                              ;%@@@@%%:;;;.\n"
				"                          ...;%@@@@@%%:;;;;,..\n";
		out.close();
	} else {
		std::cerr << "Failed to open file for shrubbery!\n";
	}
}

