//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_TYPES_STRING_HPP_INCLUDED
#define FCPPT_VARIANT_TYPES_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/mpl/sequence_to_string.hpp>
#include <fcppt/variant/types_of.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief Returns the types of a variant as a string

\ingroup fcpptvariant

\tparam Variant Must be an \link fcppt::variant::object\endlink.
*/
template<
	typename Variant
>
inline
fcppt::string
types_string()
{
	return
		fcppt::mpl::sequence_to_string<
			fcppt::variant::types_of<
				Variant
			>
		>();
}

}
}

#endif