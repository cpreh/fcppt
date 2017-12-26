//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANGE_DETAIL_HASH_COMBINE_HPP_INCLUDED
#define FCPPT_RANGE_DETAIL_HASH_COMBINE_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace range
{
namespace detail
{

template<
	typename Type
>
inline
std::size_t
hash_combine(
	std::size_t const _seed,
	Type const &_value
)
{
	// Suggested hash function from
	// https://stackoverflow.com/questions/6899392/generic-hash-function-for-all-stl-containers
	std::hash<
		Type
	> std_hash{};

	return
		_seed
		^
		(
			std_hash(
				_value
			)
			+
			fcppt::literal<
				std::size_t
			>(
				0x9e3779b9u
			)
			+
			(
				_seed
				<<
				6u
			)
			+
			(
				_seed
				>>
				2u
			)
		);
}

}
}
}

#endif
