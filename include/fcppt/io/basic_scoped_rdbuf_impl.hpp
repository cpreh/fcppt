//          Copyright Carl Philipp Reh 2009 - 2015.
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


template<
	typename Ch,
	typename Traits
>
fcppt::io::basic_scoped_rdbuf<
	Ch,
	Traits
>::basic_scoped_rdbuf(
	stream_type &_source,
	stream_type &_receiver
)
:
	receiver_(
		_receiver
	),
	old_(
		_receiver.rdbuf()
	)
{
	receiver_.rdbuf(
		_source.rdbuf()
	);
}

template<
	typename Ch,
	typename Traits
>
fcppt::io::basic_scoped_rdbuf<
	Ch,
	Traits
>::~basic_scoped_rdbuf()
{
	receiver_.rdbuf(
		old_
	);
}

#endif
