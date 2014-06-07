//          Copyright Carl Philipp Reh 2009 - 2014.
//          Copyright Philipp Middendorf 2009 - 2014.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NUMBER_MULTIPLEXER_OBJECT_IMPL_HPP_INCLUDED
#define FCPPT_NUMBER_MULTIPLEXER_OBJECT_IMPL_HPP_INCLUDED

#include <fcppt/literal.hpp>
#include <fcppt/number_multiplexer/object_decl.hpp>
#include <fcppt/number_multiplexer/set_bits.hpp>


template<typename T>
fcppt::number_multiplexer::object<T>::object()
:
	value_(
		fcppt::literal<value_type>(
			0)),
	last_bit_set_(
		fcppt::literal<value_type>(
			0))
{
}

template<typename T>
fcppt::number_multiplexer::object<T>::object(
	value_type const _value)
:
	value_(
		_value),
	last_bit_set_(
		fcppt::literal<value_type>(
			0))
{
}

template<typename T>
fcppt::number_multiplexer::object<T> &
fcppt::number_multiplexer::object<T>::append(
	bit_count const &_bit_count,
	value_type const _value)
{
	value_ =
		fcppt::number_multiplexer::set_bits(
			last_bit_set_,
			_bit_count.get(),
			_value,
			value_);

	last_bit_set_ +=
		_bit_count.get();

	return
		*this;
}

template<typename T>
typename
fcppt::number_multiplexer::object<T>::value_type
fcppt::number_multiplexer::object<T>::value() const
{
	return
		value_;
}

#endif
