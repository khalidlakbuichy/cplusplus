#include "ShrubberyCreationForm.hpp"

// Canonical form:
ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("unknown") {}
ShrubberyCreationForm::ShrubberyCreationForm(const std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), _target(copy._target) {}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
    if (this != &other)
    {
        *this = ShrubberyCreationForm(other);
    }
    return (*this);
}
ShrubberyCreationForm::~ShrubberyCreationForm() {};

// Getters:
std::string ShrubberyCreationForm::getTarget() const { return (_target); }

// Methods:
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    if (!getSigned())
        throw AForm::FormNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();

    std::ofstream file;
    std::string filename = _target + "_shrubbery";
    file.open(filename.c_str());

        file << "                                                   ." << std::endl;
        file << "                                      .         ;" << std::endl;  
        file << "         .              .              ;%     ;;" << std::endl;   
        file << "           ,           ,                :;%  %;" << std::endl;   
        file << "            :         ;                   :;%;'" << std::endl;  
        file << "   ,.        %;     %;            ;        %;'    ,;" << std::endl;
        file << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
        file << "      %;       %;%;      ,  ;       %;  ;%;   ,%;'" << std::endl; 
        file << "       ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
        file << "        `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
        file << "         `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
        file << "            `:%;.  :;bd%;          %;@%;'" << std::endl;
        file << "              `@%:.  :;%.         ;@@%;'" << std::endl;   
        file << "                `@%.  `;@%.      ;@@%;" << std::endl;         
        file << "                  `@%%. `@%%    ;@@%;" << std::endl;        
        file << "                    ;@%. :@%%  %@@%;" << std::endl;       
        file << "                      %@bd%%%bd%%:;" << std::endl;     
        file << "                        #@%%%%%:;;" << std::endl;
        file << "                        %@@%%%::;" << std::endl;
        file << "                        %@@@%(o);  . '" << std::endl;         
        file << "                        %@@@o%;:(.,'" << std::endl;         
        file << "                    `.. %@@@o%::;" << std::endl;         
        file << "                       `)@@@o%::;" << std::endl;         
        file << "                        %@@(o)::;" << std::endl;        
        file << "                       .%@@@@%::;" << std::endl;         
        file << "                       ;%@@@@%::;." << std::endl;          
        file << "                      ;%@@@@%%:;;;." << std::endl; 
        file << "                  ...;%@@@@@%%:;;;;,.." << std::endl;

    file.close();
}