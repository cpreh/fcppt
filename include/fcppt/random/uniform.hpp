//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_UNIFORM_HPP_INCLUDED
#define FCPPT_RANDOM_UNIFORM_HPP_INCLUDED

#include <fcppt/random/detail/uniform_distribution.hpp>
#include <fcppt/random/default_generator.hpp>
#include <fcppt/random/range_fwd.hpp>
#include <fcppt/chrono/high_resolution_clock.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <fcppt/tr1/random.hpp>
#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace random
{

/// A simple uniform distribution
/**
 * \tparam T the basic type that should be randomed
 * \tparam Generator the tr1 generator used
*/
template<
	typename T,
	typename Generator = default_generator
>
class uniform
{
	FCPPT_NONASSIGNABLE(uniform)

	typedef typename detail::uniform_distribution<
		T
	>::type range_type;
public:
	/// Constructs from a range
	explicit uniform(
		range<
			T
		> const &range
	)
	:
		variate(
			Generator(
				static_cast<
					typename Generator::result_type
				>(
					fcppt::chrono::high_resolution_clock::now().time_since_epoch().count()
				)
			),
			range_type(
				range.first(),
				range.last()
			)
		)
	{}

	/// Constructs from a range and a generator
	explicit uniform(
		range<T> const &range,
		Generator const &gen
	)
	:
		variate(
			gen,
			range_type(
				range.first(),
				range.last()
			)
		)
	{}

	/// Draws a random number
	T
	operator()()
	{
		return variate();
	}
private:
	typedef typename std::tr1::variate_generator<
		Generator,
		range_type
	> variate_type;

	variate_type variate;
};

}
}

#endif
