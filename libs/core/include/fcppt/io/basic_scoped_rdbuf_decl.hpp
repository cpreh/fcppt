//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_BASIC_SCOPED_RDBUF_DECL_HPP_INCLUDED
#define FCPPT_IO_BASIC_SCOPED_RDBUF_DECL_HPP_INCLUDED

#include <fcppt/nonmovable.hpp>
#include <fcppt/reference_impl.hpp>
#include <fcppt/io/basic_scoped_rdbuf_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace io
{
/**
\brief Changes the streambuf of a stream temporarily.

\ingroup fcpptio
*/
template <typename Ch, typename Traits>
class basic_scoped_rdbuf
{
  FCPPT_NONMOVABLE(basic_scoped_rdbuf);

public:
  using stream_type = std::basic_ios<Ch, Traits>;

  using streambuf_type = std::basic_streambuf<Ch, Traits>;

  basic_scoped_rdbuf(fcppt::reference<stream_type>, fcppt::reference<streambuf_type>);

  ~basic_scoped_rdbuf();

private:
  fcppt::reference<stream_type> const stream_;

  streambuf_type *const old_;
};

}
}

#endif
