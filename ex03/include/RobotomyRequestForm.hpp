/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   RobotomyRequestForm.hpp                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/11/21 16:01:52 by lsinke        #+#    #+#                 */
/*   Updated: 2022/11/21 16:01:52 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <AForm.hpp>

class RobotomyRequestForm: public AForm {
	private:
		RobotomyRequestForm(); // Not implemented, need target param
		RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs); // Not implemented

		virtual void _execute(const std::string &target) const;

	public:
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &other);
		virtual ~RobotomyRequestForm();
};

#endif