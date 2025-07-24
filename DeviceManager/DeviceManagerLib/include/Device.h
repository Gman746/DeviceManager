#pragma once

#include "DeviceType.h"
#include <string>

class Device
{
public:
	Device( std::string name, std::string a_description, DeviceType type );

	void printInfo() const;

private:
	unsigned int m_id;
	std::string m_name;
	std::string m_description;
	DeviceType m_type;
};
