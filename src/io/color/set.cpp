//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/null_ptr.hpp>
#include <fcppt/io/color/set.hpp>
#include <fcppt/config/external_begin.hpp>
#include <cstdlib>
#include <cstring>
#include <ostream>
#include <fcppt/config/external_end.hpp>


namespace
{
struct instance
{
	instance()
	:
		has_color_output_(
			false)
	{
		char const * const term =
			std::getenv("TERM");

		// TERM isn't even set? Could be the case on Windows. We have to fix that later
		if (!term)
		{
			has_color_output_ = false;
			return;
		}

		char const *term_names[] =
		{
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
			"xterm-debian",
			fcppt::null_ptr()
		};

		for(char const **ptr = term_names; *ptr; ++ptr)
		{
			if(std::strcmp(*ptr,term) == 0)
			{
				has_color_output_ = true;
				return;
			}
		}
	}

	bool
	has_color_output() const
	{
		return has_color_output_;
	}

	bool has_color_output_;
} impl;
}

fcppt::io::color::set::set(
	fcppt::io::color::foreground::type const _foreground,
	fcppt::io::color::background::type const _background,
	fcppt::io::color::attribute::type const _attribute)
:
	foreground_(
		_foreground),
	background_(
		_background),
	attribute_(
		_attribute)
{
}

fcppt::io::color::foreground::type
fcppt::io::color::set::foreground() const
{
	return foreground_;
}

fcppt::io::color::background::type
fcppt::io::color::set::background() const
{
	return background_;
}

fcppt::io::color::attribute::type
fcppt::io::color::set::attribute() const
{
	return attribute_;
}

typedef
int
enum_impl;

std::ostream &
fcppt::io::color::operator<<(
	std::ostream &s,
	fcppt::io::color::set const &c)
{
	if(!impl.has_color_output())
		return s;
	return s
		<< "\033["
		<< static_cast<enum_impl>(c.attribute()) << ";"
		<< static_cast<enum_impl>(c.foreground()) << ";"
		<< static_cast<enum_impl>(c.background()) << "m";
}

std::wostream &
fcppt::io::color::operator<<(
	std::wostream &s,
	fcppt::io::color::set const &c)
{
	if(!impl.has_color_output())
		return s;
	return s
		<< L"\033["
		<< static_cast<enum_impl>(c.attribute()) << L";"
		<< static_cast<enum_impl>(c.foreground()) << L";"
		<< static_cast<enum_impl>(c.background()) << L"m";
}
