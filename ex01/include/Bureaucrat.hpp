/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Bureaucrat.hpp                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: lsinke <lsinke@student.codam.nl>             +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/09/29 21:22:39 by lsinke        #+#    #+#                 */
/*   Updated: 2022/09/29 21:22:39 by lsinke        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <string>

class Form;

class Bureaucrat {
	private:
		Bureaucrat(); // Not implemented
		Bureaucrat &operator=(const Bureaucrat &rhs); // Neither is this, name is constant

		const std::string	_name;
		int					_grade;

	public:
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(const std::string &name, int grade);
		virtual ~Bureaucrat();

		const std::string &	getName() const;
		int					getGrade() const;

		void	incrementGrade();
		void	decrementGrade();
		void	signForm(Form &form);

	class GradeTooHighException: public std::exception {
		public:
			const char	*what() const throw();
	};
	class GradeTooLowException: public std::exception {
		public:
			const char	*what() const throw();
	};
};

std::ostream &operator<<(std::ostream &lhs, const Bureaucrat &rhs);

#endif //BUREAUCRAT_HPP
