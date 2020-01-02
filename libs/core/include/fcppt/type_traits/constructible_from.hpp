//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_CONSTRUCTIBLE_FROM_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_CONSTRUCTIBLE_FROM_HPP_INCLUDED

#include <fcppt/type_traits/detail/constructible_from.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Checks if a type can be constructed from certain arguments

\ingroup fcppttypetraits

Checks if \a Type is constructible from \a Args.
*/
template<
	typename Type,
	typename ...Args
>
struct constructible_from
:
fcppt::type_traits::detail::constructible_from<
	Type,
	Args...
>::type
{
};

}
}

#endif
