//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/noncopyable.hpp>
#include <fcppt/algorithm/contains.hpp>
#include <fcppt/cast/enum_to_underlying.hpp>
#include <fcppt/io/color/attribute.hpp>
#include <fcppt/io/color/background.hpp>
#include <fcppt/io/color/foreground.hpp>
#include <fcppt/io/color/set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <ostream>
#include <string>
#include <vector>
#include <fcppt/config/external_end.hpp>


namespace
{

bool
init_color_output()
{
	char const *const term{
		std::getenv("TERM")
	};

	// TERM isn't even set? Could be the case on Windows. We have to fix that later
	if(
		!term
	)
		return
			false;

	std::vector<
		std::string
	> const term_names{
		"Eterm",
		"ansi",
		"color-xterm",
		"con132x25",
		"con132x30",
		"con132x43",
		"con132x60",
		"con80x25",
		"con80x28",
		"con80x30",
		"con80x43",
		"con80x50",
		"con80x60",
		"cons25",
		"console",
		"cygwin",
		"dtterm",
		"eterm-color",
		"gnome",
		"gnome-256color",
		"konsole",
		"konsole-256color",
		"kterm",
		"linux",
		"msys",
		"linux-c",
		"mach-color",
		"mlterm",
		"putty",
		"rxvt",
		"rxvt-256color",
		"rxvt-cygwin",
		"rxvt-cygwin-native",
		"rxvt-unicode",
		"screen",
		"screen-256color",
		"screen-bce",
		"screen-w",
		"screen.linux",
		"vt100",
		"xterm",
		"xterm-16color",
		"xterm-256color",
		"xterm-88color",
		"xterm-color",
		"xterm-debian"
	};

	return
		fcppt::algorithm::contains(
			term_names,
			std::string(
				term
			)
		);
}

class instance
{
	FCPPT_NONCOPYABLE(
		instance
	);
public:
	instance()
	:
		has_color_output_{
			init_color_output()
		}
	{
	}

	bool
	has_color_output() const
	{
		return has_color_output_;
	}
private:
	bool const has_color_output_;
} impl;

}

fcppt::io::color::set::set(
	fcppt::io::color::foreground const _foreground,
	fcppt::io::color::background const _background,
	fcppt::io::color::attribute const _attribute)
:
	foreground_(
		_foreground
	),
	background_(
		_background
	),
	attribute_(
		_attribute
	)
{
}

fcppt::io::color::foreground
fcppt::io::color::set::foreground() const
{
	return
		foreground_;
}

fcppt::io::color::background
fcppt::io::color::set::background() const
{
	return
		background_;
}

fcppt::io::color::attribute
fcppt::io::color::set::attribute() const
{
	return
		attribute_;
}

std::ostream &
fcppt::io::color::operator<<(
	std::ostream &_stream,
	fcppt::io::color::set const &_color
)
{
	return
		impl.has_color_output()
		?
			_stream
			<< "\033["
			<<
			fcppt::cast::enum_to_underlying(
				_color.attribute()
			)
			<< ";"
			<<
			fcppt::cast::enum_to_underlying(
				_color.foreground()
			)
			<< ";"
			<<
			fcppt::cast::enum_to_underlying(
				_color.background()
			)
			<< "m"
		:
			_stream
		;
}

std::wostream &
fcppt::io::color::operator<<(
	std::wostream &_stream,
	fcppt::io::color::set const &_color
)
{
	return
		impl.has_color_output()
		?
			_stream
			<< L"\033["
			<<
			fcppt::cast::enum_to_underlying(
				_color.attribute()
			)
			<< L";"
			<<
			fcppt::cast::enum_to_underlying(
				_color.foreground()
			)
			<< L";"
			<<
			fcppt::cast::enum_to_underlying(
				_color.background()
			)
			<< L"m"
		:
			_stream
		;
}
