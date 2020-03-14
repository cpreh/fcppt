//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_DECL_HPP_INCLUDED
#define FCPPT_RANDOM_GENERATOR_BASIC_PSEUDO_DECL_HPP_INCLUDED

#include <fcppt/make_strong_typedef.hpp>
#include <fcppt/nonmovable.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/random/generator/basic_pseudo_fwd.hpp>


namespace fcppt
{
namespace random
{
namespace generator
{

/**
\brief A wrapper around pseudo random number generators

\ingroup fcpptrandom

Wraps a pseudo random number generator. This class is not copyable, although
pseudo random number generators are. However, copying them is discouraged.
Also, this class uses a strong typedef for the seed and doesn't allow any
default value for it.

\tparam Generator Must be a pseudo random number generator
*/
template<
	typename Generator
>
class basic_pseudo
{
	FCPPT_NONMOVABLE(
		basic_pseudo
	);

	using
	wrapped
	=
	Generator;
public:
	/**
	\brief The result type used for drawing random numbers
	*/
	using
	result_type
	=
	typename
	wrapped::result_type;

	FCPPT_MAKE_STRONG_TYPEDEF(
		result_type,
		seed
	);

	/**
	\brief Constructs the generator using a seed

	Constructs the generator using \a _seed

	\param _seed The seed to use
	*/
	explicit
	basic_pseudo(
		seed _seed
	);

	/**
	\brief Constructs the generator using a seed sequence

	Constructs the generator using \a _seq

	\tparam SeedSeq must be a seed sequence
	*/
	template<
		typename SeedSeq
	>
	explicit
	basic_pseudo(
		SeedSeq &_seq
	);

	/**
	\brief Destroys the generator
	*/
	~basic_pseudo();

	/**
	\brief Draws a random number
	*/
	result_type
	operator()();

	/**
	\brief Returns the minimum element of all the possible random numbers
	*/
	static
	constexpr
	result_type
	min();

	/**
	\brief Returns the maximum element of all the possible random numbers
	*/
	static
	constexpr
	result_type
	max();
private:
	wrapped wrapped_;
};

}
}
}

#endif
