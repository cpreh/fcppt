//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_TRANSFORM_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_TRANSFORM_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/iterator/transform_iterator.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Type,
	typename Fun
>
Type const
transform(
	Type const &_arg,
	Fun const &_fun
)
{
	return
		Type(
			boost::make_transform_iterator(
				_arg.begin(),
				_fun
			),
			boost::make_transform_iterator(
				_arg.end(),
				_fun
			)
		);
}

}
}
}

#endif
