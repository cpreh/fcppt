//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_PARAMETERS_HPP_INCLUDED
#define FCPPT_LOG_PARAMETERS_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/level_stream_array.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/parameters_fwd.hpp>
#include <fcppt/log/detail/symbol.hpp>
#include <fcppt/log/format/optional_function.hpp>


namespace fcppt
{
namespace log
{

/**
\brief The parameters class for an \link fcppt::log::object \endlink

\ingroup fcpptlog
*/
class parameters
{
public:
	FCPPT_LOG_DETAIL_SYMBOL
	parameters(
		fcppt::log::context &,
		fcppt::log::location,
		fcppt::log::level_stream_array const &,
		fcppt::log::format::optional_function const &
	);

	fcppt::log::context &
	context() const;

	fcppt::log::location const &
	location() const;

	fcppt::log::level_stream_array const &
	level_streams() const;

	fcppt::log::format::optional_function const &
	formatter() const;
private:
	fcppt::reference<
		fcppt::log::context
	> context_;

	fcppt::log::location location_;

	fcppt::log::level_stream_array level_streams_;

	fcppt::log::format::optional_function formatter_;
};

}
}

#endif
