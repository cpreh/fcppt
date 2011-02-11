//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_DETAIL_ASSERT_IMPL_HPP_INCLUDED
#define FCPPT_DETAIL_ASSERT_IMPL_HPP_INCLUDED

#include <fcppt/assertion_failed.hpp>
#include <fcppt/char_type.hpp>

namespace fcppt
{
namespace detail
{

inline
void
assert_impl(
	bool const _test,
	fcppt::char_type const *const _file,
	int _line,
	fcppt::char_type const *const _function,
	fcppt::char_type const *const _condition,
	fcppt::char_type const *const _message
)
{
	if(
		!_test
	)
		throw fcppt::assertion_failed(\
			_file,
			_line,
			_function,
			_condition,
			_message
		);
}

}
}

#endif
