//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


//[type_traits
#include <fcppt/type_traits/is_float_or_double.hpp>
#include <fcppt/type_traits/is_string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <iostream>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{

// A function which is only valid for something "derived from" std::basic_string
template<
	typename T
>
typename boost::enable_if
<
	fcppt::type_traits::is_string<T>,
	T
>::type
edit_string(
	T const &t
)
{
	// We know operator+ is available with basic_string
	return t + T();
}

template<
	typename T
>
typename boost::enable_if
<
	fcppt::type_traits::is_float_or_double<T>,
	T
>::type
divide_by_1000(
	T const &t
)
{
	// Might be unsafe with integral values.
	return t * static_cast<T>(1) / static_cast<T>(1000);
}

}

int main()
{
	std::cout << divide_by_1000(10.0) << '\n';
	// Would give a compiler error
	//std::cout << divide_by_1000(10) << '\n';
	std::string s("foobar");
	std::cout << edit_string(s) << '\n';
	// Would give a compiler error, although operator+ is defined
	//std::cout << edit_string(10) << '\n';
}
//]
