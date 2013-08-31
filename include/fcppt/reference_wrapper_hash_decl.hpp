//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_REFERENCE_WRAPPER_HASH_DECL_HPP_INCLUDED
#define FCPPT_REFERENCE_WRAPPER_HASH_DECL_HPP_INCLUDED

#include <fcppt/reference_wrapper_fwd.hpp>
#include <fcppt/reference_wrapper_hash_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstddef>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A hash for fcppt::reference_wrapper that hashes pointers

\ingroup fcpptref
*/
template<
	typename Type
>
struct reference_wrapper_hash<
	fcppt::reference_wrapper<
		Type
	>
>
{
	typedef
	fcppt::reference_wrapper<
		Type
	>
	type;

	std::size_t
	operator()(
		type const &
	) const;
};

}

#endif
