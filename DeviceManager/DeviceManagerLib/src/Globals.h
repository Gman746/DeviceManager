#pragma once

class Globals
{
	Globals() = default;

	unsigned int m_nextFreeId = 0; // Bisheriges generisches ID-Feld
	unsigned int m_nextAnalogID = 100;
	unsigned int m_nextDigitalID = 10000; 

public:
	static Globals& GetInstance();

	unsigned int GetNextFreeDeviceID();

	unsigned int GetNextFreeAnalogID();
	unsigned int GetNextFreeDigitalID();
};
