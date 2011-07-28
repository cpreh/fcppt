//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_UNIFORM_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_UNIFORM_IMPL_HPP_INCLUDED

#include <fcppt/random/uniform_decl.hpp>
#include <fcppt/random/range_impl.hpp>
#include <fcppt/chrono/high_resolution_clock.hpp>
#include <fcppt/chrono/time_point_impl.hpp>
#include <fcppt/chrono/duration_impl.hpp>
#include <boost/type_traits/remove_reference.hpp>

template<
	typename T,
	typename Generator
>
fcppt::random::uniform<T, Generator>::uniform(
	range_type const &_range
)
:
	variate_(
		typename boost::remove_reference<Generator>::type(
			static_cast<
				typename boost::remove_reference<Generator>::type::result_type	
			>(
				fcppt::chrono::high_resolution_clock::now().time_since_epoch().count()
			)
		),
		distribution(
			_range.first(),
			_range.last()
		)
	)
{}

template<
	typename T,
	typename Generator
>
fcppt::random::uniform<T, Generator>::uniform(
	range_type const &_range,
	Generator _gen
)
:
	variate_(
		_gen,
		distribution(
			_range.first(),
			_range.last()
		)
	)
{}

template<
	typename T,
	typename Generator
>
T
fcppt::random::uniform<T, Generator>::operator()()
{
	return variate_();
}

#endif
