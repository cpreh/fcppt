//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_WRITE_HPP_INCLUDED
#define FCPPT_IO_WRITE_HPP_INCLUDED

#include <fcppt/endianness/from_host.hpp>
#include <fcppt/endianness/format.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_fundamental.hpp>
#include <ostream>

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
	void
>::type
write(
	std::ostream &s,
	T const &t,
	endianness::format::type const fmt
)
{
	T const tmp(
		endianness::from_host(
			t,
			fmt
		)
	);

	s.write(
		reinterpret_cast<
			char const *
		>(&tmp),
		sizeof(T)
	);
}

}
}

#endif
