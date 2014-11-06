//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_DISABLE_OBJECT_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_DISABLE_OBJECT_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/type_traits/remove_cv_ref.hpp>
#include <fcppt/variant/is_object.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename U,
	typename T = void
>
struct disable_object final
:
std::enable_if<
	!(
		std::is_const<
			typename std::remove_reference<
				U
			>::type
		>::value
		||
		fcppt::variant::is_object<
			typename fcppt::type_traits::remove_cv_ref<
				U
			>::type
		>::value
	),
	T
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
