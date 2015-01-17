//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_TYPE_TRAITS_DETAIL_HAS_CONST_ITERATOR_HPP_INCLUDED
#define FCPPT_TYPE_TRAITS_DETAIL_HAS_CONST_ITERATOR_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/generate_has_type.hpp>

namespace fcppt
{
namespace type_traits
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

FCPPT_TYPE_TRAITS_GENERATE_HAS_TYPE(
	const_iterator
);

FCPPT_PP_POP_WARNING

}
}
}

#endif
