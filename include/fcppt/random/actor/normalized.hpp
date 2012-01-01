//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_ACTOR_NORMALIZED_HPP_INCLUDED
#define FCPPT_RANDOM_ACTOR_NORMALIZED_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/random/uniform.hpp>
#include <fcppt/random/actor/container.hpp>
#include <fcppt/random/actor/float_type.hpp>


namespace fcppt
{
namespace random
{
namespace actor
{

/// The normalized actor
/**
 * It takes a container of elements and distributes
 * evenly depending on how big each element's probability is.
*/
class normalized
{
	FCPPT_NONCOPYABLE(
		normalized
	);
public:
	FCPPT_SYMBOL explicit normalized(
		actor::container const &
	);

	FCPPT_SYMBOL ~normalized();

	/// invoke the random generator
	FCPPT_SYMBOL void
	operator()();
private:
	typedef uniform<
		float_type
	> rng_type;

	actor::container const elements_;

	rng_type rng_;
};

}
}
}

#endif
