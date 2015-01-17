//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANGE_HASH_DECL_HPP_INCLUDED
#define FCPPT_RANGE_HASH_DECL_HPP_INCLUDED

#include <fcppt/range_hash_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief Hashes a range

\ingroup fcpptvarious

Hashes a range of type \a Type using begin and end
*/
template<
	typename Type
>
struct range_hash
{
	std::size_t
	operator()(
		Type const &_value
	) const;
};

}

#endif
