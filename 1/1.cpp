#include <cstddef>
#include <iostream>
#include <compare>
#include <array>
#include <optional>

import module1;

[[nodiscard]] std::string super_duper([[maybe_unused]] int a)  // nodiscard, maybe_unused - atributes
{
    if (a > 1) [[unlikely]] {}  // unlikely - attribute
    return __func__;    // __func__ - built-in array in every func
}

std::optional<double> get_pressure(double altitude)
{
    const auto pressure = 1.0 / altitude;
    if (!std::isfinite(pressure)) return std::nullopt;
    return pressure;
}

int main()
{
    std::byte b{1};
    int q = 1000'000'000;

    if (int q = 0; q < 12) {}

    // Three-way comparision
    int a{}, c{};
    std::strong_ordering so = (a <=> c);
    if (so == std::strong_ordering::less) {}

    std::cout << super_duper(1) << std::endl;

    int my_array[]{1, 2, 3};
    const auto my_array_size = std::size(my_array);     // length, not size in bytes as with sizeof

    int *p;
    int *&t = p;

    std::array arr{1, 2, 3};    // CTAD - class template argument deduction

    const auto pressure{get_pressure(98)};
    if (pressure.has_value()) {}

    // Structured binding
    auto [first_element, second_element, third_element] = arr;
    std::cout << first_element << " | " << second_element << " | " << third_element << std::endl;

    // Try classes from module
    class1 instance_of_class1;
    instance_of_class1.class1method();

    class2 instance_of_class2;
    instance_of_class2.class2method();

    return 0;
}
