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
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/setting_fwd.hpp>
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
	\brief Constructs a context

	\param root The root setting which will be the default
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	explicit
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

	/**
	\brief Gets the current setting for a location
	*/
	FCPPT_LOG_DETAIL_SYMBOL
	fcppt::log::setting const &
	get(
		fcppt::log::location const &
	) const;
private:
	fcppt::log::detail::context_tree &
	root();

	fcppt::log::detail::context_tree &
	find_location(
		fcppt::log::location const &
	);

	friend class fcppt::log::object;

	fcppt::log::detail::context_tree tree_;
};

}
}

#endif
