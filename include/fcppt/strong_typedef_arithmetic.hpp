//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_STRONG_TYPEDEF_ARITHMETIC_HPP_INCLUDED
#define FCPPT_STRONG_TYPEDEF_ARITHMETIC_HPP_INCLUDED

#include <fcppt/strong_typedef_impl.hpp>

namespace fcppt
{

template<
	typename T,
	typename Tag
>
strong_typedef<
	T,
	Tag
>
operator/(
	strong_typedef<
		T,
		Tag
	> const &_a,
	strong_typedef<
		T,
		Tag
	> const &_b
)
{
	return
		fcppt::strong_typedef<
			T,
			Tag
		>(
			_a.get()
			/ _b.get()
		);
}

}

#endif
