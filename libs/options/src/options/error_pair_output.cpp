//          Copyright Carl Philipp Reh 2009 - 2021.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#include <fcppt/output_to_fcppt_string.hpp>
#include <fcppt/text.hpp>
#include <fcppt/recursive_output.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/options/error_pair.hpp>
#include <fcppt/options/error_pair_output.hpp>
#include <fcppt/options/error_output.hpp>
#include <fcppt/options/detail/indent.hpp>
#include <fcppt/variant/output.hpp>

fcppt::io::ostream &
fcppt::options::operator<<(fcppt::io::ostream &_stream, fcppt::options::error_pair const &_pair)
{
  // TODO(philipp): Format this better
  return _stream << fcppt::options::detail::indent(fcppt::output_to_fcppt_string(_pair.left()))
                 << FCPPT_TEXT("\n|\n")
                 << fcppt::options::detail::indent(fcppt::output_to_fcppt_string(_pair.right()));
}
