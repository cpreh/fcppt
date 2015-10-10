//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RANDOM_DISTRIBUTION_BASIC_IMPL_HPP_INCLUDED
#define FCPPT_RANDOM_DISTRIBUTION_BASIC_IMPL_HPP_INCLUDED

#include <fcppt/random/distribution/basic_decl.hpp>
#include <fcppt/random/distribution/decorated_value.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


template<
	typename Parameters
>
fcppt::random::distribution::basic<
	Parameters
>::basic(
	param_type const &_parameters
)
:
	distribution_(
		_parameters.convert_from()
	)
{
}

template<
	typename Parameters
>
template<
	typename T1,
	typename T2
>
fcppt::random::distribution::basic<
	Parameters
>::basic(
	T1 const &_t1,
	T2 const &_t2
)
:
	distribution_(
		param_type(
			_t1,
			_t2
		).convert_from()
	)
{
}

template<
	typename Parameters
>
void
fcppt::random::distribution::basic<
	Parameters
>::reset()
{
	distribution_.reset();
}

template<
	typename Parameters
>
typename
fcppt::random::distribution::basic<
	Parameters
>::param_type
fcppt::random::distribution::basic<
	Parameters
>::param() const
{
	return
		Parameters::convert_to(
			distribution_.param()
		);
}

template<
	typename Parameters
>
void
fcppt::random::distribution::basic<
	Parameters
>::param(
	param_type const &_parameters
)
{
	distribution_.param(
		_parameters.convert_from()
	);
}

template<
	typename Parameters
>
template<
	typename Rng
>
typename
fcppt::random::distribution::basic<
	Parameters
>::result_type
fcppt::random::distribution::basic<
	Parameters
>::operator()(
	Rng &_rng
)
{
	return
		this->make_result(
			distribution_(
				_rng
			)
		);
}

template<
	typename Parameters
>
template<
	typename Rng
>
typename
fcppt::random::distribution::basic<
	Parameters
>::result_type
fcppt::random::distribution::basic<
	Parameters
>::operator()(
	Rng &_rng,
	param_type const &_parameters
)
{
	return
		this->make_result(
			distribution_(
				_rng
			),
			_parameters.convert_from()
		);
}

template<
	typename Parameters
>
typename
fcppt::random::distribution::basic<
	Parameters
>::result_type
fcppt::random::distribution::basic<
	Parameters
>::min() const
{
	return
		this->make_result(
			distribution_.min()
		);
}

template<
	typename Parameters
>
typename
fcppt::random::distribution::basic<
	Parameters
>::result_type
fcppt::random::distribution::basic<
	Parameters
>::max() const
{
	return
		this->make_result(
			distribution_.max()
		);
}

template<
	typename Parameters
>
typename
fcppt::random::distribution::basic<
	Parameters
>::wrapped_distribution const &
fcppt::random::distribution::basic<
	Parameters
>::distribution() const
{
	return
		distribution_;
}

template<
	typename Parameters
>
typename
fcppt::random::distribution::basic<
	Parameters
>::result_type
fcppt::random::distribution::basic<
	Parameters
>::make_result(
	typename wrapped_distribution::result_type const _value
)
{
	return
		fcppt::random::distribution::decorated_value<
			result_type
		>(
			_value
		);
}

template<
	typename Parameters
>
bool
fcppt::random::distribution::operator==(
	fcppt::random::distribution::basic<
		Parameters
	> const &_left,
	fcppt::random::distribution::basic<
		Parameters
	> const &_right
)
{
	return
		_left.distribution()
		==
		_right.distribution();
}

template<
	typename Parameters
>
bool
fcppt::random::distribution::operator!=(
	fcppt::random::distribution::basic<
		Parameters
	> const &_left,
	fcppt::random::distribution::basic<
		Parameters
	> const &_right
)
{
	return
		_left.distribution()
		!=
		_right.distribution();
}

template<
	typename Ch,
	typename Traits,
	typename Parameters
>
std::basic_ostream<
	Ch,
	Traits
> &
fcppt::random::distribution::operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::random::distribution::basic<
		Parameters
	> const &_dist
)
{
	return
		_stream
		<<
		_dist.distribution();
}

template<
	typename Ch,
	typename Traits,
	typename Parameters
>
std::basic_istream<
	Ch,
	Traits
> &
fcppt::random::distribution::operator>>(
	std::basic_istream<
		Ch,
		Traits
	> &_stream,
	fcppt::random::distribution::basic<
		Parameters
	> &_dist
)
{
	return
		_stream
		>>
		_dist.distribution_;
}

#endif
