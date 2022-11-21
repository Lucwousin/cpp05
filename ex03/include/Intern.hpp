/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Intern.hpp                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 18:14:44 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/21 18:14:44 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <AForm.hpp>

class Intern {
	public:
		Intern();
		Intern(const Intern &other);
		virtual ~Intern();
		Intern &operator=(const Intern &rhs);

		AForm	*makeForm(const std::string &form, const std::string &target) const;
};

#endif