//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_NUMERIC_MAX_HPP_INCLUDED
#define FCPPT_MPL_NUMERIC_MAX_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/integral_c.hpp>
#include <limits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

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

FCPPT_PP_POP_WARNING

}
}

#endif
