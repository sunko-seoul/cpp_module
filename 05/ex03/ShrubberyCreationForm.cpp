/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunko <sunko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 01:15:12 by sunko             #+#    #+#             */
/*   Updated: 2024/01/07 01:28:16 by sunko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.h"
#include <fstream>
#include <cstdlib>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137),
	  mTarget(target)
{}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& rhs)
	: AForm("ShrubberyCreationForm", 145, 137),
	  mTarget(rhs.mTarget)
{}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs)
{
	if (this == &rhs)
		return (*this);
	mTarget = rhs.mTarget;
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{}

void	ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	if (!this->getSigned())
		throw AForm::EmptySignException();
	if (executor.getGrade() > this->getRequiredExecuteGrade())
		throw Bureaucrat::GradeTooLowException();
	createAsciiTree();
}

void	ShrubberyCreationForm::createAsciiTree() const
{
	std::string fileName = mTarget + "_shrubbery";
	std::ofstream file(fileName);

	if (file.is_open())
	{
		file << "                                                 .\n";
        file << "                                              .         ;\n";
        file << "                 .              .              ;%     ;;\n";
        file << "                   ,           ,                :;%  %;\n";
        file << "                    :         ;                   :;%;'     .,\n";
        file << "           ,.        %;     %;            ;        %;'    ,;\n";
        file << "             ;       ;%;  %%;        ,     %;    ;%;    ,%'\n";
        file << "              %;       %;%;      ,  ;       %;  ;%;   ,%;'\n";
        file << "               ;%;      %;        ;%;        % ;%;  ,%;'\n";
        file << "                `%;.     ;%;     %;'         `;%%;.%;'\n";
        file << "                 `:;%.    ;%%. %@;        %; ;@%;%'\n";
        file << "                    `:%;.  :;bd%;          %;@%;'\n";
        file << "                      `@%:.  :;%.         ;@@%;'\n";
        file << "                        `@%.  `;@%.      ;@@%;\n";
        file << "                          `@%%. `@%%    ;@@%;\n";
        file << "                            ;@%. :@%%  %@@%;\n";
        file << "                              %@bd%%%bd%%:;\n";
        file << "                                #@%%%%%:;;\n";
        file << "                                %@@%%%::;\n";
        file << "                                %@@@%(o);  . '\n";
        file << "                                %@@@o%;:(.,'\n";
        file << "                            `.. %@@@o%::;\n";
        file << "                               `)@@@o%::;\n";
        file << "                                %@@(o)::;\n";
        file << "                               .%@@@@%::;\n";
        file << "                               ;%@@@@%::;.          \n";
        file << "                              ;%@@@@%%:;;;. \n";
        file << "                          ...;%@@@@@%%:;;;;,.. \n";
		file.close();
	}
	else
	{
		std::cerr << "file open error" << std::endl;
		std::exit(1);
	}
}

