//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_ARRAY_HPP_INCLUDED

#include <fcppt/cast/size.hpp>
#include <fcppt/container/bitfield/detail/element_bits.hpp>
#include <fcppt/math/ceil_div_static.hpp>
#include <fcppt/config/external_begin.hpp>
#include <array>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

/**
\brief Meta function to retrieve the internal storage type used by
#fcppt::container::bitfield::object.

\ingroup fcpptcontainerbitfield

This is currently just an array of as many <code>InternalTypes</code> values as
are necessary to hold <code>NumElements</code> bits.
*/
template<
	typename NumElements,
	typename InternalType
>
using
array
=
std::array<
	InternalType,
	fcppt::math::ceil_div_static<
		std::size_t,
		fcppt::cast::size<
			std::size_t
		>(
			NumElements::value
		),
		fcppt::container::bitfield::detail::element_bits<
			std::size_t,
			InternalType
		>::value
	>::value
>;

}
}
}

#endif
