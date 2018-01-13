//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_BRIGAND_SEQUENCE_TO_STRING_HPP_INCLUDED
#define FCPPT_BRIGAND_SEQUENCE_TO_STRING_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/brigand/print.hpp>
#include <fcppt/io/ostringstream.hpp>


namespace fcppt
{
namespace brigand
{

/**
\brief Converts a sequence to a string.

\ingroup fcpptbrigand

\tparam Sequence Must be a brigand sequence.
*/
template<
	typename Sequence
>
fcppt::string
sequence_to_string()
{
	fcppt::io::ostringstream stream;

	fcppt::brigand::print<
		Sequence
	>(
		stream
	);

	return
		stream.str();
}

}
}

#endif
