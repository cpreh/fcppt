#include <fcppt/utf8/from_std_string.hpp>
#include <fcppt/utf8/string.hpp>
#include <string>

fcppt::utf8::string const
fcppt::utf8::from_std_string(
	std::string const &input)
{
	fcppt::utf8::string result;
	result.resize(
		static_cast<fcppt::utf8::string::size_type>(
			input.size()));
	for(std::string::size_type i = 0; i < input.size(); ++i)
		result[
			static_cast<fcppt::utf8::string::size_type>(
				i)] = 
			static_cast<fcppt::utf8::string::value_type>(
				input[i]);
	return result;
}
