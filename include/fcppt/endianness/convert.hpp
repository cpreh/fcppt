//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_CONVERT_HPP_INCLUDED
#define FCPPT_ENDIANNESS_CONVERT_HPP_INCLUDED

#include <fcppt/endianness/host_format.hpp>
#include <fcppt/endianness/swap.hpp>


namespace fcppt
{
namespace endianness
{

template<
	typename Type
>
Type
convert(
	Type const &_value,
	fcppt::endianness::format::type const _format
)
{
	return
		_format
		==
		fcppt::endianness::host_format()
		?
			_value
		:
			fcppt::endianness::swap(
				_value
			);
}

}
}

#endif
