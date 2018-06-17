//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HASH_COMBINE_HPP_INCLUDED
#define FCPPT_HASH_COMBINE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Combines two hashes

\ingroup fcpptvarious
*/
inline
std::size_t
hash_combine(
	std::size_t const _hash_old,
	std::size_t const _hash_new
)
{
	// Suggested hash function from
	// https://stackoverflow.com/questions/6899392/generic-hash-function-for-all-stl-containers
	return
		_hash_old
		^
		(
			_hash_new
			+
			std::size_t{
				0x9e3779b9u
			}
			+
			(
				_hash_old
				<<
				6u
			)
			+
			(
				_hash_old
				>>
				2u
			)
		);
}

}

#endif
