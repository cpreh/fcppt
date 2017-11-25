//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_NUMERIC_MAX_HPP_INCLUDED
#define FCPPT_MPL_NUMERIC_MAX_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

/**
\brief Metafunction to compute the maximum value of a type

\ingroup fcpptmpl
*/
template<
	typename Type
>
struct numeric_max
:
boost::mpl::integral_c<
	Type,
	std::numeric_limits<
		Type
	>::max()
>
{
};

}
}

#endif
