//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_LAST_EXCLUSIVE_RANGE_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_LAST_EXCLUSIVE_RANGE_DECL_HPP_INCLUDED

#include <fcppt/random/last_exclusive_range_fwd.hpp>
#include <fcppt/random/range_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/static_assert.hpp>
#include <boost/type_traits/is_integral.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{

/// A range that is exlcudes its last value, thus forming (first, last]
/**
 * \tparam T must be integral
*/
template<
	typename T
>
class last_exclusive_range
:
	public range<
		T
	>
{
public:
	BOOST_STATIC_ASSERT(
		boost::is_integral<
			T
		>::value
	);

	/// Constructs a last_exclusive_range
	/**
	 * @throws exclusive_range_error if first == last
	*/
	explicit last_exclusive_range(
		T const &first,
		T const &last
	);
};

}
}

#endif
