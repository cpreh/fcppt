//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_CONTEXT_HPP_INCLUDED
#define FCPPT_LOG_CONTEXT_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/location_fwd.hpp>
#include <fcppt/log/location_setting_fwd.hpp>
#include <fcppt/log/detail/auto_context_fwd.hpp>
#include <fcppt/log/detail/context_tree.hpp>
#include <fcppt/log/detail/symbol.hpp>


namespace fcppt
{
namespace log
{

/**
\brief A logger context manages log settings

\ingroup fcpptlog
*/
class context
{
	FCPPT_NONCOPYABLE(
		context
	);
public:
	/**
	\brief Constructs a context using a container of location settings

	\param root The root setting which will be the default
	*/
	explicit
	FCPPT_LOG_DETAIL_SYMBOL
	context(
		fcppt::log::setting const &root
	);

	FCPPT_LOG_DETAIL_SYMBOL
	~context();

	/**
	\brief Updates a location setting

	Updates the setting at a location, both provided by \a
	location_setting. Note that every location below is also updated.
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	void
	set(
		fcppt::log::location_setting const &location_setting
	);
private:
	fcppt::log::detail::context_tree &
	add(
		fcppt::log::location const &
	);

	void
	remove(
		fcppt::log::detail::context_tree &
	);

	fcppt::log::detail::context_tree &
	find_or_create(
		fcppt::log::location const &
	);

	friend class fcppt::log::detail::auto_context;

	fcppt::log::detail::context_tree tree_;
};

}
}

#endif
