//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ASSIGN_DETAIL_ARRAY_IMPL_HPP_INCLUDED
#define FCPPT_ASSIGN_DETAIL_ARRAY_IMPL_HPP_INCLUDED

#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/assign/detail/array.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <fcppt/config/external_end.hpp>


FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

template<
	class T,
	std::size_t N
>
fcppt::assign::detail::array<T,N>::array(
	T const &_value
)
// Don't initialize array_
{
	array_[0] = _value;
}

template<
	class T,
	std::size_t N
>
fcppt::assign::detail::array<T,N>::array(
	array<T,N-1> const &_that,
	T const &_value
)
// Don't initialize array_
{
	std::copy(
		_that.array_.begin(),
		_that.array_.end(),
		array_.begin()
	);

	array_.back() = _value;
}

FCPPT_PP_POP_WARNING

template<
	class T,
	std::size_t N
>
fcppt::assign::detail::array<T,N+1>
fcppt::assign::detail::array<T,N>::operator()(
	T const &_value
)
{
	return
		array<T,N+1>(
			*this,
			_value
		);
}

template<
	class T,
	std::size_t N
>
fcppt::assign::detail::array<T,N>::operator container_type() const
{
	return array_;
}

template<
	class T,
	std::size_t N
>
fcppt::assign::detail::array<T,N>::operator boost_array() const
{
	boost_array ret;

	std::copy(
		array_.begin(),
		array_.end(),
		ret.begin()
	);

	return ret;
}

template<
	class T,
	std::size_t N
>
typename
fcppt::assign::detail::array<T,N>::container_type const &
fcppt::assign::detail::array<T,N>::container() const
{
	return array_;
}

#endif
