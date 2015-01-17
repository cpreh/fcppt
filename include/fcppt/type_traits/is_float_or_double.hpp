//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_FLOAT_OR_DOUBLE_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_FLOAT_OR_DOUBLE_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/or.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Checks if a type is float or double

\ingroup fcppttypetraits

Checks if \a Type is float or double.

\tparam Type Can be any type
*/
template<
	typename Type
>
struct is_float_or_double
:
boost::mpl::or_<
	std::is_same<
		Type,
		float
	>,
	std::is_same<
		Type,
		double
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}

#endif
