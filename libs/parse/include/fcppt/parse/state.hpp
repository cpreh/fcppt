//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_STATE_HPP_INCLUDED
#define FCPPT_PARSE_STATE_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/detail/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <iosfwd>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

class state
{
public:
	FCPPT_PARSE_DETAIL_SYMBOL
	explicit
	state(
		fcppt::reference<
			std::istream
		>
	);

	FCPPT_PARSE_DETAIL_SYMBOL
	std::istream &
	stream() const;
private:
	fcppt::reference<
		std::istream
	> stream_;
};

}
}

#endif
