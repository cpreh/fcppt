//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_VARIATE_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_VARIATE_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/random/variate_fwd.hpp>


namespace fcppt
{
namespace random
{

/**
\brief Combines a generator and a distribution

\ingroup fcpptrandom

Combines a generator and a distribution, using the generator to draw elements
from the distribution.

\tparam Generator Must be a random number generator

\tparam Distribution Must be a random number distribution
*/
template<
	typename Generator,
	typename Distribution
>
class variate
{
	FCPPT_NONCOPYABLE(
		variate
	);
public:
	/**
	\brief The generator type
	*/
	typedef Generator generator;

	/**
	\brief The distribution type
	*/
	typedef Distribution distribution;

	/**
	\brief The result returned by drawing random numbers
	*/
	typedef typename distribution::result_type result_type;

	/**
	\brief Constructs a variate object

	Constructs a variate object from \a generator and \a distribution.

	\param generator The generator to use

	\param distribution The distribution to use
	*/
	variate(
		Generator &generator,
		Distribution const &distribution
	);

	/**
	\brief Destroys the variate object
	*/
	~variate();

	/**
	\brief Draws a random number

	Draws a random number from the distribution passing it the generator to
	use.
	*/
	result_type
	operator()();
private:
	generator &generator_;

	distribution distribution_;
};

}
}

#endif
