//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_VALUE_TYPE_TPL_HPP_INCLUDED
#define FCPPT_OPTIONAL_VALUE_TYPE_TPL_HPP_INCLUDED

#include <fcppt/optional/is_object.hpp>
#include <fcppt/optional/value_type_tpl.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Metafunction for the value type of an optional.

\ingroup fcpptoptional

\tparam Optional Must be an \link fcppt::optional::object\endlink.
*/
template<
	typename Optional
>
struct value_type_tpl
{
	static_assert(
		fcppt::optional::is_object<
			Optional
		>::value,
		"Optional must be an optional"
	);

	typedef
	typename
	Optional::value_type
	type;
};

}
}

#endif
