//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_MATRIX_STATIC_STORAGE_HPP_INCLUDED
#define FCPPT_MATH_MATRIX_STATIC_STORAGE_HPP_INCLUDED

#include <fcppt/math/static_storage.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/times.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace math
{
namespace matrix
{

template<
	typename T,
	typename N,
	typename M
>
using static_storage
=
fcppt::math::static_storage<
	T,
	boost::mpl::times<
		N,
		M
	>
>;

}
}
}

#endif
