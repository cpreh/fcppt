//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INITIAL_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INITIAL_SIZE_HPP_INCLUDED

#include <fcppt/math/is_static_storage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Storage,
	typename Size
>
typename boost::disable_if<
	fcppt::math::is_static_storage<
		Storage
	>,
	void
>::type
initial_size(
	Storage &_storage,
	Size const _size
)
{
	_storage.resize(
		_size
	);
}

template<
	typename Storage,
	typename Size
>
typename boost::enable_if<
	fcppt::math::is_static_storage<
		Storage
	>,
	void
>::type
initial_size(
	Storage &,
	Size
)
{
}

}
}
}

#endif
