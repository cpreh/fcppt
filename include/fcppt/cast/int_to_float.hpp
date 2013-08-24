//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_INT_TO_FLOAT_HPP_INCLUDED
#define FCPPT_CAST_INT_TO_FLOAT_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

template<
	typename Dest,
	typename Source
>
inline
typename
boost::enable_if<
	boost::mpl::and_<
		std::is_integral<
			Source
		>,
		std::is_floating_point<
			Dest
		>
	>,
	Dest
>::type
int_to_float(
	Source const _source
)
{
	return
		static_cast<
			Dest
		>(
			_source
		);
}

}
}

#endif
