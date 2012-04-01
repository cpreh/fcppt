//  Copyright Thomas Heller 2009 - 2010.
//  Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_FUNCTION_DETAIL_HAS_ADDRESSOF_OVERLOAD_HPP_INCLUDED
#define FCPPT_FUNCTION_DETAIL_HAS_ADDRESSOF_OVERLOAD_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/bool.hpp>
#include <boost/type_traits/integral_constant.hpp>
#include <boost/type_traits/is_class.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace function
{
namespace detail
{
namespace has_addressof_overload_detail
{

typedef char one;
typedef struct { char a[2]; } two;

template< typename T >
static one test( T* );

template< typename T >
static two test( ... );

template< typename T >
struct temp
{
	static T value;
};

}

template< typename Function, typename Enable = void >
struct has_addressof_overload;

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template< typename Function >
struct has_addressof_overload
<
	Function,
	typename boost::enable_if<
		boost::is_class<
			Function
		>
	>::type
>
:
boost::mpl::bool_<
	sizeof(
		::fcppt::function::detail::has_addressof_overload_detail::test<
			Function
		>(
			&has_addressof_overload_detail::temp<Function>::value
		)
	)
	== sizeof( has_addressof_overload_detail::two )
>
{
};

template<
	typename Function
>
struct has_addressof_overload
<
	Function,
	typename boost::disable_if<
		boost::is_class<
			Function
		>
	>::type
>
:
boost::false_type
{};

FCPPT_PP_POP_WARNING

} // end namespace detail

} // end namespace function

} // end namespace fcppt

#endif
