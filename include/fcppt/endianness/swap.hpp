//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_SWAP_HPP_INCLUDED
#define FCPPT_ENDIANNESS_SWAP_HPP_INCLUDED

#include <fcppt/endianness/raw_pointer.hpp>
#include <fcppt/endianness/reverse_mem.hpp>


namespace fcppt
{
namespace endianness
{

template<
	typename Type
>
Type
swap(
	Type _value
)
{
	fcppt::endianness::reverse_mem(
		reinterpret_cast<
			fcppt::endianness::raw_pointer
		>(
			&_value
		),
		sizeof(
			Type
		)
	);

	return _value;
}

}
}

#endif
