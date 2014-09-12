//          Copyright Carl Philipp Reh 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CAST_SIZE_HPP_INCLUDED
#define FCPPT_CAST_SIZE_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/equal_to.hpp>
#include <boost/mpl/or.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/is_floating_point.hpp>
#include <boost/type_traits/is_signed.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <boost/utility/enable_if.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace cast
{

/**
\brief Converts a type to a similar type of different size

\ingroup fcpptcasts

Converts \a _source to the type specified by \a Dest. Exactly one of
the following cases must hold:

<ul>

<li>Both types are signed integer types.</li>

<li>Both types are unsigned integer types.</li>

<li>Both types are floating point types.</li>

</ul>
*/
template<
	typename Dest,
	typename Source
>
inline
constexpr
typename
boost::enable_if<
	boost::mpl::or_<
		boost::mpl::equal_to<
			boost::is_floating_point<
				Dest
			>,
			boost::is_floating_point<
				Source
			>
		>,
		boost::mpl::equal_to<
			boost::is_signed<
				Dest
			>,
			boost::is_signed<
				Source
			>
		>,
		boost::mpl::equal_to<
			boost::is_unsigned<
				Dest
			>,
			boost::is_unsigned<
				Source
			>
		>
	>,
	Dest
>::type
size(
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
