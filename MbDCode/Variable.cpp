#include "Variable.h"

using namespace MbD;

Variable::Variable()
{
	value = 0.0;
}

Variable::Variable(const char* str) : name(str) 
{
	value = 0.0;
}

Variable::Variable(double val) : value(val)
{
}

void Variable::initialize()
{
}

void Variable::setName(std::string& str)
{
	name = str;
}

const std::string& Variable::getName() const
{
	return name;
}

double MbD::Variable::getValue()
{
	return value;
}
