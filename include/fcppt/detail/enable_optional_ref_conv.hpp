//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_ENABLE_OPTIONAL_REF_CONV_HPP_INCLUDED
#define FCPPT_DETAIL_ENABLE_OPTIONAL_REF_CONV_HPP_INCLUDED

#include <boost/mpl/and.hpp>
#include <boost/mpl/not.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_const.hpp>


namespace fcppt
{
namespace detail
{

template<
	typename Own,
	typename Other
>
struct enable_optional_ref_conv
:
boost::enable_if<
	boost::mpl::and_<
		boost::is_const<
			Own
		>,
		boost::mpl::not_<
			boost::is_const<
				Other
			>
		>
	>
>
{
};

}
}

#endif
