//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_OPTIONAL_IS_OBJECT_HPP_INCLUDED
#define FCPPT_OPTIONAL_IS_OBJECT_HPP_INCLUDED

#include <fcppt/optional/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace optional
{

/**
\brief Checks if a given type is an #fcppt::optional::object.

\ingroup fcpptoptional
*/
template<
	typename T
>
struct is_object
:
std::false_type
{
};

template<
	typename Type
>
struct is_object<
	fcppt::optional::object<
		Type
	>
>
:
std::true_type
{
};

}
}

#endif
