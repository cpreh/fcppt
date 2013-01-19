//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_SAFE_NUMERIC_CAST_HPP_INCLUDED
#define FCPPT_SAFE_NUMERIC_CAST_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/and.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/greater_equal.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/is_signed.hpp>
#include <boost/utility/enable_if.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief safe numeric cast is a safer static_cast that forbids lossy conversions

\ingroup fcpptcasts

This cast implicitly converts one arithmetic type to another, where the size of
the destination type must be at least the size of the source type.

Furthermore, the conversion is only allowed if one of the following cases hold
true:

<ul>

<li>Both types are the same type</li>

<li>Both types are integer types and both have the same signedness</li>

<li>Both types are floating point types</li>

</ul>

\tparam Dest The destination type of the conversion

\tparam Source the source type of the conversion

\param _source The source of the conversion

\return The implicitly converted value
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
			std::is_same<
				Dest,
				Source
			>,
			boost::mpl::and_<
				std::is_floating_point<
					Dest
				>,
				std::is_floating_point<
					Source
				>
			>,
			boost::mpl::and_<
				std::is_integral<
					Dest
				>,
				std::is_integral<
					Source
				>,
				boost::mpl::equal_to<
					boost::is_signed<
						Dest
					>,
					boost::is_signed<
						Source
					>
				>
			>
		>
	>,
	Dest
>::type
safe_numeric_cast(
	Source const &_source
)
{
	return _source;
}

}

#endif
