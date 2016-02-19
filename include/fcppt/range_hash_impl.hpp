//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANGE_HASH_IMPL_HPP_INCLUDED
#define FCPPT_RANGE_HASH_IMPL_HPP_INCLUDED

#include <fcppt/range_hash_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/functional/hash/hash.hpp>
#include <cstddef>
#include <iterator>
#include <fcppt/config/external_end.hpp>


template<
	typename Type
>
std::size_t
fcppt::range_hash<
	Type
>::operator()(
	Type const &_value
) const
{
	using std::begin;
	using std::end;

	return
		boost::hash_range(
			begin(
				_value
			),
			end(
				_value
			)
		);
}

#endif
