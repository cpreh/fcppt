//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_IS_UNIQUE_PTR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_IS_UNIQUE_PTR_HPP_INCLUDED

#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace type_traits
{

/**
\brief Tells if a type is a unique ptr

\ingroup fcppttypetraits

Tells if \a Type is a unique ptr. It is used by the functions in \ref
fcpptcontainerptr

\tparam Type Can be any type
*/
template<
	typename Type
>
struct is_unique_ptr
:
boost::false_type
{
};

template<
	typename Type,
	typename Deleter
>
struct is_unique_ptr<
	fcppt::unique_ptr<
		Type,
		Deleter
	>
>
:
boost::true_type
{
};

}
}

#endif
