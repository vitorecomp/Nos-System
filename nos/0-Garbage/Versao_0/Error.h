#ifndef ERROR_H
#define ERROR_H
class Error
{
public:
	void messagemForaLimite(int);
};

inline void Error::messagemForaLimite(int erro)
{
	pinMode(13, OUTPUT);
	while(1)
	{
		digitalWrite(13, HIGH);
		delay(200);
		digitalWrite(13, LOW);
		delay(1000);
	}

}
#endif