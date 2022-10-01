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
#include <iostream>

ShrubberyCreationForm::ShrubberyCreationForm():
		Form(FORM_NAME, SIGN_GRADE, EXEC_GRADE) {}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other):
		Form(other) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

static bool	shouldBranch() {
	static unsigned int	seed = rand();

	return ((double) rand_r(&seed) / (float) RAND_MAX) <= BRANCH_ODDS;
}

static void	generateBranch(char treeBuf[99][101], float x, float y, float dx, float dy) {
	while (x >= 0 && y >= 0 && x <= 1.0f && y <= 1.0f) {
		int	px = (int) (x * 98.f), py = (int) (y * 98.f);
		treeBuf[py][px] = '#';
		x += dx;
		y += dy;
		if (shouldBranch()) {
			if (dx == 0.f) {
				dx = .25f / 98;
			}
			if (dy == 0.f) {
				dy = .25f / 98;
			}
			dy /= 2;
			generateBranch(treeBuf, x, y, -dx, dy);
		}
	}
}

void ShrubberyCreationForm::_execute(const Bureaucrat &target) const {
	char treeBuf[99][101]; // odd so the tree can start in the center

	for (int i = 0; i < 99; i++) {
		memset(treeBuf[i], ' ', 99);
		treeBuf[i][99] = '\n';
		treeBuf[i][100] = '\0';
	}

	generateBranch(treeBuf, .5f, 1.f, 0.f, -1.f / 98);
	for (int i = 0; i < 99; i++)
		std::cout << treeBuf[i];

	(void) target;
}

