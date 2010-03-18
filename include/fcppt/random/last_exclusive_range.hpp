//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_LAST_EXCLUSIVE_RANGE_HPP_INCLUDED
#define FCPPT_RANDOM_LAST_EXCLUSIVE_RANGE_HPP_INCLUDED

#include <fcppt/random/range.hpp>
#include <fcppt/random/exclusive_range_error.hpp>
#include <fcppt/text.hpp>
#include <boost/utility/enable_if.hpp>
#include <boost/type_traits/is_integral.hpp>

namespace fcppt
{
namespace random
{

template<
	typename T,
	typename Enable = void
>
class last_exclusive_range;

/// A range that is exlcudes its last value, thus forming (first, last]
/**
 * \tparam T must be integral
*/
template<
	typename T
>
class last_exclusive_range<
	T,
	typename boost::enable_if<
		boost::is_integral<
			T
		>
	>::type
>
:
	public range<
		T
	>
{
public:
	/// Constructs a last_exclusive_range
	/**
	 * @throws exclusive_range_error if first == last
	*/
	last_exclusive_range(
		T const &first,
		T const &last
	)
	:
		range<
			T
		>(
			first,
			last - static_cast<T>(1)
		)
	{
		if(first == last)
			throw exclusive_range_error(
				FCPPT_TEXT("last_exclusive_range empty!")
			);
	}
};

}
}

#endif
