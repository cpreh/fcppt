//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_MPL_PRINT_HPP_INCLUDED
#define FCPPT_MPL_PRINT_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/mpl/detail/print.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace mpl
{

template<
	typename Sequence
>
fcppt::io::ostream &
print(
	fcppt::io::ostream &_stream
)
{
	_stream
		<< FCPPT_TEXT('(');

	fcppt::mpl::detail::print<
		Sequence
	>(
		_stream
	);

	_stream
		<< FCPPT_TEXT(')');

	return
		_stream;
}

}
}

#endif
