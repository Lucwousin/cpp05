/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Form.hpp                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/01 16:17:20 by lsinke        #+#    #+#                 */
/*   Updated: 2022/10/01 16:17:20 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <ostream>

class Bureaucrat;

class Form {
	private:
		Form(); // Not implemented
		Form &operator=(const Form &rhs); // Neither is this, constant attributes

		const std::string	_name;
		const int	_signGrade;
		const int	_execGrade;

		bool		_signed;

	public:
		Form(const Form &other);
		Form(const std::string &name, int signGrade, int execGrade);
		~Form();

		const std::string	&getName() const;
		int		getSignGrade() const;
		int		getExecGrade() const;
		bool	isSigned() const;

		void	beSigned(const Bureaucrat &by);

		class GradeTooHighException: public std::exception {
			public:
				const char	*what() const throw();
		};
		class GradeTooLowException: public std::exception {
			public:
				const char	*what() const throw();
		};
		class SignException: public Form::GradeTooLowException {
			public:
				const char	*what() const throw();
		};
};

std::ostream &operator<<(std::ostream &lhs, const Form &rhs);

#endif //FORM_HPP
