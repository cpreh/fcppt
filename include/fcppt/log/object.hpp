//          Copyright Carl Philipp Reh 2009 - 2012.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_OBJECT_HPP_INCLUDED
#define FCPPT_LOG_OBJECT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/symbol.hpp>
#include <fcppt/io/ostream.hpp>
#include <fcppt/log/enabled_level_array.hpp>
#include <fcppt/log/level.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/level_stream_fwd.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/detail/temporary_output_fwd.hpp>
#include <fcppt/log/format/const_object_ptr.hpp>
#include <fcppt/log/parameters/object_fwd.hpp>


namespace fcppt
{
namespace log
{

/// The main logger class. If you need a new logger, you should create an object of it.
class object
{
	FCPPT_NONCOPYABLE(
		object
	);
public:
	FCPPT_SYMBOL
	explicit
	object(
		fcppt::log::parameters::object const &
	);

	FCPPT_SYMBOL
	~object();

	FCPPT_SYMBOL
	void
	log(
		fcppt::log::level::type,
		fcppt::log::detail::temporary_output const &
	);

	FCPPT_SYMBOL
	fcppt::log::level_stream &
	level_sink(
		fcppt::log::level::type
	);

	FCPPT_SYMBOL
	fcppt::log::level_stream const &
	level_sink(
		fcppt::log::level::type
	) const;

	FCPPT_SYMBOL
	void
	activate(
		fcppt::log::level::type
	);

	FCPPT_SYMBOL
	void
	deactivate(
		fcppt::log::level::type
	);

	FCPPT_SYMBOL
	bool
	activated(
		fcppt::log::level::type
	) const;

	FCPPT_SYMBOL
	void
	enable(
		bool
	);

	FCPPT_SYMBOL
	bool
	enabled() const;

	FCPPT_SYMBOL
	fcppt::io::ostream &
	sink() const;

	FCPPT_SYMBOL
	fcppt::log::format::const_object_ptr const
	formatter() const;

	FCPPT_SYMBOL
	fcppt::log::level_stream_array const &
	level_streams() const;

	FCPPT_SYMBOL
	fcppt::log::enabled_level_array const &
	enabled_levels() const;
private:
	fcppt::io::ostream &sink_;

	fcppt::log::detail::auto_context auto_context_;

	fcppt::log::format::const_object_ptr const formatter_;

	fcppt::log::level_stream_array level_streams_;

	fcppt::log::enabled_level_array enabled_levels_;

	bool enabled_;
};

}
}

#endif
