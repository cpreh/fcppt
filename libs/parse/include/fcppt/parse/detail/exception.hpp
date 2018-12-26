//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_DETAIL_EXCEPTION_HPP_INCLUDED
#define FCPPT_PARSE_DETAIL_EXCEPTION_HPP_INCLUDED

#include <fcppt/string.hpp>
#include <fcppt/config/external_begin.hpp>
#include <utility>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{
namespace detail
{

class exception
{
public:
	explicit
	exception(
		fcppt::string &&_what
	)
	:
		what_{
			std::move(
				_what
			)
		}
	{
	}

	fcppt::string const &
	what() const
	{
		return
			what_;
	}
private:
	fcppt::string what_;
};

}
}
}

#endif
