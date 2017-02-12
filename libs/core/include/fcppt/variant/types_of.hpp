//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_TYPES_OF_HPP_INCLUDED
#define FCPPT_VARIANT_TYPES_OF_HPP_INCLUDED

#include <fcppt/variant/types_of_tpl.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief The types of a variant

\ingroup fcpptvariant
*/
template<
	typename Variant
>
using
types_of
=
typename
fcppt::variant::types_of_tpl<
	Variant
>::type;

}
}

#endif
