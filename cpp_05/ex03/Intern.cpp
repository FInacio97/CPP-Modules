# include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern &src) {(void) src;}

Intern &Intern::operator=(Intern &src) {(void) src; return(*this);}

Intern::~Intern(void) {}