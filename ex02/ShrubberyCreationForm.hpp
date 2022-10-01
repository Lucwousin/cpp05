/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ShrubberyCreationForm.hpp                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 17:36:44 by lsinke        #+#    #+#                 */
/*   Updated: 2022/10/01 17:36:44 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <Form.hpp>

# define FORM_NAME	"Shrubbery creation form"
# define SIGN_GRADE	145
# define EXEC_GRADE	137

class ShrubberyCreationForm: public Form {
	private:
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs); // Not implemented

		void _execute(const Bureaucrat &target);

	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		~ShrubberyCreationForm();
};

#endif //SHRUBBERYCREATIONFORM_HPP
