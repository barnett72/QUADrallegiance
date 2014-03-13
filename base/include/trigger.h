#ifndef TRIGGER_H_
#define TRIGGER_H_

#define TRIGGER_DIVISOR 8

class Trigger
{
	public:
    	Trigger();
    	void setValue(int rawValue);
    	char getValue();
    	char getTransmitValue(int zeroOffset);
    private:
    	char value;
};

#endif /* TRIGGER_H_ */
