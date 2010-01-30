//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_READ_HPP_INCLUDED
#define FCPPT_IO_READ_HPP_INCLUDED

#include <fcppt/endianness/to_host.hpp>
#include <fcppt/endianness/format.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <istream>

namespace fcppt
{
namespace io
{

template<
	typename T
>
typename boost::enable_if<
	boost::is_fundamental<
		T
	>,
	T	
>::type
read(
	std::istream &s,
	endianness::format::type const fmt
)
{
	T t;

	s.read(
		reinterpret_cast<char *>(&t),
		sizeof(T)
	);

	return endianness::to_host(
		t,
		fmt
	);
}

}
}

#endif
