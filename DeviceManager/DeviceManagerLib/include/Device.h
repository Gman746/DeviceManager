#pragma once

#include "DeviceType.h"
#include <string>

class Device
{
public:
	Device( std::string name, std::string a_description, DeviceType type, DeviceVariant a_variant = DeviceVariant::None );

	void printInfo() const;

private:
	unsigned int m_id;
	std::string m_name;
	std::string m_description;
	std::string m_status;

	DeviceType m_type;
	DeviceVariant m_variant;

	std::string generateStatus() const;
};
