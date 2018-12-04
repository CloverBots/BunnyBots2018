#include <PIDValOutput.h>

PIDValOutput::PIDValOutput()
{
	value = 0;
}

PIDValOutput::~PIDValOutput() {

}

void PIDValOutput::PIDWrite(double value)
{
	this->value = value;
}

double PIDValOutput::GetValue()
{
	return value;
}

