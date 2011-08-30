//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_COLOR_SET_HPP_INCLUDED
#define FCPPT_IO_COLOR_SET_HPP_INCLUDED

#include <fcppt/io/color/foreground.hpp>
#include <fcppt/io/color/background.hpp>
#include <fcppt/io/color/attribute.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/config/external_begin.hpp>
#include <ostream>
#include <fcppt/config/external_end.hpp>

namespace fcppt
{
namespace io
{
namespace color
{
class set
{
public:
	FCPPT_SYMBOL
	explicit
	set(
		fcppt::io::color::foreground::type,
		fcppt::io::color::background::type,
		fcppt::io::color::attribute::type);

	FCPPT_SYMBOL
	fcppt::io::color::foreground::type
	foreground() const;

	FCPPT_SYMBOL
	fcppt::io::color::background::type
	background() const;

	FCPPT_SYMBOL
	fcppt::io::color::attribute::type
	attribute() const;

private:
	fcppt::io::color::foreground::type foreground_;
	fcppt::io::color::background::type background_;
	fcppt::io::color::attribute::type attribute_;
};

FCPPT_SYMBOL
std::ostream &
operator<<(
	std::ostream &,
	fcppt::io::color::set const &);

FCPPT_SYMBOL
std::wostream &
operator<<(
	std::wostream &,
	fcppt::io::color::set const &);

}
}
}

#endif
