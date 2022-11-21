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

# include <AForm.hpp>

class ShrubberyCreationForm: public AForm {
	private:
		ShrubberyCreationForm(); // Not implemented, need target param
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs); // Not implemented

		virtual void _execute(const std::string &target) const;

	public:
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		virtual ~ShrubberyCreationForm();
};

#endif //SHRUBBERYCREATIONFORM_HPP
