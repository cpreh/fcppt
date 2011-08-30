//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_OUTPUT_HPP_INCLUDED
#define FCPPT_MATH_DETAIL_ONE_DIMENSIONAL_OUTPUT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{
namespace detail
{

template<
	typename Ch,
	typename Traits,
	typename T
>
std::basic_ostream<Ch, Traits> &
one_dimensional_output(
	std::basic_ostream<Ch, Traits> &s,
	T const &v
)
{
	s << s.widen('(');
	if(v.size() > 1)
		for(typename T::size_type i = 0; i < v.size() - 1; ++i)
			s << v[i] << s.widen(',');
	if(!v.empty())
		s << v.back();
	return s << s.widen(')');
}

}
}
}

#endif
