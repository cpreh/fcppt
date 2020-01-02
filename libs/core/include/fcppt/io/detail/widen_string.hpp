//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_DETAIL_WIDEN_STRING_HPP_INCLUDED
#define FCPPT_IO_DETAIL_WIDEN_STRING_HPP_INCLUDED

#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <string>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace io
{
namespace detail
{

class widen_string
{
public:
	explicit
	widen_string(
		std::string &&_string
	)
	:
		string_{
			_string
		}
	{
	}

	std::string const &
	get() const
	{
		return
			string_;
	}
private:
	std::string string_;
};

template<
	typename Ch,
	typename Traits
>
std::basic_ostream<
	Ch,
	Traits
> &
operator<<(
	std::basic_ostream<
		Ch,
		Traits
	> &_stream,
	fcppt::io::detail::widen_string const &_string
)
{
	for(
		char const ch
		:
		_string.get()
	)
		_stream
			<<
			_stream.widen(
				ch
			);

	return
		_stream;
}

}
}
}

#endif
