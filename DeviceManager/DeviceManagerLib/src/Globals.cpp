#include "Globals.h"
#include <stdexcept>

Globals* instance = nullptr;

Globals& Globals::GetInstance()
{
	if ( !instance )
	{
		instance = new Globals();
	}
	return *instance;
}

unsigned int Globals::GetNextFreeDeviceID()
{
	return ++m_nextFreeId;
}

unsigned int Globals::GetNextFreeAnalogID()
{
	if ( m_nextAnalogID > 9999 )
		throw std::runtime_error( "No more analog IDs available." );
	return m_nextAnalogID++;
}

unsigned int Globals::GetNextFreeDigitalID()
{
	if ( m_nextDigitalID > 19999 )
		throw std::runtime_error( "No more digital IDs available." );
	return m_nextDigitalID++;
}
