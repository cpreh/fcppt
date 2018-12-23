//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/state.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


fcppt::parse::state::state(
	fcppt::reference<
		std::istream
	> const _stream
)
:
	stream_{
		_stream
	}
{
}

std::istream &
fcppt::parse::state::stream() const
{
	return
		this->stream_.get();
}
