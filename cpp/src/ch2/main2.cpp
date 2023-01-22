#include <iostream>
#include <string>
#include <variant>

enum class TrafficLight {red, yellow, green};
enum class Color {green, yellow, red};

std::string trafficMapping[3] = {"red", "yellow", "green"};

int main() {
	
	std::variant<int, float> v, w;
	v = 42;	// v contains 'int'

	try {
		std::cout << std::get<float>(v);
	} catch (const std::bad_variant_access& ex) {
		std::cout << ex.what() << '\n';
	}

	TrafficLight light{Color::red};
	std::cout << trafficMapping[static_cast<int>(light)] << "\n"; // 'green'

	// Error
	// light = TrafficLight{62737237};
	// std::cout << trafficMapping[static_cast<int>(light)] << '\n';
	return 0;
}
