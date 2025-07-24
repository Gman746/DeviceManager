// Copyright @ Schueco Digital GmbH 2023
// @Author: Konstantin Nikkel
#include <vector>
#include <random>

#include "Device.h"
#include "DeviceType.h"

DeviceVariant generateRandomDigitalVariant()
{
	static std::random_device rd;
	static std::mt19937 gen( rd() );
	static std::uniform_int_distribution<> dis( 0, 2 );

	switch ( dis( gen ) )
	{
	case 0: return DeviceVariant::A;
	case 1: return DeviceVariant::B;
	case 2: return DeviceVariant::D;
	default: return DeviceVariant::None; // fallback – sollte nie passieren
	}
}


std::vector<Device> generateData( size_t count )
{
	std::vector<Device> result;

	for ( size_t current = 0; current < count; ++current )
	{
		const std::string deviceName = "device " + std::to_string( current );
		const std::string desc = "this is dev no " + std::to_string( current );

		DeviceType type = ( current % 2 == 0 ) ? DeviceType::Analog : DeviceType::Digital;
		DeviceVariant variant = ( type == DeviceType::Digital ) ? generateRandomDigitalVariant() : DeviceVariant::None;

		auto device = Device( deviceName, desc, type, variant );
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
