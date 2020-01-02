//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_HASH_HPP_INCLUDED
#define FCPPT_HASH_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <functional>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Calls std::hash

\ingroup fcpptvarious
*/
template<
	typename Type
>
inline
std::size_t
hash(
	Type const &_value
)
{
	return
		std::hash<
			Type
		>{}(
			_value
		);
}

}

#endif
