//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)

#ifndef FCPPT_IO_BASIC_SCOPED_RDBUF_IMPL_HPP_INCLUDED
#define FCPPT_IO_BASIC_SCOPED_RDBUF_IMPL_HPP_INCLUDED

#include <fcppt/io/basic_scoped_rdbuf_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ios>
#include <streambuf>
#include <fcppt/config/external_end.hpp>

template <typename Ch, typename Traits>
fcppt::io::basic_scoped_rdbuf<Ch, Traits>::basic_scoped_rdbuf(
    fcppt::reference<stream_type> const _stream, fcppt::reference<streambuf_type> const _buffer)
    : stream_{_stream}, old_{_stream.get().rdbuf(&_buffer.get())}
{
}

template <typename Ch, typename Traits>
fcppt::io::basic_scoped_rdbuf<Ch, Traits>::~basic_scoped_rdbuf<Ch, Traits>()
{
  this->stream_.get().rdbuf(this->old_);
}

#endif
