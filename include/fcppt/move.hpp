// Copyright 2009 Howard Hinnant, Ion Gazta&ntilde;aga.
// Copyright 2010-2012 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0. (See
// accompanying file LICENSE_1_0.txt or copy at
// http://www.boost.org/LICENSE_1_0.txt)
// See http://www.boost.org/libs/foreach for documentation


#ifndef FCPPT_MOVE_HPP_INCLUDED
#define FCPPT_MOVE_HPP_INCLUDED

#include <fcppt/detail/rvalue_ref.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/not.hpp>
#include <boost/type_traits/is_convertible.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

template<
	typename Type
>
inline
typename boost::enable_if
<
	boost::mpl::not_<
		boost::is_convertible<
			Type,
			fcppt::detail::rvalue_ref<
				Type
			>
		>
	>,
	Type &
>::type
move(
	Type &_value
)
{
	return _value;
}

template<
	typename Type
>
inline
typename boost::enable_if
<
	boost::mpl::not_<
		boost::is_convertible<
			Type,
			fcppt::detail::rvalue_ref<
				Type
			>
		>
	>,
	Type const &
>::type
move(
	Type const &_value
)
{
	return _value;
}

template<
	typename Type
>
inline
typename boost::enable_if
<
	boost::is_convertible<
		Type,
		fcppt::detail::rvalue_ref<
			Type
		>
	>,
	Type
>::type
move(
	Type &_value
)
{
	return
		Type(
			fcppt::detail::rvalue_ref<
				Type
			>(
				_value
			)
		);
}

}

#endif
