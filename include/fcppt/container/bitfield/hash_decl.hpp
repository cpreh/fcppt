//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_BITFIELD_HASH_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_BITFIELD_HASH_DECL_HPP_INCLUDED

#include <fcppt/container/bitfield/hash_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{
namespace bitfield
{

template<
	typename Bitfield
>
struct hash
{
	std::size_t
	operator()(
		Bitfield const &
	) const;
};

}
}
}

#endif
