//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_INDEX_OF_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_INDEX_OF_HPP_INCLUDED

#include <fcppt/mpl/index_of.hpp>
#include <fcppt/mpl/integral_cast.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/variant/size_type.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename Types,
	typename Element
>
struct index_of
:
fcppt::mpl::integral_cast<
	fcppt::variant::size_type,
	fcppt::mpl::index_of<
		Types,
		Element
	>
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
