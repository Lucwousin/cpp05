/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   PresidentialPardonForm.hpp                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:01:52 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/21 16:01:52 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <AForm.hpp>

class PresidentialPardonForm: public AForm {
	private:
		PresidentialPardonForm(); // Not implemented, need target param
		PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs); // Not implemented

		virtual void _execute(const std::string &target) const;

	public:
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm	 &other);
		virtual ~PresidentialPardonForm();
};

#endif