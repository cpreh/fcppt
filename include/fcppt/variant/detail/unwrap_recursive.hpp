//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_DETAIL_UNWRAP_RECURSIVE_HPP_INCLUDED
#define FCPPT_VARIANT_DETAIL_UNWRAP_RECURSIVE_HPP_INCLUDED

#include <fcppt/variant/recursive_fwd.hpp>

namespace fcppt
{
namespace variant
{
namespace detail
{

template<
	typename Type
>
Type &
unwrap_recursive(
	Type &_value
)
{
	return _value;
}

template<
	typename Type
>
Type &
unwrap_recursive(
	variant::recursive<
		Type
	> &_value
)
{
	return
		_value.get();
}

template<
	typename Type
>
Type &
unwrap_recursive(
	variant::recursive<
		Type
	> const &_value
)
{
	return
		_value.get();
}

}
}
}

#endif
