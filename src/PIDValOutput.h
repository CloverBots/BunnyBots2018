#ifndef Motor6PIDOutput_H_
#define Motor6PIDOutput_H_
#include <WPILib.h>
#include <ctre/Phoenix.h>

class PIDValOutput : public PIDOutput{
private:
	double value;
public:
	PIDValOutput();
	virtual ~PIDValOutput();
	virtual void PIDWrite(double value);
	double GetValue();
};

#endif /* Motor6PIDOutput_H_ */
