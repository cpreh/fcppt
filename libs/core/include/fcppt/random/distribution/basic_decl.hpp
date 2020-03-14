//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_BASIC_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_BASIC_DECL_HPP_INCLUDED

#include <fcppt/random/distribution/basic_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace random
{
namespace distribution
{

/**
\brief A wrapper for distributions

\ingroup fcpptrandom

A wrapped for distributions that draws its properties from \a Parameters. The
capabilities provided by this class are almost the same as the random
distribution requirements by the standard except it lacks a default
constructor.

\tparam Parameters Must be a class from fcppt::random::distribution::parameters
*/
template<
	typename Parameters
>
class basic
{
public:
	/**
	\brief A self typedef required by the standard
	*/
	using
	distribution_type
	=
	basic;

	/**
	\brief The underlying distribution used
	*/
	using
	wrapped_distribution
	=
	typename
	Parameters::distribution;

	/**
	\brief The result type of applying this distribution
	*/
	using
	result_type
	=
	typename
	Parameters::result_type;

	/**
	\brief The parameters type, required by the standard
	*/
	using
	param_type
	=
	Parameters;

	/**
	\brief Constructs the distribution from the parameters type

	Constructs the distribution from \a parameters

	\param parameters The parameters to use
	*/
	explicit
	basic(
		param_type const &parameters
	);

	/**
	\brief Constructs the distribution from multiple parameters

	Constructs the distribution from \a p1 and \a p2, calling
	<code>param_type(p1,p2)</code>

	\note This should really be replaced by a variadic template

	\param p1 The first parameter

	\param p2 The second parameter

	\tparam T1 A type compatible to the first parameter of param_type

	\tparam T2 A type compatible to the second parameter of param_type
	*/
	template<
		typename T1,
		typename T2
	>
	basic(
		T1 const &p1,
		T2 const &p2
	);

	/**
	\brief Resets the underlying distribution
	*/
	void
	reset();

	/**
	\brief Returns the parameters used to construct the distribution
	*/
	[[nodiscard]]
	param_type
	param() const;

	/**
	\brief Supplies new parameters to the distribution

	Supplies the new parameters \a parameters to the distribution.

	\param parameters The new parameters to use
	*/
	void
	param(
		param_type const &parameters
	);

	/**
	\brief Draws a random number

	Draws a random number from the underlying distribution by using \a
	generator

	\tparam Rng Must be a random generator

	\param generator The random generator to use
	*/
	template<
		typename Rng
	>
	[[nodiscard]]
	result_type
	operator()(
		Rng &generator
	);

	/**
	\brief Draws a random number with parameters

	Draws a random number from the underlying distribution by using \a
	generator and \a parameters

	\tparam Rng Must be a random generator

	\param generator The random generator to use

	\param parameters The parameters to use
	*/
	template<
		typename Rng
	>
	[[nodiscard]]
	result_type
	operator()(
		Rng &generator,
		param_type const &parameters
	);

	/**
	\brief The minimum value that can be produced
	*/
	[[nodiscard]]
	result_type
	min() const;

	/**
	\brief The maximum value that can be produced
	*/
	[[nodiscard]]
	result_type
	max() const;

	/**
	\brief The underlying distribution
	*/
	[[nodiscard]]
	wrapped_distribution const &
	distribution() const;
private:
	template<
		typename Ch,
		typename Traits
	>
	friend
	std::basic_istream<
		Ch,
		Traits
	>
	operator >>(
		std::basic_istream<
			Ch,
			Traits
		>,
		basic &
	);

	static
	result_type
	make_result(
		typename wrapped_distribution::result_type
	);

	wrapped_distribution distribution_;
};

/**
\brief Compares two distribution for equality

Compares distributions \a left and \a right for equality, calling the
equality operator of the underlying distributions.

\param left The first distribution

\param right The second distribution
*/
template<
	typename Parameters
>
bool
operator==(
	fcppt::random::distribution::basic<
		Parameters
	> const &left,
	fcppt::random::distribution::basic<
		Parameters
	> const &right
);

/**
\brief Compares two distribution for inequality

Compares distributions \a left and \a right for inequality, calling the
inequality operator of the underlying distributions.

\param left The first distribution

\param right The second distribution
*/
template<
	typename Parameters
>
bool
operator!=(
	fcppt::random::distribution::basic<
		Parameters
	> const &left,
	fcppt::random::distribution::basic<
		Parameters
	> const &right
);

/**
\brief Outputs a distribution

Outputs the underlying distribution of \a dist to \a stream.

\param stream The stream to output to

\param dist The distribution to output
*/
template<
	typename Ch,
	typename Traits,
	typename Parameters
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &stream,
	fcppt::random::distribution::basic<
		Parameters
	> const &dist
);

/**
\brief Inputs into a distribution

Inputs into the underlying distribution of \a dist from \a stream.

\param stream The stream to input from

\param dist The distribution to input to
*/
template<
	typename Ch,
	typename Traits,
	typename Parameters
>
std::basic_istream<
	Ch,
	Traits
> &
operator>>(
	std::basic_istream<
		Ch,
		Traits
	> &stream,
	fcppt::random::distribution::basic<
		Parameters
	> &dist
);

}
}
}

#endif
