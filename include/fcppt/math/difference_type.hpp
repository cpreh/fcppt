//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MATH_DIFFERENCE_TYPE_HPP_INCLUDED
#define FCPPT_MATH_DIFFERENCE_TYPE_HPP_INCLUDED

#include <fcppt/math/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/make_signed.hpp>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace math
{

/**
\brief The difference type used for structure sizes
\ingroup fcpptmath
*/
typedef boost::make_signed<
	math::size_type
>::type difference_type;

}
}

#endif
