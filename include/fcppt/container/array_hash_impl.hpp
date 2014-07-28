//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_ARRAY_HASH_IMPL_HPP_INCLUDED
#define FCPPT_CONTAINER_ARRAY_HASH_IMPL_HPP_INCLUDED

#include <fcppt/container/array_hash_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/functional/hash/hash.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


template<
	typename Array
>
std::size_t
fcppt::container::array_hash<
	Array
>::operator()(
	Array const &_array
) const
{
	return
		boost::hash_range(
			_array.begin(),
			_array.end()
		);
}

#endif
