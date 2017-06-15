//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_STORAGE_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_STORAGE_SIZE_HPP_INCLUDED

#include <fcppt/container/array_size.hpp>
#include <fcppt/math/detail/is_static_storage.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	typename T,
	typename Enable = void
>
struct storage_size;

template<
	typename T
>
struct storage_size<
	T,
	typename
	boost::disable_if<
		fcppt::math::detail::is_static_storage<
			T
		>
	>::type
>
:
T::static_size
{
};

template<
	typename T
>
struct storage_size<
	T,
	typename
	boost::enable_if<
		fcppt::math::detail::is_static_storage<
			T
		>
	>::type
>
:
fcppt::container::array_size<
	typename
	T::array_type
>
{
};

FCPPT_PP_POP_WARNING

}
}
}

#endif
