//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_HASH_DECL_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_HASH_DECL_HPP_INCLUDED

#include <fcppt/strong_typedef_fwd.hpp>
#include <fcppt/strong_typedef_hash_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Hash function object for strong typedefs

\ingroup fcpptstrongtypedef
*/
template<
	typename Type,
	typename Alias
>
struct strong_typedef_hash<
	fcppt::strong_typedef<
		Type,
		Alias
	>
>
{
	typedef fcppt::strong_typedef<
		Type,
		Alias
	> type;

	std::size_t
	operator()(
		type const &
	) const;
};

}

#endif
