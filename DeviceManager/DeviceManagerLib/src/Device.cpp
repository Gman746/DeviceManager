#include <iostream>
#include <iomanip>
#include <sstream>
#include "Device.h"
#include "Globals.h"


Device::Device( std::string a_name, std::string a_description, DeviceType type )
	: m_name( a_name )
	, m_description( a_description )
	, m_type( type )
{
	if ( m_type == DeviceType::Analog )
	{
		m_id = Globals::GetInstance().GetNextFreeAnalogID();

		std::ostringstream oss;
		oss << "AD" << std::setw( 4 ) << std::setfill( '0' ) << m_id;
		m_description = oss.str();
	}
	else // Digital
	{
		m_id = Globals::GetInstance().GetNextFreeDigitalID();

		std::ostringstream oss;
		oss << "DD" << m_id;
		m_description = oss.str();
	}
}

void Device::printInfo() const
{
	std::cout << " >>> \n";

	std::cout << " - " << m_id << "\n";
	std::cout << " - " << m_name << "\n";
	std::cout << " - " << m_description << "\n";

	std::cout << " <<< \n";
}
