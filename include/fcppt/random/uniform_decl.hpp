//          Copyright Carl Philipp Reh 2009 - 2010.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_UNIFORM_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_UNIFORM_DECL_HPP_INCLUDED

#include <fcppt/random/uniform_fwd.hpp>
#include <fcppt/random/detail/uniform_distribution.hpp>
#include <fcppt/random/range_fwd.hpp>
#include <fcppt/tr1/random.hpp>
#include <fcppt/nonassignable.hpp>

namespace fcppt
{
namespace random
{

template<
	typename T,
	typename Generator
>
class uniform
{
	FCPPT_NONASSIGNABLE(uniform)

	typedef typename detail::uniform_distribution<
		T
	>::type distribution;
public:
	typedef range<
		T
	> range_type;

	/// Constructs from a range
	explicit uniform(
		range_type const &
	);

	/// Constructs from a range and a generator
	explicit uniform(
		range_type const &,
		Generator const &
	);

	/// Draws a random number
	T
	operator()();
private:
	typedef typename std::tr1::variate_generator<
		Generator,
		distribution	
	> variate_type;

	variate_type variate;
};

}
}

#endif
