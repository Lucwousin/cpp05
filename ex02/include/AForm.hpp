/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   AForm.hpp                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 16:17:20 by lsinke        #+#    #+#                 */
/*   Updated: 2022/10/01 16:17:20 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <ostream>

class Bureaucrat;

class AForm {
	private:
		AForm(); // Not implemented
		AForm &operator=(const AForm &rhs); // Neither is this, constant attributes

		const std::string	_name;
		const int			_signGrade;
		const int			_execGrade;
		const std::string	_target;

		bool				_signed;

		virtual void _execute(const std::string &target) const = 0;

	public:
		AForm(const AForm &other);
		AForm(const std::string &name, int signGrade, int execGrade, const std::string &target);
		~AForm();

		const std::string	&getName() const;
		const std::string	&getTarget() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		bool	isSigned() const;

		void	beSigned(const Bureaucrat &by);
		void	execute(const Bureaucrat &by) const;

		class GradeTooHighException: public std::exception {
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char	*what() const throw();
		};
		class SignException: public AForm::GradeTooLowException {
			public:
				const char	*what() const throw();
		};
		class ExecException: public std::exception {
			private:
				const char	*_reason;
			public:
				ExecException(const char *reason);
				const char	*what() const throw();
		};
};

std::ostream &operator<<(std::ostream &lhs, const AForm &rhs);

#endif
