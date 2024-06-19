#include "Serializer.hpp"

int	main()
{
	Data		*data;
	uintptr_t	rawData;
	Data		*returnData;

	data = new Data;
	std::cout << "Data\t\t\t: " << data << std::endl;
	rawData = Serializer::serialize(data);
	std::cout << "Raw Data\t\t: " << rawData << std::endl;
	returnData = Serializer::deserialize(rawData);
	std::cout << "Deserialized data\t: " << returnData << std::endl;

	delete data;
	return (0);
}