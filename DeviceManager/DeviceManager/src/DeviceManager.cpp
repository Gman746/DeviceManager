// Copyright @ Schueco Digital GmbH 2023
// @Author: Konstantin Nikkel
#include <vector>

#include "Device.h"
#include "DeviceType.h"

std::vector<Device> generateData( size_t count )
{
	std::vector<Device> result;

	for ( size_t current = 0; current < count; ++current )
	{
		const std::string deviceName = "device " + std::to_string( current );
		const std::string desc = "this is dev no " + std::to_string( current );

		DeviceType type = ( current % 2 == 0 ) ? DeviceType::Analog : DeviceType::Digital;

		auto device = Device( deviceName, desc, type );
		result.push_back( device );

	}

	return result;
}

void showData( const std::vector<Device>& devices )
{
	for ( const auto device : devices )
	{
		device.printInfo();
	}
}

int main()
{
	constexpr size_t dataToGenerate = 5;
	const std::vector<Device> devices = generateData( dataToGenerate );
	showData( devices );
}
