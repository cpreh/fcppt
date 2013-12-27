//          Copyright Carl Philipp Reh 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_LOG_DETAIL_AUTO_CONTEXT_REP_HPP_INCLUDED
#define FCPPT_LOG_DETAIL_AUTO_CONTEXT_REP_HPP_INCLUDED

#include <fcppt/reference_wrapper_impl.hpp>
#include <fcppt/log/context_fwd.hpp>
#include <fcppt/log/context_location_fwd.hpp>
#include <fcppt/log/location.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/detail/auto_context_rep_fwd.hpp>
#include <fcppt/log/detail/context_tree_fwd.hpp>


namespace fcppt
{
namespace log
{
namespace detail
{

class auto_context_rep
{
public:
	auto_context_rep(
		fcppt::log::context_location const &,
		fcppt::log::detail::context_tree &
	);

	void
	context(
		fcppt::log::context &
	);

	void
	node(
		fcppt::log::detail::context_tree &
	);

	fcppt::log::context &
	context() const;

	fcppt::log::detail::context_tree &
	node() const;

	fcppt::log::location const &
	location() const;
private:
	typedef
	fcppt::reference_wrapper<
		fcppt::log::context
	>
	context_ref;

	context_ref context_;

	fcppt::log::location location_;

	typedef
	fcppt::reference_wrapper<
		fcppt::log::detail::context_tree
	>
	context_tree_ref;

	context_tree_ref node_;
};

}
}
}

#endif

