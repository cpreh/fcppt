#include <fcppt/container/raw_vector.hpp>
#include <fcppt/container/bitfield/basic.hpp>
#include <iostream>
#include <ostream>
#include <fstream>
#include <vector>

int
main()
{
{
//! [raw_vector]
std::vector<int> chars(
	1024);

// Will output "0"
std::cout << chars[0];

fcppt::container::raw_vector<int> raw_chars(
	1024);

// This is undefined, since raw_chars is not initialized.
std::cout << raw_chars[0];

std::ifstream file("test_file");
// Note here that raw_vector has a ::data member (unlike C++03's
// std::vector)
file.read(
	reinterpret_cast<char *>(
		raw_chars.data()),
	1024);
//! [raw_vector]
}
}
