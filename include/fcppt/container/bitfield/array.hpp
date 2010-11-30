//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_ARRAY_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_ARRAY_HPP_INCLUDED

#include <fcppt/container/bitfield/detail/element_bits.hpp>
#include <fcppt/container/array_fwd.hpp>

namespace fcppt
{
namespace container
{
namespace bitfield
{

template<
	typename Enum,
	Enum Size,
	typename InternalType
>
struct array
{
private:
	static bitfield::size_type const element_bits =
		bitfield::detail::element_bits<
			InternalType
		>::value;
public:
	typedef fcppt::container::array<
		InternalType,
		Size / element_bits + (Size % element_bits ? 1 : 0)
	> type;
};

}
}
}

#endif
