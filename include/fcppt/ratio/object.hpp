//  Copyright 2008 Howard Hinnant
//  Copyright 2008 Beman Dawes
//  Copyright 2009-2010 Carl Philipp Reh
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RATIO_OBJECT_HPP_INCLUDED
#define FCPPT_RATIO_OBJECT_HPP_INCLUDED

#include <fcppt/ratio/detail/static_abs.hpp>
#include <fcppt/ratio/detail/static_sign.hpp>
#include <fcppt/ratio/detail/static_gcd.hpp>
#include <fcppt/ratio/object_fwd.hpp>
#include <fcppt/ratio/int_type.hpp>
#include <boost/static_assert.hpp>

namespace fcppt
{
namespace ratio
{

template<
	int_type N,
	int_type D
>
class object
{
	BOOST_STATIC_ASSERT(
		detail::static_abs<N>::value >= 0
	);

	BOOST_STATIC_ASSERT(
		detail::static_abs<D>::value
	);

	BOOST_STATIC_ASSERT(
		detail::static_abs<D>::value > 0
	);

	static int_type const
		na_ = detail::static_abs<N>::value,
		da_ = detail::static_abs<D>::value,
		s_ = detail::static_sign<N>::value * detail::static_sign<D>::value,
		gcd_ = detail::static_gcd<na_, da_>::value;
public:
	static int_type const
		num = s_ * na_ / gcd_,
		den = da_ / gcd_;
};

}
}

#endif
