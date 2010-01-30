//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CHRONO_DURATION_VALUES_HPP_INCLUDED
#define FCPPT_CHRONO_DURATION_VALUES_HPP_INCLUDED

#include <limits>

namespace fcppt
{
namespace chrono
{

template<
	typename Rep
>
struct duration_values {
	static Rep
	zero()
	{
		return Rep(0);
	}

	static Rep
	min()
	{
		return std::numeric_limits<
			Rep
		>::lowest();
	}

	static Rep
	max()
	{
		return std::numeric_limits<
			Rep
		>::max();
	}
};

}
}

#endif
