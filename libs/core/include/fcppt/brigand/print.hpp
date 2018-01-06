//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_PRINT_HPP_INCLUDED
#define FCPPT_BRIGAND_PRINT_HPP_INCLUDED

#include <fcppt/text.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/brigand/detail/print.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Pretty prints a brigand sequence.

\ingroup fcpptbrigand

Pretty prints \a Sequence to \a _stream. Every type in \a Sequence will be
converted to a string using fcppt::type_name. The resulting format of the
printed sequence will be <code>(name_1, ..., name_n)</code>.

\tparam Sequence Must be a brigand sequence.

\param _stream The stream to print to.

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

	fcppt::brigand::detail::print<
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
