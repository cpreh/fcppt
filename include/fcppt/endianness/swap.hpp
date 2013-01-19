//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENDIANNESS_SWAP_HPP_INCLUDED
#define FCPPT_ENDIANNESS_SWAP_HPP_INCLUDED

#include <fcppt/endianness/raw_pointer.hpp>
#include <fcppt/endianness/reverse_mem.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace endianness
{

/**
\brief Swaps the endianness of an object

\ingroup fcpptendianness

Swaps the endiannness of \a _value.

\tparam Type Must be a fundamental type

\param _value The value to swap the endianness for

\return The converted value
*/
template<
	typename Type
>
typename boost::enable_if<
	std::is_fundamental<
		Type
	>,
	Type
>::type
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
