//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_INITIAL_SIZE_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_INITIAL_SIZE_HPP_INCLUDED

#include <fcppt/math/detail/is_static_storage.hpp>
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
	typename T,
	typename S
>
typename boost::disable_if<
	detail::is_static_storage<
		T
	>,
	void
>::type
initial_size(
	T &t,
	S const size
)
{
	t.resize(
		size
	);
}

template<
	typename T,
	typename S
>
typename boost::enable_if<
	detail::is_static_storage<
		T
	>,
	void
>::type
initial_size(
	T &,
	S
)
{
}

}
}
}

#endif
