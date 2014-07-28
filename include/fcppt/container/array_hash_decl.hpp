//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_HASH_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_HASH_DECL_HPP_INCLUDED

#include <fcppt/container/array_hash_fwd.hpp>
#include <fcppt/type_traits/is_std_array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

template<
	typename Array
>
struct array_hash
{
	static_assert(
		fcppt::type_traits::is_std_array<
			Array
		>::value,
		"Array must be a std::array"
	);

	std::size_t
	operator()(
		Array const &
	) const;
};

}
}

#endif
