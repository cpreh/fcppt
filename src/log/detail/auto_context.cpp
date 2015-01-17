//          Copyright Carl Philipp Reh 2009 - 2015.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#include <fcppt/optional_impl.hpp>
#include <fcppt/assert/pre.hpp>
#include <fcppt/log/context.hpp>
#include <fcppt/log/object_fwd.hpp>
#include <fcppt/log/optional_location.hpp>
#include <fcppt/log/detail/auto_context.hpp>
#include <fcppt/log/detail/auto_context_rep.hpp>
#include <fcppt/log/detail/optional_context_location.hpp>
#include <fcppt/log/detail/optional_context_tree_ref.hpp>


fcppt::log::detail::auto_context::auto_context(
	fcppt::log::detail::optional_context_location const &_context_location,
	fcppt::log::object &_object
)
:
	rep_(
		_context_location
		?
			optional_auto_context_rep(
				fcppt::log::detail::auto_context_rep(
					*_context_location,
					_context_location->context().add(
						_context_location->location(),
						_object
					)
				)
			)
		:
			optional_auto_context_rep()
	)
{
}

fcppt::log::detail::auto_context::~auto_context()
{
	if(
		rep_
	)
		rep_->context().remove(
			rep_->node()
		);
}

fcppt::log::optional_location
fcppt::log::detail::auto_context::location() const
{
	return
		rep_
		?
			fcppt::log::optional_location(
				rep_->location()
			)
		:
			fcppt::log::optional_location()
		;
}

fcppt::log::detail::optional_context_tree_ref const
fcppt::log::detail::auto_context::node() const
{
	return
		rep_
		?
			fcppt::log::detail::optional_context_tree_ref(
				rep_->node()
			)
		:
			fcppt::log::detail::optional_context_tree_ref()
		;
}

void
fcppt::log::detail::auto_context::transfer(
	fcppt::log::context &_context,
	fcppt::log::object &_object
)
{
	FCPPT_ASSERT_PRE(
		rep_
	);

	rep_->context().remove(
		rep_->node()
	);

	rep_->context(
		_context
	);

	rep_->node(
		_context.add(
			rep_->location(),
			_object
		)
	);
}
