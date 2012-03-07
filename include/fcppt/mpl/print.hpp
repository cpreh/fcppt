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

/**
\brief Pretty prints an MPL sequence

\ingroup fcpptmpl

Pretty prints \a Sequence to \a _stream. Every type in \a Sequence will be
converted to a string using fcppt::type_name. The resulting format of the
printed sequence will be <code>(name_1, ..., name_n)</code>.

\tparam Sequence An MPL sequence

\param _stream The stream to print to

\return \a _stream
*/
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
