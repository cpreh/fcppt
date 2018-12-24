//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_STATE_IMPL_HPP_INCLUDED
#define FCPPT_PARSE_STATE_IMPL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/state_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


template<
	typename Ch
>
fcppt::parse::state<
	Ch
>::state(
	fcppt::reference<
		stream_type
	> const _stream
)
:
	stream_{
		_stream
	}
{
}

template<
	typename Ch
>
typename
fcppt::parse::state<
	Ch
>::stream_type &
fcppt::parse::state<
	Ch
>::stream() const
{
	return
		this->stream_.get();
}

#endif
