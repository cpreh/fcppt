//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)



#ifndef FCPPT_RANDOM_DISTRIBUTION_BASE_TYPE_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_BASE_TYPE_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/random/distribution/detail/base_type.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Calculates the base type

Calculates the base type of \a Type by converting to
<code>fcppt::random::distribution::transform<Type>::base_type</code>
recursively, until no specialization is found.

\tparam Type Can be any type
*/
template<
	typename Type
>
struct base_type
:
fcppt::random::distribution::detail::base_type<
	Type
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
