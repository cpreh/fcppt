//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SN_CAST_HPP_INCLUDED
#define FCPPT_SN_CAST_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <boost/type_traits/is_same.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief safe_numeric_cast is a safer static_cast that forbids lossy conversions

This cast converts one fundamental type to another, where the size of the
destination type must be at least the size of the source type.

Furthermore, the conversion is only allowed if one of the following cases hold
true:

<ul>

<li>Both types are the same type</li>

<li>Both types are integer types</li>

<li>Both types are floating point types</li>

</ul>

\tparam Dest The destination type of the conversion

\tparam Source the source type of the conversion

\param _source The source
*/
template<
	typename Dest,
	typename Source
>
typename boost::enable_if<
	boost::mpl::and_<
		boost::mpl::greater_equal<
			boost::mpl::sizeof_<
				Dest
			>,
			boost::mpl::sizeof_<
				Source
			>
		>,
		boost::mpl::or_<
			boost::is_same<
				Dest,
				Source
			>,
			boost::mpl::and_<
				boost::is_floating_point<
					Dest
				>,
				boost::is_floating_point<
					Source
				>
			>,
			boost::mpl::and_<
				boost::is_integral<
					Dest
				>,
				boost::is_integral<
					Source
				>
			>
		>
	>,
	Dest
>::type
sn_cast(
	Source const &_source
)
{
	return _source;
}

}

#endif
