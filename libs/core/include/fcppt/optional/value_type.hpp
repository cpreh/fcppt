//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_VALUE_TYPE_HPP_INCLUDED
#define FCPPT_OPTIONAL_VALUE_TYPE_HPP_INCLUDED

#include <fcppt/optional/value_type_tpl.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief The value type of an optional.

\ingroup fcpptoptional

\tparam Optional Must be an \link fcppt::optional::object\endlink.
*/
template<
	typename Optional
>
using
value_type
=
typename
fcppt::optional::value_type_tpl<
	Optional
>::type;

}
}

#endif
