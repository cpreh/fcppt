//          Copyright Carl Philipp Reh 2009 - 2012.
//          Copyright Philipp Middendorf 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_NUMBER_MULTIPLEXER_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_NUMBER_MULTIPLEXER_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/static_assert_statement.hpp>
#include <fcppt/strong_typedef.hpp>
#include <fcppt/number_multiplexer/object_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/type_traits/is_unsigned.hpp>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace number_multiplexer
{
template<typename T>
class object
{
FCPPT_STATIC_ASSERT_STATEMENT(
	boost::is_unsigned<T>::value);
public:
	typedef
	T
	value_type;

	FCPPT_MAKE_STRONG_TYPEDEF(
		value_type,
		bit_count);

	object();

	explicit
	object(
		value_type);

	object &
	append(
		bit_count const &,
		value_type);

	value_type
	value() const;
private:
	value_type value_;
	value_type last_bit_set_;
};
}
}

#endif
