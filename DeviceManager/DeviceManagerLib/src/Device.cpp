#include <iostream>
#include <iomanip>
#include <sstream>
#include "Device.h"
#include "Globals.h"
#include <random>

static std::random_device rd;
static std::mt19937 gen( rd() );
static std::uniform_real_distribution<> distA( -50.0, 70.0 );
static std::uniform_int_distribution<> distB( 0, 1 );
static std::uniform_int_distribution<> distDGen1( 0, 10 );
static std::uniform_int_distribution<> distDGen2( 0, 100 );

Device::Device( std::string a_name, std::string a_description, DeviceType a_type, DeviceVariant a_variant )
	: m_name( a_name )
	, m_description( a_description )
	, m_type( a_type )
	, m_variant( a_variant )
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
	 m_status = generateStatus();

	if ( m_variant == DeviceVariant::D && m_id >= 15000 )
	{
		m_description += " (Gen 2)";
	}
}

std::string deviceVariantToString( DeviceVariant variant )
{
	switch ( variant )
	{
	case DeviceVariant::None: return "No Variant";
	case DeviceVariant::A: return "Variant A";
	case DeviceVariant::B: return "Variant B";
	case DeviceVariant::D: return "Variant D";
	default: return "Unknown";
	}
}

std::string deviceTypeToString( DeviceType type )
{
	if ( type == DeviceType::Analog )
		return "Analog";
	else
		return "Digital";
}


std::string Device::generateStatus() const
{
	if ( m_type != DeviceType::Digital )
		return "";

	switch ( m_variant )
	{
	case DeviceVariant::A:
	{
		double val = distA( gen );
		if ( val <= -50.0 )
			return "Low";
		else if ( val >= 70.0 )
			return "High";
		else
		{
			std::ostringstream oss;
			oss << val;
			return oss.str();
		}
	}
	case DeviceVariant::B:
	{
		int val = distB( gen );
		return val == 0 ? "Off" : "On";
	}
	case DeviceVariant::D:
	{
		if ( m_id < 15000 )
		{
			// Generation 1
			int step = distDGen1( gen );
			int percent = step * 10;
			if ( percent == 0 )
				return "Opened";
			else if ( percent == 100 )
				return "Closed";
			else
			{
				std::ostringstream oss;
				oss << percent << "%";
				return oss.str();
			}
		}
		else
		{
			// Generation 2
			int percent = distDGen2( gen );
			if ( percent == 0 )
				return "Opened";
			else if ( percent == 100 )
				return "Closed";
			else
			{
				std::ostringstream oss;
				oss << percent << "%";
				return oss.str();
			}
		}
	}
	default:
		return "";
	}
}

void Device::printInfo() const
{
	std::cout << " >>> \n";

	std::cout << " - Type: " << deviceTypeToString( m_type ) << "\n";
	std::cout << " - " << m_id << "\n";
	std::cout << " - " << m_name << "\n";
	std::cout << " - " << m_description << "\n";
	std::cout << " - " << deviceVariantToString( m_variant ) << "\n";

		if ( m_type == DeviceType::Digital )
	{
		std::cout << " - Status: " << m_status << "\n";
	}

	std::cout << " <<< \n";
}
